first_line = input()
second_line = input().split(' ')

n = int(first_line)


n_pairs = 0
d = {}
for i in range(n):
    key = int(second_line[i])
    try:
        sock = d[key]
    except:
        sock = None

    if sock == None:
        d[key] = 1
    else:
        n_pairs += 1
        del d[key]

print(n_pairs)