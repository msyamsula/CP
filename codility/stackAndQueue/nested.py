import re

def solution(string):
    regex = '\(\w*\)'

    status = re.search(regex, string)

    while status != None:
        string = re.sub(regex, '', string)
        status = re.search(regex, string)

    if string == '':
        return 1
    else:
        return 0

string = "()()"
print(solution(string))