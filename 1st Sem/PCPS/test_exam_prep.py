'''
num = int(input("Enter a number: "))
sum = 0
temp=num
while temp>0:
    digit=temp%10
    sum+=digit**3
    temp//=10

if num == sum:
    print(num,"is an Armstrong number")
else:
    print(num,"is not an Armstrong number")
'''
'''
i=1
while i<1000:    

    sum = 0
    temp=i
    while temp>0:
        digit=temp%10
        sum+=digit**3
        temp//=10

    if i == sum:
        print(i,"is an Armstrong number")
    else:
        print()
    i+=1
'''
'''
Output
A
BCD
EFGHI
JKLMNOP
QRSTUVW

x,y=0,1
for i in range(ord('A'),ord('Z')):
    x+=1
    print(chr(i),end='')
    if x==y**2:
        print()
        y+=1
'''
'''
a=[1,1,1,1,1,2,3,3,4,4,5,3,6,6,7,8]
b=[]
for i in range(len(a)):
	if a[i] not in b:
		b.append(a[i])
print(b)
'''
'''
d="python programming"
for i in d:
    print(i,end='p')
'''
'''
f=open("a.txt",'r')
rdln=f.readlines()
print(rdln)
for i in range(len(rdln)):
    rdln[i]=rdln[i].strip()
print(rdln)

f.close()
'''

'''
def outer():
    x = 10 #local
    print ("within outer x:",x)
    def inner():
        nonlocal x
        x = 20 #x from outer funtion
        print("within inner x:",x)
    inner()
x = 5 #global
print("Before outerx:",x)
outer()
print("After outer x:",x)
'''
'''
inc=1
val=65
for i in range(0,5):
    for j in range(0,inc):
        ch=chr(val)
        print(ch,end='')
        val+=1
    inc+=2
    print()
'''
'''
def inc(x):
    return x+1

def dec(x):
    return x-1

def opertaion(func,x):
    result=func(x)

    return result

print(opertaion(dec,10))
'''
'''
def fun_called():
    def fun_returned():
        print("is it confusing?")
    return fun_returned

new=fun_called()
new()
'''
'''
def make_pre(func):
    def inner():
        print("I look nice after decoration")
        func()
    return inner

def ordinary():
    print("I look very simple")

pre=make_pre(ordinary)
pre()
'''

'''
from tkinter import *

root = Tk()

lb1 = Label(root,text="first",fg="blue")
lb1.grid(column=0,row=10)

e= Entry(root,text="Enter your name")
e.grid()

def onclick():
    name=e.get()
    lb2=Label(root,text=f"{name} has submitted the form")
    lb2.grid()

bt1=Button(root,text="click here",command=onclick)
bt1.grid()
bt1.grid()
root.mainloop()
'''