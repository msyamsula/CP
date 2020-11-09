from math import degrees, acos

def findMBC():
    
    ab_string = input()
    bc_string = input()

    ab = int(ab_string)
    bc = int(bc_string)

    area = ab*bc/2
    # print(area)
    ac = (ab**2 + bc**2)**0.5
    print(ac)
    bm = (2 * area)/ac
    # print(bm, bm*ac/2)
    am = (ac/2)

    cos = (bm**2 + bc**2 - am**2)/(2*bm*bc)
    # print(cos)
    rad_angle = acos(cos)

    value = int(round(degrees(rad_angle), 0))
    d = u'\N{DEGREE SIGN}'
    return '{}{}'.format(value,d)

print(findMBC())
