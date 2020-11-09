first_line = input().split(' ')
n = int(first_line[0])
m = int(first_line[1])

second_line = input().split(' ')
arr = second_line

third_line = input().split(' ')
A = third_line

fourth_line = input().split(' ')
B = fourth_line

dA = {}
dB = {}

for i in range(m):
    key_a = A[i]
    key_b = B[i]
    try:
        a = dA[key_a]
    except:
        a = None

    try:
        b = dB[key_b]
    except:
        b = None

    if a == None:
        dA[key_a] = True
    
    if b == None:
        dB[key_b] = True


happines = 0
for i in range(n):
    num = arr[i]

    try:
        like = dA[num]
    except:
        like = None

    try:
        dislike = dB[num]
    except:
        dislike = None

    if like:
        happines += 1
    elif dislike:
        happines -= 1
    elif like == None and dislike == None:
        continue

print(happines)
    
