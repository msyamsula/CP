def solution(A):
    total=0
    cumulativeList=[]
    for num in A:
        total+=num
        cumulativeList.append(total)
    
    Min=None
    for i in range(len(cumulativeList)-1):
        left=cumulativeList[i]
        right=total-cumulativeList[i]
        newValue=abs(right-left)
        if Min==None or newValue<Min:
            Min=newValue

    return Min


print(solution([]))