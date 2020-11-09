from os import getenv, getcwd
import subprocess as sp
from dotenv import load_dotenv
import os
import json

prime_list = {'one':1}
# dump = json.dumps(prime_list, indent=2)
# f = open('./memory.json', 'w')
# print(dump, file=f)
# f.close()

# with open('./memory.json', 'w') as f:
#     data = json.dumps(prime_list, indent=2)
#     print(data, file=f)
#     f.close()

with open('memory.json', 'r') as data_file:
    data = json.loads(data_file.read())
    data_file.close()
# f.close()
print(data, type(data))
    