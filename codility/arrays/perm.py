def quickSort(arr):
    if len(arr)<=1:
        return arr

    length=len(arr)
    middleIndex=length//2
    middleElement=arr[middleIndex]
    left=[]
    right=[middleElement]
    for i in range(length):
        number=arr[i]
        if number<middleElement and i != middleIndex:
            left.append(number)
        elif number>=middleElement and i != middleIndex:
            right.append(number)

    print(left, right)

    if left and right:
        return quickSort(left)+quickSort(right)
    elif not left:
        return right
    elif not right:
        return left


def solution(A):
    A=quickSort(A)
    for i in range(len(A)):
        if i+1 != A[i]:
            return 0
    return 1

print(solution([1,2,8,8,2,2]))