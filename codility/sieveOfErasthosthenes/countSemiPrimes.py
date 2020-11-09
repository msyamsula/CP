def primeFactor(num):

    if num == 1:
        return [1]

    factor = []
    
    for i in range(2, num+1):
        mod = num % i
        if mod == 0:
            factor.append(i)
            break

    new_factor = primeFactor(int(num/factor[0]))

    return factor + new_factor

def isSemiPrime(num):

    factor = primeFactor(num)
    n = len(factor)
    if n != 3:
        return False

    return True

def solution(P, Q):

    n = len(P)
    result = []
    for i in range(n):
        curr_total = 0
        for num in range(P[i], Q[i]+1):
            if isSemiPrime(num):
                curr_total += 1
        
        result.append(curr_total)

    return result

P = [1, 4, 16]
Q = [26, 10, 20]
print(solution(P, Q))