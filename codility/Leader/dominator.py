
A = [4, 3, 3, 2, 3, -1, 3, 3]
A = [0,1,0,1,0,1,1,2,2]
A=[1, 2, 1]

from math import ceil

from math import floor
def solution(A):
    length = len(A)
    if length == 0:
        return -1
    if length == 1:
        return 0
    den_count = int(floor((length/2)+1))
    # print(den_count
    for i, num in enumerate(A):
        if A.count(num) >= den_count:
            return i

    return -1

print(solution(A))