from binaryTree import binaryTree
from radixSort import radixSort

def book(string):

    bookeeping = {}

    for char in string:
        if char in bookeeping:
            bookeeping[char] += 1
        else:
            bookeeping[char] = 1

    return bookeeping

def huffmanCoding(string):

    bookeeping = book(string)
    sorted_bookeeping = radixSort(bookeeping.values())
    root = sum(sorted_bookeeping)

    bt = binaryTree(root)
    # return sorted_bookeeping
    bit_representation = ''
    bit_representation_dict = {}
    length = len(string)

    for i in range(1, length+1):
        for data in bookeeping:
            if len(bookeeping) == 1:
                bt.addRight(data)
                bit_representation = bit_representation[:-1] + '1'
                bit_representation_dict[data] = bit_representation
                break
            elif bookeeping[data] == sorted_bookeeping[-i]:
                bt.addLeft(data)
                bit_representation += '0'
                bit_representation_dict[data] = bit_representation
                remaining_sum = sum(sorted_bookeeping[:-i])
                bt.addRight(sum)
                bit_representation = bit_representation[:-1] + '1'

                del bookeeping[data]
                break

    # return bit_representation_dict
    binary_representation = ''
    for char in string:
        binary_representation += bit_representation_dict[char]

    return binary_representation


def huffmanCoding2(string):
    bookeeping = book(string)
    sorted_bookeeping = radixSort(bookeeping.values())
    length = len(sorted_bookeeping)
    bit_representation = ''
    bit_representation_dict = {}

    for i in range(1, length+1):
        for char in bookeeping:
            if len(bookeeping) == 1:
                bit_representation = bit_representation[:-1] + '1'
                bit_representation_dict[char] = bit_representation
                break
            elif bookeeping[char] == sorted_bookeeping[-i] and bit_representation == '':
                bit_representation += '0'
                bit_representation_dict[char] = bit_representation
                del bookeeping[char]
                break
            elif bookeeping[char] == sorted_bookeeping[-i]:
                bit_representation = '1' + bit_representation
                bit_representation_dict[char] = bit_representation
                del bookeeping[char]
                break

    # return bit_representation_dict
    binary_representation = ''
    for char in string:
        binary_representation += bit_representation_dict[char]

    return binary_representation
print(huffmanCoding('aabacdaca'))