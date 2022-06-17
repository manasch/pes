# 1

'''a,b=0,1
n=int(input("Enter the number of terms to be found: "))
if n<0 or n==0:
    print("Invalid number of terms")
else:
    for i in range(1,n+1):
        print(a,end=" ")
        a,b=b,a+b
        i+=1'''

'''n=int(input("Enter a number: "))
fact=1
if n<0:
    print("Invalid number")
elif n==0:
    print(fact)
else:
    for i in range(2,n+1):
        fact*=i
        i+=1    
    print(fact)'''

'''n=int(input("Enter a number till which primes are to be found: "))
#num=2
for num in range(2,n+1):
    if num>1:
        for i in range(2,num):
            if num%i==0:
                break
        else:
            print(num,end=" ")'''

#2

'''l=eval(input("Enter a list: "))
s,i,f,b=[],[],[],[]
for a in l:
    if type(a)==str:
        s.append(a)
    elif type(a)==int:
        i.append(a)
    elif type(a)==bool:
        b.append(a)
    elif type(a)==float:
        f.append(a)
print("Strings: ",s)
print("Integers: ",i)
print("Boolean: ",b)
print("Floating: ",f)'''

'''l=["apple","dog","cow","ball"]
l1=[92,1,5,3,2,68]
print("list of strings and numbers: ",l,l1)
l.sort()
print("Acsending order of list of strings: ",l)
l.sort(reverse=True)
print("Descending order of list of strings: ",l)
l1.sort()
print("Acsending order of list of numbers: ",l1)
l1.sort(reverse=True)
print("Descending order of list of numbers: ",l1)'''

'''import random as r

h_rate,b,t=[],0,0
for i in range(0,25,3):
    h=r.randint(50,120)
    print(h,end=" ")
    h_rate.append(h)
    if 50<=h<=65:
        print("Bradycardia")
        b+=1
    elif h>100:
        print("Tachycardia")
        t+=1
    else:
        print("Normal")
if b>3 or t>3:
    print("At Risk")
else:
    print("Not at Risk")
print("Max heart rate: ",max(h_rate),"\nMin heart rate: ",min(h_rate))'''

'''m,i=[],1
while i==1:
    n=int(input("Enter the marks: "))
    m.append(n)
    i=int(input("Enter 1 to continue or 0 to stop: "))

print("Highest marks scored: ",max(m))
print("Number of students who got the highest marks: ",m.count(max(m)))
m.sort(reverse=True)
print("Second highest marks: ",m[m.count(max(m))])
f=int(input("Enter the fail marks: "))
for i in range(len(m)):
    if m[-1]<=f:
        m.pop(-1)
print("Students with pass marks: ",m)'''

'''n=input("Enter comma separated values: ")
a=n.split(',')# splitting by comma
print(a,type(a))
a=tuple(a)# converting list to tuple
print(a,type(a))'''

# 1 c

n=int(input("Enter a number: "))
for i in range(2,n+1): 
  if i>1: 
    for j in range(2,i): 
        if(i % j==0): 
            break
    else: 
        print(i,end=' ')