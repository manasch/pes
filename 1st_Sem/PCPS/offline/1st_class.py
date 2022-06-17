# programs on functions, recursion, callbacks

# 1) using functions generate prime numbers using sleve of erathosthenes
# 2) a) Reverse the given string using recursion 
#    b) Use recursion to raise a number to given power of n
# 3) Use callback to find sum, double and triple the given number
# 4) Increment a given a number by 5 for n number of times using closure
# 5) Find nth root of a given number by closure

#2 a

'''s=input("Enter a string: ")

def rev(st):
    if st[:-1] > "":
        return st[-1] + rev(st[:-1])
    else:
        return st

print(rev(s))'''


#2 b
'''
n = int(input("Enter the base: "))
p = int(input("Enter the power: "))

def power(n,p):
    if p>0:
        return(n*power(n,p-1))
    else:
        return 1

print(power(n,p))'''


# 1

'''n=int(input("Enter a number: "))
def prim(n):
    pn=[]
    for i in range(2,n+1):
        if i not in pn:
            print(i,end=" ")
            for j in range(i*i,n+1,i):
                pn.append(j)
prim(n)'''


# 3
'''
def h(n,s,d,a):
    if n==1:
        print('move disk ',n,'from ',s,' to ',d)
        return
    h(n-1,s,a,d)
    print('move disk ',n,' from ',s,' to ',d)
    h(n-1,a,d,s)
num=int(input("Enter number of disks"))
h(num,'source','destination','auxillary')'''

'''
# Recursive Python function to solve the tower of hanoi 
  
def TowerOfHanoi(n , source, destination, auxiliary): 
    if n==1: 
        print ("Move disk 1 from source",source,"to destination",destination)
        return
    TowerOfHanoi(n-1, source, auxiliary, destination) 
    print("Move disk",n,"from source",source,"to destination",destination)
    TowerOfHanoi(n-1, auxiliary, destination, source) 
          
# Driver code 
n = 20
TowerOfHanoi(n,'A','B','C')  
# A, C, B are the name of rods'''

'''def sn(n):
    if(n==0):
        return 0
    else:
        return n+sn(n-1)
i=0
def d(n):
    global i
    if(i==2):
        i=0
        return 0
    else:
        i+=1
        return n+d(n)
def t(n):
    global i
    if(i==3):
        return 0
    else:
        return n+d(n)
x=int(input("Enter a number"))
print("Sum of numbers till ",x," is ",sn(x))
print("Double of ",x," is ",d(x))
print("Triple of ",x," is ",t(x))'''

'''def counter():
    count=0
    def inc():
        nonlocal count
        count+=5
        return count
    return inc

n=int(input("enter a number: "))
c=counter()
for i in range(n):
    print(c())'''

'''
def np(x,p):
    def fn():
        return x**(1/p)
    return fn
b=int(input("enter the number: "))
a=int(input("enter the root of the number that has to be found: "))
c=np(b,a)
print(c())'''

'''def fib(n):
    if n == 0:
        return 0
    elif n==1:
        return 1
    else:
        return fib(n-2) + fib(n-1)

def call(f):
    def fibc(n):
        return f(n)
    return fibc

x=call(fib)
n=int(input())
print(x(n))'''