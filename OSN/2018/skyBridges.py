def isExist(d, key):
    try:
        data = d[key]
    except:
        data = None

    return data

def makeInt(arr):

    result = []
    for s in arr:
        result.append(int(s))

    return result

def solution():
    
    data_input = input()
    array_input = data_input.split(' ')
    n_floor = int(array_input[0])
    n_bridges = int(array_input[1])

    data_input = input()
    array_input = data_input.split(' ')
    H = makeInt(array_input)

    data_input = input()
    array_input = data_input.split(' ')
    A = makeInt(array_input)

    data_input = input()
    array_input = data_input.split(' ')
    B = makeInt(array_input)

    accesible_dict = {}


    for i in range(n_floor):
        curr_floor = i+1
        bridge_height = H[B[i]-1]
        new_floor = []
        for j in range(n_floor):
            curr_new_floor = j+1
            new_bridge_height = H[A[j]-1]
            if bridge_height == new_bridge_height:
                if curr_floor > bridge_height and curr_new_floor > bridge_height:
                    continue
                elif curr_floor < bridge_height and curr_new_floor < bridge_height:
                    continue
                else:
                    new_floor.append(curr_new_floor)
        
        accesible_dict[curr_floor] = new_floor
        if new_floor == []:
            return 0

    priority = [None for i in range(n_floor)]
    for key in accesible_dict:
        choices = accesible_dict[key]
        n_choices = len(choices)
        index = n_choices - 1
        priority[index] = {key:choices}

    print(accesible_dict)
solution()