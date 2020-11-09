memory = {}
def superDigit(num, multiply=1):
    try:
        evaluate = memory[num]
        exist = True
    except:
        exist = False

    if exist:
        return evaluate

    total = 0
    for digit in num:
        int_digit = int(digit)
        total += int_digit

    p = str(multiply*total)

    try:
        evaluate = p[1]
        single_digit = False
    except:
        single_digit = True

    if single_digit:
        memory[num] = p
        return memory[num]

    total = 0
    for digit in p:
        int_digit = int(digit)
        total += int_digit

    str_total = str(total)
    memory[num] = superDigit(str_total)
    return memory[num]

print(superDigit('9875', 4))
print(memory)