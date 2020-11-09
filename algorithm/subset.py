from math import log, ceil

def int2binary(integer, length):
    
    binary = [0 for i in range(length)]
    int_length_binary = int(ceil(log(integer+1, 2)))

    if length < int_length_binary:
        return 'length to short'
    if integer == 0:
        return binary
    if integer < 0:
        return 'negative number'

    curr_integer = integer
    i = 1
    while (curr_integer != 1):
        modulo = curr_integer % 2
        binary[-i] = modulo
        curr_integer = int(curr_integer/2)
        i += 1

    binary[-i] = 1

    return binary

def subset(array):

    length = len(array)
    max_binary = (2**length)

    binary = []

    for i in range(max_binary):
        subset_binary = int2binary(i, length)
        binary.append(subset_binary)
    
    full_set = []

    for binar in binary:
        new_set = []
        for i, num in enumerate(binar):
            if num == 1:
                new_set.append(array[i])
        
        full_set.append(new_set)

    return full_set

print(subset([1,2,3,4]))

