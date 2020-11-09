def maxIndex(A):
    Max=None
    index=0
    for i,num in enumerate(A):
        if Max==None or num>Max:
            index=i
            Max=num
    return index


def solution(K, M, A):
    indexMax = maxIndex(A)
    partition=[]
    increment=int(len(A)/K)
    
    for i in range(K):
        if i == K-1:
            partition.append(A[i*increment:])
        else:
            partition.append(A[i*increment:increment*(i+1)])
    
    print(partition)

solution(3,1,[2,1,5,1,2,2,2])
