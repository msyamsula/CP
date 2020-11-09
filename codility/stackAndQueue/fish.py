A = [2, 3, 4, 1, 5, 6]
B = [0, 1, 0, 0, 1, 1]


def clear_stream(A, B, a):
    size = A[:]
    stream = B[:]
    alive = a

    for i in range(len(B)):
        if B[i] == 0:
            alive += 1
            stream = B[i+1:]
            size = A[i+1:]
        else:
            break
    
    downstream = stream[:]
    downsize = size[:]
    for i in range(len(downstream)-1, -1, -1):
        if downstream[i] == 1:
            alive += 1
            stream = downstream[:i]
            size = downsize[:i]
        else:
            break
    
    return [size, stream, alive]

def solution(A, B):
    elimination_result = clear_stream(A, B, 0)
    size = elimination_result[0]
    stream = elimination_result[1]
    alive = elimination_result[2]
    
    if len(stream) == 0:
        return alive

    while (stream[0] != 0 or stream[-1] !=1):
        for i in range(len(stream)):
            if stream[i]==0:
                if size[i-1] > size[i]:
                    size.pop(i)
                    stream.pop(i)
                else:
                    size.pop(i-1)
                    stream.pop(i-1)
                break
        
        elimination_result = clear_stream(size, stream, alive)
        size = elimination_result[0]
        stream = elimination_result[1]
        alive = elimination_result[2]
    
        if stream == []:
            return alive

print(solution(A,B))
        

