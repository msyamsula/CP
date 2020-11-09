import os
import json

with open('./memory.json', 'r') as f:
    memory = json.loads(f.read())
    f.close()

def checkPrime(num):

    if str(num) in memory:
        return True

    if num == 1:
        return False
    
    if num == 2:
        memory[2] = 2
        with open('./memory.json', 'w') as f:
            dump = json.dumps(memory, indent=2)
            print(dump, file=f)
            f.close()
        return True

    limit = int(num**0.5) + 2

    for i in range(2, limit):
        if num % i == 0:
            return False

    memory[num] = num
    with open('./memory.json', 'w') as f:
        dump = json.dumps(memory, indent=2)
        print(dump, file=f)
        f.close()

    return True

def primeList(max):
    status = 0

    for key in memory:
        if int(key) > max:
            status = 1
            break

    result = []
    if status == 1:
        print('from memory')
        for key in memory:
            if memory[key] < max:
                result.append(memory[key])
        return result
    else:
        for i in range(2, max+1):
            if str(i) in memory:
                result.append(memory[str(i)])
            elif checkPrime(i):
                result.append(i)
        return result 

print(primeList(3))
# print(memory)