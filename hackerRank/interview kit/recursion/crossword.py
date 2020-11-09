map = []
for i in range(10):
    line = input()
    map.append(line)

# print(map)

horizontal_d = {}
for i in range(10):
    for j in range(10):
        char = map[i][j]

        if char == '-':
            try:
                data = horizontal_d[i]
            except:
                data = None

            if data == None or j - horizontal_d[i][-1] > 1:
                horizontal_d[i] = [j]
            else:
                horizontal_d[i] += [j]

    if len(horizontal_d[i]) == 1:
        del horizontal_d[i]

for key in horizontal_d:
    print(key, horizontal_d[key])

vertical_d = {}
for j in range(10):
    for i in range(10):
        char = map[i][j]

        if char == '-':
            try:
                data = vertical_d[i]
            except:
                data = None

            if data == None or j - vertical_d[i][-1] > 1:
                vertical_d[i] = [j]
            else:
                vertical_d[i] += [j]

    if len(vertical_d[i]) == 1:
        del vertical_d[i]

for key in vertical_d:
    print(key, vertical_d[key])