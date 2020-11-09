def doubleSum(array, start, mid, end):
    sum = 0
    for i, number in enumerate(array):
        if i == start or i == mid or i == end:
            continue
        elif i >= start and i <= end:
            sum += number
    
    return sum
    

def solution(array):
    max = 0
    length = len(array)

    for n in range(4, length+1):
        for i in range(length - n + 1):
            for mid in range(i+1, i+n-1):
                new_max = doubleSum(array, i, mid, i+n-1)
                if new_max > max:
                    max = new_max

    return max


def check(d, key):
    try:
        value = d[key]
    except:
        return False

    return True

def solution(arr):

    length = len(arr)

    if length <= 3:
        return 0

    pivot = {}
    min_index = []
    
    for i in range(1, length):
        p1 = check(pivot, 1)
        p3 = check(pivot, 3)

        num = arr[i]
        if num < 0:
            if not p1:
                if num + sum(arr[1:i]) <= 0:
                    pivot[1] = i
                else:
                    pivot[1] = 0
            if p1 and not p3:
                if num + sum(arr[i+1:-1]) <= 0:
                    pivot[3] = i
                    break
                else:
                    pivot[3] = length - 1
                    min_index.append(i)
            elif p1 and p3:
                if i > pivot[1] and i < pivot[3]:
                    min_index.append(i)

    p1 = check(pivot, 1)
    p3 = check(pivot, 3)
    if not p1:
        return sum(arr[1:-1]) - min(arr[1:-1])
    if not p3:
        if min_index == []:
            return sum(arr[pivot[1]+1:-1]) - min(arr[pivot[1]+1:-1])
        # elif min
            
    print(pivot, min_index)

A=[5,4,-100,4,-1,3,2]
print(solution(A))