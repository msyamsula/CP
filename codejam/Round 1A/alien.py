from math import log

def calculateRhyme(str_lst, l, index, old_d):
    new_d = {}
    for i in range(l):
        key = str_lst[i][index:]
        old_key = key[index+1:]
        try:
            cur_lst = old_d[old_key]
        except:
            continue

        length = len(cur_lst)
        lcl_idx = 0
        for j in range(length):
            word = cur_lst[lcl_idx]
            
            if (word[index:] == key and word != str_lst[i]):
                try:
                    new_d[key].append(cur_lst[lcl_idx])
                except:
                    new_d[key] = [cur_lst[lcl_idx]]
                cur_lst.pop(lcl_idx)
            else:
                lcl_idx += 1

    new_d.update(old_d)

    return new_d


if __name__ == "__main__":
    T = int(input())
    result = []

    for t in range(1, T+1):
        n = int(input())
        str_list = []
        for j in range(n):
            temp = input()
            str_list.append(temp)

        d = {}
        for i in range(n):
            key = str_list[i][-1]

            try:
                d[key].append(str_list[i])
            except:
                d[key] = [str_list[i]]

        limit = n/2 if n%2 == 0 else (n+1)/2
        if (len(d) > limit):
            result.append(0)
            continue

        index = -2
        for i in range(int(2)):
            d = calculateRhyme(str_list, n, index, d)
            index -= 1
        
        rhy_count = 0
        for key in d:
            n = len(d[key])
            if n > 1:
                rhy_count += int(log(n)/log(2))*2

        result.append(rhy_count)

    for i, r in enumerate(result):
        print("Case #{}: {}".format(i+1, r))
        
