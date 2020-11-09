def maximum(array):
    max_number = None

    for number in array:
        if max_number is None or number > max_number:
            max_number = number

    return number

def sortDigit(array, digit_position):
    bucket = [ [] for i in range(10)]

    for number in array:
        string_number = str(number)
        number_length = len(string_number)
        if digit_position > number_length:
            bucket[0].append(number)
        else:
            current_digit = int(string_number[-digit_position])
            bucket[current_digit].append(number)

    result = []

    for lst in bucket:
        result += lst

    return result


def radixSort(array):

    max_number = maximum(array)
    max_digit = len(str(max_number))
    newly_sorted = array[:]

    for digit_position in range(1, max_digit+1):
        newly_sorted = sortDigit(newly_sorted, digit_position)

    return newly_sorted


# A = [3, 44, 38, 5, 47, 15, 36, 26, 27, 2, 46, 4, 19, 50, 48]
# print(radixSort(A))