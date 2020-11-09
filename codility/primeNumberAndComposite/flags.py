def solution(A):
    n = len(A)
    peaks = []
    n_peak = 0
    for i in range(1,n-1):
        if A[i] > A[i-1] and A[i] > A[i+1]:
            peaks.append(i)
            n_peak += 1

    if n_peak == 0:
        return 0
    elif n_peak == 1:
        return 1

    n_flags = 1
    for f in range(2,n_peak+1):
        flags_amount = 1
        prev_flag = peaks[0]
        for i in range(1, n_peak):
            if flags_amount == f:
                break

            distance = peaks[i] - prev_flag
            if distance >= f:
                flags_amount += 1
                prev_flag = peaks[i]

        if flags_amount > n_flags:
            n_flags = flags_amount

    return n_flags

A = [1,5,3,4,3,4,1,2,3,4,6,2]
print(solution(A))