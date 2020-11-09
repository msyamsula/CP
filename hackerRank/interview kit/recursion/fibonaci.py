n = int(input())

memory = {}
def fibonacci(n):
    try:
        evaluate = memory[n]
    except:
        evaluate = None

    if evaluate != None:
        return evaluate

    if n == 0:
        return 0
    
    if n == 1:
        return 1
    
    memory[n] = fibonacci(n - 1) + fibonacci(n - 2)

    return memory[n]