def solution(A, P, Q):
    dna_length = len(A)
    query_length = len(P)
    dna_in_number = []
    result = []
    dict={97:1, 99:2, 103:3, 116:4}

    for i in range(dna_length):
        dna_in_number.append(ord(A[i].lower()))

    for i in range(query_length):
        slice_dna = dna_in_number[P[i]:Q[i]+1]
        min_factor = min(slice_dna)
        min_factor = dict[min_factor]
        result.append(min_factor)

    return result

A='cagccta'
P=[2, 5, 2]
Q=[4, 5, 5]
print(solution(A, P, Q))
