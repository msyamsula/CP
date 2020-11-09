def mergeSort(n, arr):

    if n == 1:
        return arr

    mid = int((n-1)/2)
    l = mid+1
    left = mergeSort(l, arr[:mid+1])
    right = mergeSort(n-l, arr[mid+1:])

    result = []
    while left and right:
        if left[0] < right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))

    if left:
        result += left
    elif right:
        result += right

    return result

def solution(N, L, case):

    print(case)
    ''' dechiper first value '''
    first_value = case[0]
    limit = int(first_value**(0.5))
    primes = []
    for num in range(2, limit+1):
        if first_value % num == 0:
            primes.append(num)
            primes.append(int(first_value/num))

    second_value = case[1]
    if second_value % primes[0] == 0:
        temp = primes[1]
        primes[1] = primes[0]
        primes[0] = temp        

    for i in range(1, L):
        next_prime = int(case[i]/primes[i])
        primes.append(next_prime)

    sorted_prime = mergeSort(L+1, primes)
    p_d = {}
    i = 0
    j = 0
    while j < L+1:
        value = chr(65+i)
        try:
            exist = p_d[sorted_prime[j]]
        except:
            exist = None
        
        if exist == None:
            p_d[sorted_prime[j]] = value
            i += 1

        j += 1

    result = ''
    for p in primes:
        result += p_d[p]

    return result



if __name__ == '__main__':

    T = int(input())

    for i in range(T):
        line_1 = input().split(' ')
        N = int(line_1[0])
        L = int(line_1[1])
        case = input().split(' ')
        for j, c in enumerate(case):
            case[j] = int(case[j])

        string = solution(N, L, case)
        result = 'Case #{}: {}'.format(i+1, string)
        print(result)
            
