n = int(input())

d = {}
total = 0
for i in range(n):
    key = input()
    try:
        data = d[key]
    except:
        data = None

    if data == None:
        d[key] = 1
        total += 1
    else:
        d[key] += 1

print(total)
for key in d:
    print(d[key], end=' ')