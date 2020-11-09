from mergeSort import mergeSort

def knapsack(arr):
    length = len(arr)

    if length == 1:
        return arr

    if length < 1:
        return []

    sub_arr = arr[:-1]
    last_number = arr[-1]

    result = knapsack(sub_arr)
    if last_number not in result:
        result.append(last_number)

    for i in range(len(result) - 1):
        if last_number + result[i] not in result:
            result.append(last_number+result[i])


    return result

A = [1,3,3,5]
# A = [1,2,3]
w = knapsack(A)
# print(mergeSort(w))
print(w)

# sub_arr = A[:-1]
# last_number = A[-1]

# result = knapsack(sub_arr)

# for i in range(len(result)):
#     data = last_number + result[i]
#     result.append(data)

# print(result)