def permutation(array):

    length = len(array)

    if length == 1:
        return [array]

    all_permutation = []

    for i in range(length):
        start = [array[i]]
        other = array[:i] + array[i+1:]
        subset_permutation = permutation(other)
        for subset in subset_permutation:
            new_permutation = start + subset
            all_permutation.append(new_permutation)


    return all_permutation

print(permutation([1,2,3,4]))