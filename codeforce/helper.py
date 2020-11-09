lst=[437,519,865,808,909,391,194,291,237,395,323,365,511,497,781,737,871,559,731,697,779,841,961]

def gcd(a, b):
    if (b==0): return a
    return gcd(b, a%b)

num = 961
for i in range(len(lst)):
    if (gcd(num, lst[i]) != 1):
        print(lst[i])
