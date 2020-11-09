def get_average(A):
    length = len(A)
    total = 0

    for num in A:
        total += num

    return total/length

def solution(A):
    length = len(A)
    minimal = None
    index = None
    for size in range(2,length):
        for i in range(length-size+1):
            slice_arr = A[i:i+size]
            average = get_average(slice_arr)
            if minimal == None or average < minimal:
                minimal = average
                index = i

    return index


A = [4, 2, 2, 5, 1, 5, 8]
print(solution(A))
            
            
