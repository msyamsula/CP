import random

# def maxSubsetSum(n, arr, memory={}):

#     key = n
#     try:
#         m = memory[key]
#         return m
#     except:
#         pass

#     if n == 1:
#         memory[key] = arr[0]
#         return memory[key]

#     if n == 2:
#         if arr[1] > arr[0]:
#             memory[key] = arr[1]
#         else:
#             memory[key] = arr[0]

#         return memory[key]

#     best = maxSubsetSum(n-1, arr[:n-1], memory)
#     evaluate = arr[-1]
#     if evaluate > best:
#         best = evaluate
    
#     evaluate = arr[-1] + maxSubsetSum(n-2, arr[:n-2], memory) 
#     if evaluate > best:
#         best = evaluate

#     memory[key] = best
#     return memory[key]

def maxSubsetSum(n, arr):
    memory = {}

    if n == 1:
        return arr[0]
    elif n == 2:
        return arr[0] if arr[0] > arr[1] else arr[1]

    memory[0] = arr[0]
    memory[1] = arr[0] if arr[0] > arr[1] else arr[1]

    best = memory[1]
    for i in range(2,n):
        best = arr[i] if arr[i] > best else best
        new_best = arr[i] + memory[i-2]
        best = new_best if new_best > best else best
        memory[i] = best

    return best

        
a = [random.randint(-10000,10000) for i in range(10**0)]
# a = [3,7,4,6,5]
# print(a)
print(maxSubsetSum(10**0, a))
b = [-5, -6, -7, 6, -3, -2, 6]
b = [4,3,2,-1,5]
n = len(b)
# print(n)
print(maxSubsetSum(n, b))
