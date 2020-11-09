def solution(X, Y, D):
    distance=Y-X
    if distance==0:
        return 0

    if D>=distance:
        return 1
    
    count=distance//D
    if distance%D!=0:
        count+=1

    return count

print(solution(10,1000,30))