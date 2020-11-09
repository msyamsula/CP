H = [8, 8, 5, 7, 9, 8, 7, 4, 8]
H = [3, 4, 6, 7, 9, 7, 6,4,3]
H = [1]

def solution(H):
    wall_length = len(H)
    
    if wall_length == 0:
        return 0
    
    if wall_length == 1:
        if H[0] == 0:
            return 0
        return 1
    
    significant_height = []
    block = 0
    
    for i in range(wall_length):
        if H[i] in significant_height:
            significant_height = [ h for h in significant_height if h <= H[i]]
            # print('* '*significant_height[-1])
            continue
        else:
            if H[i] == 0:
                significant_height = []
                continue
            block += 1
            significant_height = [ h for h in significant_height if h < H[i]]
            significant_height.append(H[i])
            # print('* '*significant_height[-1])

    
    return block

print(solution(H))