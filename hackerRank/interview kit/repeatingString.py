def repeatingString(s, n):
    n_a = 0
    length = len(s)

    for i in range(length):
        if s[i] == 'a':
            n_a += 1

    n_duplicate = int(n/length)
    remainder = n%length

    total_a = n_duplicate*n_a

    for i in range(remainder):
        if s[i] == 'a':
            total_a += 1

    return total_a


s = 'abac'
n = 10
a = repeatingString(s, n)