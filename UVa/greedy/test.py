from statistics import mean
from math import ceil

lst = [27.38,9.58,9.58,10.88,4.67,4.67,4.67,5.75,20.25,1.71,3.75,12.83,1.04,6.04,1.79,5.13,6.17,5.17,4.96,4.21]
lst.sort()
print(lst)
n = len(lst)
result = []
for i in range(ceil(n*0.9)):
    result.append(lst[i])

print(lst)
print(result)
