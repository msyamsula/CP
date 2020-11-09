def radixSort(array):
    arr = array[:]
    max_number = max(arr)
    max_number_string = str(max_number)
    total_itteration = len(max_number_string)

    for digit_position in range(total_itteration):
        bucket = [[] for i in range(10)]

        for i in range(len(arr)):
            bigRemainder = arr[i]%(10**(digit_position+1))
            smallRemainder = arr[i]%(10**(digit_position))
            digit_float = (bigRemainder - smallRemainder)/(10**(digit_position))
            digit_int = int(digit_float)

            bucket[digit_int].append(arr[i])

        result = []
        for lst in bucket:
            result+=lst
        arr = result
        
    return arr

def solution(arr):
    if arr == []:
        return 0

    array_length = len(arr)
    if array_length == 1:
        return 1

    sorted_array = radixSort(arr)
    distinct_number = 1

    for i in range(array_length-1):
        if sorted_array[i+1] != sorted_array[i]:
            distinct_number+=1

    return distinct_number

test_array = [4,4,4,4]
print(solution(test_array))
