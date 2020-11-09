def radix(arr):
    maxNumber=max(arr)
    stringNumber=str(maxNumber)
    maxDigit=len(stringNumber)
    i=0

    while(i<maxDigit):
        bucket=[ [] for j in range(10) ]
        i+=1
        for num in arr:
            stringNum=str(num)
            if i>1 and num<10**(i-1):
                bucket[0].append(num)
            else:
                digit=int(stringNum[-i])
                bucket[digit].append(num)

        arr=[]
        for n in bucket:
            arr+=n

    return arr

def solution(A):
    A=radix(A)
    minNumber=1
    # print(A)
    for num in A:
        if num==minNumber:
            minNumber+=1
        elif num-minNumber>=2:
            break
        else:
            continue
        print(minNumber)

    return minNumber

# print(solution([1,3,6,4,1,2,7,8]))

def missingInteger(A):
    length = len(A)
    checklist = [0 for i in range(length)]

    for num in A:
        if num <= 0 or num > length:
            continue
        else:
            checklist[num-1] = 1

    print(checklist)

    for i, check in enumerate(checklist):
        if check == 0:
            return i+1

print(missingInteger([1,3,6,4,1,2,7,8]))
