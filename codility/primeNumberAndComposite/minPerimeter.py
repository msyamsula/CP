from math import ceil, floor

def solution(N):

    p = int(ceil(N**0.5))
    l = 0
    
    if p**2 == N:
        return 4*p

    for i in range(1, p):
        if N % i == 0 and i > l:
            l = i

    p = int(N/l)
    return 2*(p+l)


print(solution(36))