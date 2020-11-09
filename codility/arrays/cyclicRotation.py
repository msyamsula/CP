def solution(A, K):
    if not A:
        return []

    result=[]
    k=K%len(A)
    newEnd=len(A)-k
    for i in range(newEnd,len(A)):
        result.append(A[i])

    for i in range(newEnd):
        result.append(A[i])

    return result

print(solution([],12))