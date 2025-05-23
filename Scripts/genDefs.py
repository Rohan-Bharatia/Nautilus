import re
import os
import subprocess

input_file = os.path.join(os.path.dirname(__file__), '..', 'Nautilus', 'Core', 'Preprocessor.h')
output_file = os.path.join(os.path.dirname(__file__), '..', 'Nautilus', 'PlatformDefs.cmake')

# Use cpp to preprocess the file and extract defined macros
cpp_command = ['cpp', '-dM', input_file]
cpp_output = subprocess.check_output(cpp_command)

# Parse the output to extract defined macros
macros = re.findall(r'#define\s+(\w+)', cpp_output.decode('utf-8'))

with open(output_file, 'w') as f:
    f.flush()
    for macro in macros:
        f.write(f'set({macro} 1)\n')
