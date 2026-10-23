cmake_minimum_required(VERSION 3.20)

project(sensor_monitor C ASM)

# FreeRTOS-Kernel
set(FREERTOS_KERNEL
    "${CMAKE_CURRENT_SOURCE_DIR}/FreeRTOS-Kernel"
)

# Linker-Skript
set(LINKER_SCRIPT
    "${CMAKE_CURRENT_SOURCE_DIR}/firmware/linker/linker.ld"
)

# Firmware und FreeRTOS-Kernel
add_executable(firmware.elf
    firmware/src/main.c
    firmware/src/sensor_task.c
    firmware/src/task_log.c

    firmware/startup/startup.c
    firmware/startup/vectors.c

    ${FREERTOS_KERNEL}/tasks.c
    ${FREERTOS_KERNEL}/queue.c
    ${FREERTOS_KERNEL}/list.c
    ${FREERTOS_KERNEL}/portable/GCC/ARM_CM3/port.c
    ${FREERTOS_KERNEL}/portable/MemMang/heap_4.c
)

# Header-Dateien
target_include_directories(firmware.elf PRIVATE
    ${FREERTOS_KERNEL}/include
    ${FREERTOS_KERNEL}/portable/GCC/ARM_CM3
    ${CMAKE_CURRENT_SOURCE_DIR}/config
    ${CMAKE_CURRENT_SOURCE_DIR}/firmware/include
)

# Compiler-Optionen für Cortex-M3
target_compile_options(firmware.elf PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -ffreestanding
)

# Linker-Optionen
target_link_options(firmware.elf PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -nostartfiles
    -T${LINKER_SCRIPT}
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/firmware.map
)

# Ausgabedatei heißt firmware.elf
set_target_properties(firmware.elf PROPERTIES
    SUFFIX ""
)

# Bei Änderungen am Linker-Skript neu konfigurieren
set_property(DIRECTORY APPEND PROPERTY
    CMAKE_CONFIGURE_DEPENDS "${LINKER_SCRIPT}"
)

# Firmware in QEMU starten
add_custom_target(run
    COMMAND qemu-system-arm
        -M mps2-an385
        -kernel $<TARGET_FILE:firmware.elf>
        -nographic
    DEPENDS firmware.elf
    USES_TERMINAL
)
