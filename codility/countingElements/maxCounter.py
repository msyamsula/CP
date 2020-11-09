def increase(X):
    return 1

def setMax(arr):
    maxNum=max(arr)
    for i in range(len(arr)):
        arr[i]=maxNum

    return arr


def solution(N,A):
    result =[ 0 for j in range(N) ]
    print(result)
    for i, a in enumerate(A):
        if a<=N:
            result[a-1]+=1
        elif a>N:
            setMax(result)
        print(result)
    
    return result

def solution(N, A):

    maximum = 0
    fixed_maximum = 0
    # counter = [0 for i in range(N)]
    dictionary = {}
    limit = N+1
    length = len(A)

    for num in A:
        print(dictionary, maximum)
        if num == limit:
            dictionary = {}
            maximum += fixed_maximum
            fixed_maximum = 0
        else:
            try:
                data = dictionary[num]
            except:
                data = 'first'

            if data == 'first':
                dictionary[num] = 1
            else:
                dictionary[num] += 1

            if dictionary[num] > fixed_maximum:
                fixed_maximum = dictionary[num]

    result = []
    for i in range(N):
        try:
            data = dictionary[i+1] + maximum
        except:
            data = maximum

        result.append(data)

    return result
        

print(solution(5,[3,4,4,6,1,4,4]))