import os

a=os.getcwd()

for e in os.listdir(a):
    m=''
    m=a+'/'+e
    print(os.stat(m))

m+='aaaaaa'

print(os.stat(m))
