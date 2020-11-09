A=[1, 3, 1, 4, 2, 3, 5, 4]

def frogRiverOne(X, A):

    river = [0 for i in range(X+1)]
    river[0] = 1
    total = 1

    for i, num in enumerate(A):
        if river[num] == 1:
            continue
        elif river[num] == 0:
            river[num] = 1
            total += 1

        if total == X+1:
            return i

    return -1

print(frogRiverOne(5,A))
