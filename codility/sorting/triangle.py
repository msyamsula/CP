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
        if left[0] >= right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    if left == []:
        return result + right
    elif right == []:
        return result + left

def validateTriange(arr):
    test = arr[1]+arr[2] > arr[0]
    if test:
        return True

    return False


def solution(arr):
    arr_length = len(arr)
    if arr_length < 3:
        return 0

    sorted_array = mergeSort(arr)
    print(sorted_array)

    for i in range(arr_length - 2):
        if sorted_array[i+2] <= 0:
            break
        elif validateTriange(sorted_array[i:i+3]):
            return 1
    
    return 0

memory = {}

def solution(array):
    arr = array[:]
    length = len(arr)

    for i in range(length):
        if arr[i] > 0:
            if arr[i] in memory:
                memory[arr[i]] += 1
            else:
                memory[arr[i]] = 1

    sides = list(memory.keys())
    sorted_sides = mergeSort(sides)

    for side in sorted_sides:
        if memory[side] > 2:
            return 1
        elif memory[side] == 2 and len(memory) > 1:
            return 1

    for i in range(len(sorted_sides) - 2):
        if validateTriange(sorted_sides[i:i+3]) == 1:
            return 1

    return 0


    # status = 0
    # for i in range(length):
    #     new_array = arr[:i] + arr[i+1:]
    #     print(new_array, status, i, arr[:i], arr[i+1:])
    #     status = solution(new_array)
    #     if status == 1:
    #         return 1

    # return 0


test_array = [-1,5,5,5,-3]
print(solution(test_array))