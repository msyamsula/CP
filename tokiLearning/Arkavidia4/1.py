from random import randint

N = 5000
print(N)
C = 10**5000

for i in range(N):
    a = randint(0,C)
    print(a, end=' ')
    other = C-a
    print(other)