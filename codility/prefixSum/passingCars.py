def solution(arr):

    length = len(arr)
    index = -1
    east_car = []
    total = 0
    for num in arr:
        if east_car == [] and num == 1:
            continue
        elif num == 0:
            east_car.append(0)
            total += (index+1)*east_car[index]
            index += 1
        elif num == 1:
            east_car[index] += 1

    if east_car != []:        
        total += (index+1)*east_car[-1]
    
    if total > 1000000000:
        return -1

    return total


