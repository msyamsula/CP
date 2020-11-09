def makeDict(string):
    d = {}
    for char in string:
        try:
            data = d[char]
        except:
            data = None

        if data == None:
            d[char] = 1
        else:
            d[char] += 1
    
    return d

def editDistance(str1, str2):

    d1 = makeDict(str1)
    d2 = makeDict(str2)

    deletion = 0
    addition = 0


    for char in d1:
        try:
            data = d2[char]
        except:
            data = None

        if data == None:
            deletion += d1[char]
        elif d2[char] < d1[char]:
            deletion += d1[char] - d2[char]
            del d2[char]
        elif d2[char] > d1[char]:
            addition += d2[char] - d1[char]
        elif d2[char] == d1[char]:
            del d2[char]

        print(char, d2, addition, deletion)

    for char in d2:
        addition += d2[char]

    if addition > deletion:
        return addition
    else:
        return deletion

print(editDistance('gogo', 'moovie'))
