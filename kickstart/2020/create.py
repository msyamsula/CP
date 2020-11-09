import sys, os

name = sys.argv[1]
command = "cp ~/Desktop/blanko.cpp {name}".format(name=name)
# print(name)
os.system(command)
command = "code {name}".format(name=name)
os.system(command)
