def validateIntersection(ctr1, rad1, ctr2, rad2):
    circle_distance = ctr2-ctr1
    if circle_distance > rad2 + rad1:
        return False
    return True

def solution(arr):
    arr_length = len(arr)

    if arr_length < 2:
        return 0

    total_intersection = 0
    for i in range(arr_length-1):
        for j in range(i+1, arr_length):
            if validateIntersection(i, arr[i], j, arr[j]):
                total_intersection+=1

    if total_intersection > 10000000:
        return -1
    
    return total_intersection

# test = [1, 5, 2, 1, 4, 0]
# test = [1, 2]
test = [1, 1, 1]
print(solution(test))