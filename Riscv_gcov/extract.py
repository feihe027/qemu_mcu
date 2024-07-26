import re
import os
import time
import subprocess


def extract_info_from_file(file_path):
    # Define regex pattern to match the desired line
    pattern_emit = r'(\d+):Emitting (\d+) bytes for (.+)$'

    pattern_line = r'^[0-9a-fA-F]{8}:.*$'

    # Read the file line by line
    with open(file_path, 'r') as file:
        lines = file.readlines()

        size = 0
        filepath = ""
        for line in lines:
            # Match the line against the pattern
            match = re.match(pattern_emit, line)
            match_line = re.match(pattern_line, line)

            if match_line:
                hex_numbers = line.split(": ")[1].replace(" ", "")
                byte_data = bytes.fromhex(hex_numbers)
                with open(filepath, "ab") as file:
                    file.write(byte_data)

            if match:
                index = match.group(1)
                size = int(match.group(2))
                filepath = match.group(3)
                folder_path = os.path.dirname(filepath)
                os.makedirs(folder_path, exist_ok=True)


if __name__ == "__main__":
    command = [
        R'qemu-system-riscv32',
        '-machine', 'virt',
        '-serial', 'stdio',
        '-nodefaults',
        '-monitor', 'null',
        '-bios', 'none',
        '-smp', '1',
        '-kernel', 'output/HelloWorld.elf',
        '-nographic'
    ]
    
    output = ''
    try:
        process = subprocess.Popen(
            command, stdout=subprocess.PIPE, universal_newlines=True, bufsize=8192*2)
        
        while True:
            line = process.stdout.readline()
            if not line:
                break 
            output += line
            if line.startswith('__gcov_exit finish'):
                process.terminate()
    except subprocess.CalledProcessError as e:
        print(f"Error executing command: {e}")
        output = e.output

    output_file = "main.log"
    with open(output_file, 'w') as file:
        file.write(output)

    extract_info_from_file(output_file)
    exit(0)
