import os
def he(a):
    b=0
    for i in range(1000) :
        b=b+a%10
        a=int(a/10)
        if a <= 0:
        	break
    return b

a=input()
tyt=he(a)
print(tyt)