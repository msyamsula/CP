A = [4, 3, 4, 4, 4, 2]
# A = [1,1]

def makeDict(arr):
    d = {}
    length = 0
    for num in arr:
        try:
            data = d[num]
        except:
            data = None

        if data == None:
            d[num] = 1
        else:
            d[num] += 1

        length += 1

    return length, d

def Leader(A):
    length, d = makeDict(A)
    half_length_plus = int(length/2)+1

    for num in d:
        if d[num] >= half_length_plus:
            return num

    return None

def solution(A):

    equilider = 0
    length = len(A)
    for i in range(length-1):
        leader1 = Leader(A[:i+1])
        leader2 = Leader(A[i+1:])
        print(A[:i+1], A[i+1:])
        print(leader1, leader2)
        if leader1 == leader2 and leader1 != None:
            equilider += 1
    
    return equilider
    

print(solution([1,2,3,4,5]))
# print(Leader([4,2]))
