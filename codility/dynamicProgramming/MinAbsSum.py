import numpy as np
import matplotlib.pyplot as plt

A = [1,5,2,-2]
S = [-5,1,1,1]

step = 1
s0 = [-20 + step*i for i in range(41)]
# print(s0)
y = []
for num in s0:
    S[0] = num
    y_i = np.dot([A], np.transpose([S]))[0][0]
    y.append(y_i**2)

S = [0,0,0,0]

def gradient(A, S):
    grad = []
    dot_prod = np.dot(A, np.transpose(S))
    for i in range(len(A)):
        g = 2*dot_prod*A[i]
        grad.append(g)
    
    return grad

def gradient_descent(A, S, step, rep):
    s = S
    s0 = []
    for i in range(rep):
        g = gradient(A, s)
        for i in range(len(s)):
            s[i] = s[i] - g[i]*step
        s0.append(s[2])

    return [s0]

s0 = np.transpose(np.array(gradient_descent(A,S, 0.01, 10)))
# print(np.dot([A], np.transpose([S]))[0][0])
rep = np.transpose(np.array([[i for i in range(10)]]))
# print(s0.shape, rep.shape)
# print(rep.shapes)
plt.plot(rep,s0)
plt.show()

# s = [-5, 1, 0, 0]

# print(np.dot(A, np.transpose(s)))
S = [-5,1,0,0]
print(gradient(A,S))