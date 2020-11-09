import os, time

n = 5
sample = 1
input_folder = "a0-input"
output_folder = "a0-output"

for i in range(n):
    inp = f'{input_folder}/mengawasi_{i+1}.in'
    out = f'{output_folder}/mengawasi_{i+1}.out'
    command = f"./prog < {inp} > {out}"
    print(command)
    os.system(command)
    time.sleep(1)

for i in range(sample):
    inp = f'{input_folder}/mengawasi_sample_{i+1}.in'
    out = f'{output_folder}/mengawasi_sample_{i+1}.out'
    command = f"./prog < {inp} > {out}"
    print(command)
    os.system(command)
    time.sleep(1)
