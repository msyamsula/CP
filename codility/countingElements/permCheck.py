def solution(arr):

    N = len(arr)

    if N < 1:
        return 0

    dictionary = {}

    for num in arr:
        if num < 1 or num > N:
            return 0
        
        try:
            data = dictionary[num]
        except:
            data = 'first'

        if data == 'first':
            dictionary[num] = num
        else:
            return 0

    return 1

print(solution([1,1]))