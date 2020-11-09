def longestIncreasingSequence(array, n):
    arr = array[:n+1]
    length = len(arr)
    if length < 1:
        return []

    if length == 1:
        return arr

    last_number = arr[-1]
    sub_array = arr[:-1]

    current_sequence = longestIncreasingSequence(sub_array, len(sub_array)+1)
    if len(current_sequence) > 1 and last_number > current_sequence[-1]:
        return current_sequence + [last_number]
    elif len(current_sequence) > 1:
        return current_sequence
    elif len(current_sequence) == 1:
        if last_number > current_sequence[0]:
            return current_sequence + [last_number]
        else:
            return [last_number]

a = [6,2,5,1,7,4,8,3]
for i in range(len(a)):
    print(longestIncreasingSequence(a, i))