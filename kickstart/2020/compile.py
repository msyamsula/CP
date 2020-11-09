import sys, os

name = sys.argv[1]
command = "c++ {name} -std=c++11 -o prog".format(name=name)
os.system(command)
