
cmake_minimum_required(VERSION 3.20)

project(sensor_monitor C ASM)

add_executable(firmware.elf
    startup.c
    vectors.c
    main.c
)

target_compile_options(firmware.elf PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -ffreestanding
)

target_link_options(firmware.elf PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -nostdlib
    -T${CMAKE_CURRENT_SOURCE_DIR}/linker.ld
    -Wl,-Map=${CMAKE_CURRENT_BINARY_DIR}/firmware.map
)

set_target_properties(firmware.elf PROPERTIES
    SUFFIX ""
)

set_property(DIRECTORY APPEND PROPERTY
    CMAKE_CONFIGURE_DEPENDS linker.ld
)

add_custom_target(run
    COMMAND qemu-system-arm
        -M mps2-an385
        -kernel $<TARGET_FILE:firmware.elf>
        -nographic
    DEPENDS firmware.elf
    USES_TERMINAL
)

