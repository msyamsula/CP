def climbingLeaderBoard(scores, n, alice, m):

    rank = []
    for i in range(n):
        if i == 0:
            rank.append(1)
        else:
            rank.append(rank[-1]) if scores[i] == scores[i-1] else rank.append(rank[-1]+1)

    result = []
    i = 0
    j = 0
    move = 1
    while j < m:
        
        if j == 0:
            move = 1
        else:
            move = -1 if alice[j] >= alice[j-1] else 1

        if move == 1:
            if alice[j] < scores[i]:
                if i == n-1:
                    result.append(rank[i]+1)
                    j += 1
                else:
                    i += move
            elif alice[j] >= scores[i]:
                result.append(rank[i])
                j += 1
        else:
            if alice[j] > scores[i]:
                if i == 0:
                    result.append(rank[i])
                    j += 1
                else:
                    i += move
            elif alice[j] == scores[i]:
                result.append(rank[i])
                j += 1
            elif alice[j] < scores[i]:
                result.append(rank[i]+1)
                j += 1                
            
    return result

scores = [100, 100, 50, 40, 40, 20, 10]
alice = [15, 60, 100, 30, 900, 5]
alice = [5, 25, 50, 120]
n = len(scores)
m = len(alice)
print(climbingLeaderBoard(scores, n, alice, m))