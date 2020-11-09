def solution(n):

    n_str = str(n)

    split = 0
    for i in range(1, len(n_str)+1):
        if n_str[-i] == '4':
            split += 2*(10**(i-1))

    r_1 = n - split
    r_2 = split

    return '{} {}'.format(r_1, r_2)


if __name__ == '__main__':

    T = int(input())

    for i in range(T):
        prize = int(input())

        change = solution(prize)
        result = 'Case #{}: {}'.format(i+1, change)
        print(result)
            
