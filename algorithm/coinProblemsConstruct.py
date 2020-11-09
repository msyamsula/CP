from coinProblems import coinProblem

memory = {}

def coinsConstruction(arr, target):
    if target <= 0 :
        return []

    if target in memory:
        return memory[target]

    coin_remains = []
    new_targets = []
    for num in arr:
        new_target = target - num
        if new_target >= 0:
            new_targets.append(new_target)
            coin_remains.append(num)

    print(new_targets)
    
    total_coins = []
    for current_target in new_targets:
        total_coins.append(coinProblem(arr, current_target))

    # print(total_coins)

    coin_construction = []
    for i, coins in enumerate(total_coins):
        if coins == min(total_coins):
            memory[target] = coinsConstruction(arr, target - coin_remains[i]) + [coin_remains[i]]
            coin_construction = memory[target]
            break

    return memory[target]

arr = [1,3,4]
t = 10
print(coinsConstruction(arr, t))
print(memory)
print(' ')
print(coinsConstruction(arr, 6))
print(memory)
