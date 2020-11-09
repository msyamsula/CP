'''
crucial idea == bookeeping record

steps:
create bookeeping record based on data.
bookeeping index means value in data, bookeeping value means total appearance of that value

e.g
data = [1, 3, 6, 9, 9, 3, 5, 9]
bookeeping = [0, 1, 0, 2, 0, 1, 1, 0, 0, 3]
index 0 = 0 --> data 0 appear 0 times
index 1 = 1 --> data 1 appear 1 times
index 3 = 2 --> data 3 appear 2 times
and so on

after bookeeping is done, recreate new list from that bookeeping
'''

def countingSort(array):
    length = len(array)
    max_number = max(array)
    bookeeping = [0 for i in range(max_number+1)]

    for number in array:
        bookeeping[number] += 1

    print(bookeeping)

    result = []
    for i, count in enumerate(bookeeping):
        if count == 0:
            continue
        else:
            for j in range(count):
                result.append(i)

    # print(result)
    return result
        

# A=[1,3,6,9,9,3,5,9]
# countingSort(A)