import re

with open("task.log", "r") as file:
    content = file.read()

# Hexadezimalzahlen aus den GDB-Datenzeilen lesen
values = []

for line in content.splitlines():
    if "<task_log" in line:
        data = line.split(":", 1)[1]
        values.extend(int(x, 16) for x in re.findall(r"0x[0-9a-fA-F]+", data))

tasks = {
    0x53: ("SensorTask", 3),
    0x50: ("ProcessingTask", 2),
    0x4C: ("LoggerTask", 1),
}

with open("task_readable.log", "w") as output:
    output.write(f"{'Tick':<10} {'Task':<20} {'Priorität'}\n")
    output.write("-" * 42 + "\n")

    for i in range(0, len(values) - 1, 2):
        tick = values[i]
        task_id = values[i + 1]

        if task_id in tasks:
            name, priority = tasks[task_id]
            output.write(f"{tick:<10} {name:<20} {priority}\n")

print("Fertig: task_readable.log")