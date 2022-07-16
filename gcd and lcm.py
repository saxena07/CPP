from itertools import count
import math
t=int(input())
def fun(n):
    count=0
    a=[]
    w=int(math.sqrt(n))
    for i in range(1,w+1):
        bs=n-i*i
        b=int(math.sqrt(bs))
        if(b*b==bs):
            a.append([i,b])
    c=[]
    b=[]
    for i in a:
        if i not in b:
            c.append(i)
            b.append([i[1],i[0]])
    for i in c:
        p=min(i[0], i[1])
        q=max(i[0],i[1])
        if(i[0]==0 or i[1]==0):
            count+=1
        else:
            for j in range(1, q):
                a=j
                b=a+p
                g=math.gcd(a,b)
                l=(a*b)//g
                if(g+l)==q:
                    count+=2
    return count                

for i in range(t):
    n=int(input())
    if n%2==0:
        print(fun(n))
    else:
        print(0)    