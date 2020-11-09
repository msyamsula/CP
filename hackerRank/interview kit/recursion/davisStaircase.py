memory = {}
def stepPerms(n):
    if n in memory:
        return memory[n]
        
    if n == 1 or n == 0:
        return 1

    step = [1, 2, 3]
    choices = 0
    for s in step:
        if n < s:
            break

        curr_choices = 1
        if n >= s:
            memory[n-s] = stepPerms(n-s)
            curr_choices *= memory[n-s]
        
        choices += curr_choices

    return choices

n = 35
a = stepPerm(n)
print(a)