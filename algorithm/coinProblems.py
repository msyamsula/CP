memory = {}

def coinProblem(arr, target):

    if target in memory:
        return memory[target]

    if target <= 0:
        return 0

    remainings = []
    for num in arr:
        new_remaining = target - num
        if new_remaining >= 0:
            remainings.append(new_remaining)

    solutions = []
    for remaining in remainings:
        memory[target] = coinProblem(arr, remaining) + 1
        solutions.append(memory[target])

    return min(solutions)

# array = [1,3,4]
# t = 1000

# print(coinProblem(array, t))
# print(memory)
