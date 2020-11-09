def factorial(x):
    if x<=1:
        return 1

    return factorial(x-1)*x

def permutation(arr):
    s = arr[0] + arr[1]
    num = factorial(s)
    den = factorial(arr[0]) * factorial(arr[1])

    return int(num/den)

def totalPermutation(N, P):

    comb = []
    total = 0
    for i in range(N+1):
        if (N-i) % 2 == 0:
            a = i
            b = (N-i)/2
            new_comb = [a, b]
            comb.append(new_comb)
            total += permutation(new_comb)

    print(comb, total)
    divider = 2**P

    return total%divider



def solution(A, B):

    result = []
    for i in range(len(A)):
        result.append(totalPermutation(A[i], B[i]))

    return result

A = [20,4,5,5,1]
B = [10000,2,4,3,1]

print(solution(A, B))

