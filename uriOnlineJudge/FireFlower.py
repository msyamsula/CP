def solution(r1,x1,y1,r2,x2,y2):
    dx=abs(x1-x2)
    dy=abs(y1-y2)
    d=dx**2 + dy**2
    d=d**0.5

    if r1>=r2+d:
        return 'RICO'
    else:
        return 'MORTO'

test=[[6,-8,2,3,0,0],[7,3,4,2,4,5],[3,0,0,4,0,0],[5,4,7,1,8,7]]
for t in test:
    a1=t[0]
    a2=t[1]
    a3=t[2]
    a4=t[3]
    a5=t[4]
    a6=t[5]
    print(solution(a1,a2,a3,a4,a5,a6))