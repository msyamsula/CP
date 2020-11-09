test_array = [-2,-3,-5,-6,0]

def maximumNumber(arr):
    arr_length = len(arr)
    max_number = arr[0]
    for i in range(arr_length):
        if arr[i]>max_number:
            max_number = arr[i]

    return max_number

def radixSort(array):
    arr = array[:]
    max_number = maximumNumber(arr)
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

def radixSortWithNegative(arr):
    arr_positive = [num for num in arr if num>=0]
    arr_negative = [num for num in arr if num<0]

    if arr_positive == []:
        sorted_positive = []
    else:
        sorted_positive = radixSort(arr_positive)

    if arr_negative == []:
        sorted_negative = []
    else:
        sorted_negative = radixSort(arr_negative)

    result = sorted_negative + sorted_positive

    return result


def maxOfThree(arr):
    if len(arr)<=2:
        return None
    
    sorted_arr = radixSortWithNegative(arr)
    zero_excluded_arr = [num for num in sorted_arr if num!=0]

    if len(zero_excluded_arr) < 3:
        return 0

    if len(zero_excluded_arr) == 3:
        return zero_excluded_arr[0]*zero_excluded_arr[1]*zero_excluded_arr[2]
        

    threeProduct = None

    threeProductLeft = zero_excluded_arr[0]*zero_excluded_arr[1]*zero_excluded_arr[-1]
    threeProductRight = zero_excluded_arr[-1]*zero_excluded_arr[-2]*zero_excluded_arr[-3]

    if threeProductLeft < 0 and threeProductRight < 0 and len(zero_excluded_arr) < len(arr):
        threeProduct = 0
    elif threeProductLeft > threeProductRight:
        threeProduct = threeProductLeft
    elif threeProductLeft < threeProductRight:
        threeProduct = threeProductRight

    return threeProduct

print(maxOfThree(test_array))
# print(maximum(test_array))