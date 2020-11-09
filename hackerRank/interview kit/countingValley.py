def countingValley(n, s):

    level = 0
    n_hills = 0.0
    for i in range(n):
        step = s[i]
        if step == 'D':
            if level == 0:
                n_hills += 0.5
            level -= 1
        elif step == 'U':
            level += 1
            if level == 0:
                n_hills += 0.5
        print(step, n_hills, level)

    return int(n_hills)

n = 8
s = 'DDDDDDDD'
a = countingValley(n, s)
print(a)