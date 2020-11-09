def findNextValue(num, arr, modulo):
    next_number = arr[0]
    pivot = (num+arr[0])%modulo
    for number in arr:
        if (number+num)%modulo > pivot:
            next_number = number
            pivot = (number+num)%modulo

    return next_number

def solution():
    first_line = input()
    first_line_split = first_line.split(' ')
    total_array = int(first_line_split[0])
    modulo = int(first_line_split[1])

    if modulo == 1:
        return 0

    group_list = []
    for i in range(total_array):
        the_list = input()
        if len(the_list) == 1:
            input_list = [int(the_list)]
        else:
            input_list = the_list.split(' ')

        ith_list = []
        for number in input_list:
            ith_list.append((int(number)**2))
        group_list.append(ith_list)
        # print(group_list, type(group_list))

    group_length = len(group_list)
    current_number = 0
    choice_list = []
    for i in range(group_length):
        next_number = findNextValue(current_number, group_list[i], modulo)
        current_number+=next_number
        choice_list.append(next_number)
        print('cur:',current_number-next_number, 'arr:',group_list[i], 'next:', next_number)
    
    result1 = current_number%modulo
    print(result1)
    print()

    current_number = 0
    for i in range(group_length):
        next_number = findNextValue(current_number, group_list[-i-1], modulo)
        current_number+=next_number
        choice_list.append(next_number)
        print('cur:',current_number-next_number, 'arr:',group_list[-i-1], 'next:', next_number)

    result2 = current_number%modulo
    # print(result2)
    
    if result1 > result2:
        return result1

    return result2

print(solution())
# print(findNextValue(0, [4,25,16], 1000))