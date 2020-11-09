import matplotlib.pyplot as plt
import numpy as np


# size = input()
# a = input()
# b = input()
# print(a.split(' '))
# print(b.split(' '))
A = [1,2,3]
a = []
a.append((0,0,1))
a.append((0,0,2))
a.append((0,0,3))
a.append((0,1,0))
a.append((0,1,1))
a.append((0,1,2))
a.append((0,1,3))
a.append((0,2,0))
a.append((0,2,1))
a.append((0,2,2))
a.append((0,2,3))
a.append((1,0,0))
a.append((1,0,1))
a.append((1,0,2))
a.append((1,0,3))
a.append((1,1,0))
a.append((1,1,1))
a.append((1,1,2))
a.append((1,1,3))
a.append((1,2,0))
a.append((1,2,1))
a.append((1,2,2))
a.append((1,2,3))

B = [2,2,2]
b = []
b.append((0,0,1))
b.append((0,0,2))
b.append((0,1,0))
b.append((0,1,1))
b.append((0,1,2))
b.append((0,2,0))
b.append((0,2,1))
b.append((0,2,2))
b.append((1,0,0))
b.append((1,0,1))
b.append((1,0,2))
b.append((1,1,0))
b.append((1,1,1))
b.append((1,1,2))
b.append((1,2,0))
b.append((1,2,1))
b.append((1,2,2))
b.append((2,0,0))
b.append((2,0,1))
b.append((2,0,2))
b.append((2,1,0))
b.append((2,1,1))
b.append((2,1,2))
b.append((2,2,0))
b.append((2,2,1))
b.append((2,2,2))

n_error_a = []
overall_error_a = []

n_error_b = []
overall_error_b = []

for comb in a:
    n_total = 0
    overall_total = 0
    for i, num in enumerate(comb):
        n_temp = num/A[i]
        n_total += n_temp
        overall_total += num
    
    overall_error_a.append(overall_total/sum(A))
    n_error_a.append(n_total)

for comb in b:
    n_total = 0
    overall_total = 0
    for i, num in enumerate(comb):
        n_temp = num/B[i]
        n_total += n_temp
        overall_total += num
    
    overall_error_b.append(overall_total/sum(A))
    n_error_b.append(n_total)


n_error = []
overall_error = []

for i in range(len(n_error_a)):
    n_error.append(n_error_b[i]/n_error_a[i])
    overall_error.append(overall_error_a[i]/overall_error_b[i])

# print(n_error_a, overall_error_a)
# print(len(a), len(n_error_a))
x = np.linspace(1, 23, 23)
y1 = n_error
y2 = overall_error

plt.plot(x, y1, '-o', x, y2,'-x', label='overall_error')

plt.show()