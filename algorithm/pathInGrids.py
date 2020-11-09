def pathInGrid(grids, greater_grids):

    length = len(grids)
    greater_length = len(greater_grids)

    if length == 1:
        return grids[0][0], (0,0)

    if length < 1:
        return 0, (-1,-1)

    downsize = length - 1

    downsize_grid = grids[:]

    for i in range(length):
        downsize_grid[i] = downsize_grid[i][:downsize]

    downsize_grid = downsize_grid[: downsize]

    total, current_position = pathInGrid(downsize_grid, greater_grids)
    curr_row = current_position[0]
    curr_col = current_position[1]

    for j in range(2):
        if curr_col == greater_length - 1:
            total += greater_grids[curr_row + 1][curr_col]
            curr_row += 1
        elif curr_row == greater_length - 1:
            total += greater_grids[curr_row][curr_col + 1]
            curr_col += 1
        else:
            choices = [greater_grids[curr_row][curr_col + 1], greater_grids[curr_row + 1][curr_col]]

            if choices[0] > choices[1]:
                curr_col = curr_col + 1
                total += choices[0]
            else:
                curr_row = curr_row + 1
                total += choices[1]

        print(curr_row, curr_col)        

    return total, (curr_row, curr_col)

grid = [
    [3,7,9,2,7],
    [9,8,3,5,5],
    [1,7,9,8,5],
    [3,8,6,4,10],
    [6,3,9,7,8]
]

print(pathInGrid(grid, grid)[0])