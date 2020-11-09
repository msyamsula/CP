def abbreviation(a, b):

    n = len(a)
    m = len(b)
    if m > n:
        return 'NO'

    result = ''
    i = 0
    j = 0
    while j < n:
        if i == m and j < n:
            if a[j].upper() == a[j]:
                return 'NO'
            else:
                j += 1
        else: 
            if a[j].upper() == b[i]:
                result += a[j].upper()
                i += 1
                j += 1
            else:
                if a[j].upper() == a[j] and result[-1] != a[j]:
                    result += a[j]
                j += 1
        print(result)
    return 'YES' if result == b else 'NO'

# if __name__ == '__main__':

#     q = int(input())

#     for q_itr in range(q):
#         a = input()

#         b = input()

#         result = abbreviation(a, b)
#         print(result)



# print(abbreviation('LLZOSYAMQRMBTZXTQMQcKGLR', 'LLZOSYAMBTZXMQKLR'))
# print(abbreviation('RDWPJPAMKGRIWAPBZSYWALDBLDOFLWIQPMPLEMCJXKAENTLVYMSJNRJAQQPWAGVcGOHEWQYZDJRAXZOYDMNZJVUSJGKKKSYNCSFWKVNHOGVYULALKEBUNZHERDDOFCYWBUCJGbvqlddfazmmohcewjg', 'RDWPJPAMKGRIWAPBZSYWALDBLDOFLWIQPMPLEMCJXKAENTLVYMSJNRJAQQPWAGVcGOHEWQYZDJRAXZOYDMNZJVUSJGKKKSYNCSFWKVNHOGVYULALKEBUNZHERDDOFCYWBUCJGbvqlddfazmmohcewjg'))
# print(abbreviation('RMPRWOBYTSXGVJQPDQEHTWXMOGHVWKATSWLBWPJBQTYKVHKMFKCYVVJXGLUEZTLSXCGBCAOAMFEAPPAGWMXXQAQTFCZGXKOGZLLUWTZDOYVWHIJZEIDOSHPFWHYXCIZKTKKVKQNDXMTCCBQMAGVCDPZOXHPSEQY', 'RMPRWOBYTSXGVJQPDQEHTWXMOGHVWKATSWLBWPJBQTYKVHKMFKCYVVJXGLUEZTLSXCGBCAOAMFEAPPAGWMXXQAQTFCZGXKOGZLLUWTZDOYVWHIJZEIDOSHPFWHYXCIZKTKKVKQNDXMTCCBQMAGVCDPZOXHPSEQY'))
print(abbreviation('BFZZVHdQYHQEMNEFFRFJTQmNWHFVXRXlGTFNBqWQmyOWYWSTDSTMJRYHjBNTEWADLgHVgGIRGKFQSeCXNFNaIFAXOiQORUDROaNoJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMvSTGEQCYAJSFvbqivjuqvuzafvwwifnrlcxgbjmigkms', 'BFZZVHQYHQEMNEFFRFJTQNWHFVXRXGTFNBWQOWYWSTDSTMJRYHBNTEWADLHVGIRGKFQSCXNFNIFAXOQORUDRONJPXWZXIAABZKSZYFTDDTRGZXVZZNWNRHMSTGEQCYAJSF'))

