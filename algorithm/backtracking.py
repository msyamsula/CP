def verticalSearch(current_position, size, established_position):

    modulo = current_position % size

    danger_zone = [x for x in range(size**2) if x % size == modulo]

    for position in danger_zone:
        if position in established_position:
            return False

    return True

def horizontalSearch(current_position, size, established_position):
    current_row = int(current_position / size)
    start_row = current_row*size
    end_row = (current_row+1)*size - 1

    danger_zone = [x for x in range(size**2) if x>=start_row and x<=end_row]

    for position in danger_zone:
        if position in established_position:
            return False

    return True

def positiveDiagonalSearch(current_position, size, established_position):
    base_multiple = size - 1
    current_row = int(current_position/size)
    danger_zone = []
    for row in range(size):
        row_distance = row - current_row
        danger_position = current_position + row_distance*base_multiple
        danger_row = int(danger_position/size)
        if danger_row == row:
            danger_zone.append(danger_position)

    for position in danger_zone:
        if position in established_position:
            return False

    return True

def negativeDiagonalSearch(current_position, size, established_position):
    base_multiple = size + 1
    current_row = int(current_position/size)
    danger_zone = []
    for row in range(size):
        row_distance = row - current_row
        danger_position = current_position + row_distance*base_multiple
        danger_zone.append(danger_position)

    for position in danger_zone:
        if position in established_position:
            return False

    return True

def queen_backtracking(size, start):
    size_square = size**2
    established_position = [start]
    
    for i in range(size_square):
        if verticalSearch(i, size, established_position) and horizontalSearch(i, size, established_position) and negativeDiagonalSearch(i, size, established_position) and positiveDiagonalSearch(i, size, established_position):
            established_position.append(i)
        else:
            continue

    return established_position

def backtracking(size):

    for s in range(size**2):
        arr = queen_backtracking(size, s)
        if len(arr) == 5:
            print(queen_backtracking(size, s), s)

backtracking(5)