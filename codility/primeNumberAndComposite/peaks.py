def solution(arr):

    length = len(arr)

    if length < 1:
        return 0

    if length == 1:
        return 0

    peaks = []
    n_peaks = 0
    

    for i in range(1, length - 1):
        left = arr[i-1]
        right = arr[i+1]
        curr = arr[i]

        if curr > left and curr > right:
            peaks.append(i)
            n_peaks += 1

    if n_peaks == 0:
        return 0

    if length % n_peaks != 0:
        return 0

    if n_peaks == 1:
        return 1

    for i in range(n_peaks):
        p1 = int(i*length/n_peaks)
        p2 = ((i+1)*length/n_peaks)
        if not (p1 <= peaks[i] and peaks[i] < p2):
            return 0

    return n_peaks
# A = [1,2,3,4,3,4,1,2,3,4,6,2]
A = [0,100000]
print(solution(A))

            