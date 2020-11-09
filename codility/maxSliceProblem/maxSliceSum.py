def solution(arr):

    length = len(arr)
    if length < 1:
        return 0

    if length == 1:
        return arr[0]

    minus = None
    plus = None
    for num in arr:
        if num < 0:
            minus = num

        if num > 0:
            plus = num

    if minus == None:
        return sum(arr)
    elif plus == None:
        return max(arr)

    sub_array = arr[:-1]
    last_number = arr[-1]

    prev_max = solution(sub_array)
    curr_max = last_number
    all_max = sum(arr)

    last_negative = 0
    last_negative_arr = []
    for i in range(1, len(arr)+1):
        if arr[-i] >= 0:
            last_negative += arr[-i]
        elif arr[-i] < 0:
            last_negative_arr.append(last_negative)
            last_negative += arr[-i]

    last_negative_arr.append(last_negative)

    return max([prev_max, curr_max, all_max, max(last_negative_arr)])
    
arr = [1,3,-5, 3,7]
arr =  [1, 3, -5, 3, 7, 14, 1, 29]
arr = [1,3, -5, 3, 7, 14, 29]
arr = [1,3,-5,3,7,14, -1 ,29]
arr = [-2,3,1]
arr = [3,1,1]
arr = [-1,1,4]
arr = [3, 2, -6, 4, 0]
arr = [-2,-1]
arr = [1,2]
print(solution(arr))