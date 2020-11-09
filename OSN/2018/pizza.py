def countingSort(array):
    length = len(array)
    max_number = max(array)
    bookeeping = [0 for i in range(max_number+1)]

    for number in array:
        bookeeping[number] += 1

    # print(bookeeping)

    result = []
    for i, count in enumerate(bookeeping):
        if count == 0:
            continue
        else:
            for j in range(count):
                result.append(i)

    # print(result)
    return result

def makeInt(arr):

    result = []
    for s in arr:
        result.append(int(s))

    return result

def isLike(pizza_dict, choice):
    try:
        check = pizza_dict[choice]
    except:
        check = None

    return check

def makeDict(arr):
    d = {}

    for num in arr:
        # num = int(n)
        d[num] = num

    return d

def turn(pizza, my_pizza, comp_pizza=[]):

    if pizza == []:
        return 0

    remaining_pizza = pizza[:]

    target = comp_pizza + countingSort(my_pizza)

    choice = None
    for p in target:
        index = p-1
        if remaining_pizza[index] == 0:
            continue
        elif remaining_pizza[index] > 0:
            choice = p
            remaining_pizza[index] -= 1
            break
        
    if choice == None:
        choice = 0

    return choice, remaining_pizza

def start():
    data_input = input()
    flavor_length = int(data_input.split(' ')[0])
    dengklek_strat = int(data_input.split(' ')[1])

    data_input = input()
    input_array = data_input.split(' ')
    pizza = makeInt(input_array)

    data_input = input()
    my_pizza_length = int(data_input.split(' ')[0])
    my_pizza = makeInt(data_input.split(' ')[1:])
    my_pizza_dict = {}
    
    data_input = input()
    dengklek_pizza_length = int(data_input.split(' ')[0])
    dengklek_pizza = makeInt(data_input.split(' ')[1:])
    dengklek_pizza_dict = {}


    my_pizza_dict = makeDict(my_pizza)
    dengklek_pizza_dict = makeDict(dengklek_pizza)
    print(my_pizza_dict, dengklek_pizza_dict)

    comp_pizza = []
    for i in range(flavor_length):
        choice = i+1

        my_check = isLike(my_pizza_dict, choice)
        dengklek_check = isLike(dengklek_pizza_dict, choice)
        print(my_check, dengklek_check)

        if my_check != None and dengklek_check != None:
            comp_pizza.append(choice)

    my_slice = 0
    dengklek_slice = 0
    while True:
        d = []
        my_choice, pizza = turn(pizza, my_pizza, comp_pizza)
        if dengklek_strat == 1:
            d = []
        elif dengklek_strat == 2:
            d = comp_pizza

        dengklek_choice, pizza = turn(pizza, dengklek_pizza, d)
        print('my:', my_choice, 'dengklek:', dengklek_choice, pizza)
        if my_choice != 0:
            my_slice += 1
        if dengklek_choice != 0:
            dengklek_slice += 1

        if dengklek_choice == 0 and my_choice == 0:
            break

    print(my_slice, dengklek_slice)

start()