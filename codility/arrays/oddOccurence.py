def solution(arr):

    dictionary = {}

    for num in arr:
        try:
            data = dictionary[num]
        except:
            data = 'first time'
        
        if data == 'first time':
            dictionary[num] = 1
        else:
            del dictionary[num]

    return dictionary.keys()[0]

print(solution([1,3,5,3,1]))