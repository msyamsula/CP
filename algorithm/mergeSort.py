def mergeSort(arr):
    length = len(arr)
    if length == 1:
        return arr

    if length%2 != 0:
        mid = int(length/2)
    else:
        mid = int((length-1)/2)

    left = mergeSort(arr[:mid+1])
    right = mergeSort(arr[mid+1:])
    result = []

    while left != [] and right != []:
        if left[0] <= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    if left == []:
        return result + right
    elif right == []:
        return result + left

A = [3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48]
print(mergeSort(A))

