def solution(path):

    mine = ''
    for c in path:
        mine += 'E' if c=='S' else 'S'

    return mine


if __name__ == '__main__':

    T = int(input())

    for i in range(T):
        dim = int(input())
        path = input()

        my_path = solution(path)
        result = 'Case #{}: {}'.format(i+1, my_path)
        print(result)
            
