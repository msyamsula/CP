import re

def solution(string):
    regex = '\(\w*\)|\[\w*\]|\{\w*\}'

    status = re.search(regex, string)
    print(string)

    while status != None:
        string = re.sub(regex, '', string)
        print(string)
        status = re.search(regex, string)

    if string == '':
        return 1
    else:
        return 0

cb1 = '{'
cb2 = '}'
string = "(ege_0123){(abac)[(234{5426[}]})]}(){}"
print(solution(string))