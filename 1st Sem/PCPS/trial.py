'''
s="PESU EC CAMPUS"
print(s)
s1=s.split()
#print(s1)
for i in range(len(s1)):
    s1[i]=s1[i][::-1]
#print(s1)
for i in s1:
    print(i,end=' ')
'''
'''
def rev(s):
    if(s[-1]==" "):
        return " "
    else:
        return s[-1]+rev(s[:-1])
x=input("Enter a string ")
t=x.split()
for i in t:
    print(rev(" "+i),end="")
'''

def rev(s):
    if(s[-1]==" "):
        return " "
    else:
        return s[-1]+rev(s[:-1])
        
x=input("Enter a string ")
t=x.split()
for i in range(len(t)):
    print(rev(" "+i),end="")