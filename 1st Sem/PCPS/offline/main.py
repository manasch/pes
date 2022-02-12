'''from calculate import *

l1=[10,12,13,14,15,16,17]
print(sumu(l1))
print(avgu(l1))

name=input("student name: ")
marks=int(input("Enter marks: "))
print(calculate.grade_relative(marks,max(l1)))'''

#2 by using list comprehension

'''a) Write a program to print list after removing the value 25 in [10,25,35,45,55,65,75,85,95]
b) write a program to print the list after removing 0th,6th,7th numbers in l=[10,25,35,45,55,65,75,85,95]
ans: r=[x for x in range(len(l)) if x!=0 and x!=6 and x!=7]
c) find all numbers which are odd and which are palindromes between a pair of numbers 20 and 100
'''
# 2a
'''
l=[10,25,35,45,55,65,75,85,95]

print(list((x for x in l if x!= 25)))
print(list(l[x] for x in range(len(l)) if x not in (0,6,7))) # !=0,6,7
print(list(x for x in range(20,101) if x%2!=0 and str(x)==str(x)[::-1]))
'''
'''Create a list of numbers and list of strings , combine two lists to make a list of tuples'''
'''l1=[1,2,3]
l2=['pes','mech','1styear']
a=[i for i in zip(l1,l2)]
print(a)'''


'''f) generate a list of prime number berween a given range'''

'''a=[j for i in range(2,8) for j in range (i*i,50,i)]
prime=[x for x in range(2,8) if x not in a]
print(prime)'''

'''write a code to determine the maximum element in a given list containing values using reduce'''

'''from functools import reduce
f=lambda a,b: a if a>b else b
print(reduce(f,[1,2,3,45]))'''

'''mimic a reduce function to concatenate given list of strings'''
''' i/p : l=['p','e','s']
o/p: pes'''

'''
Indian_enter=('swathiPiramal','EkthaKapoor','mallikasrinivasan','Ashwini','FalguniNayar')
Company=('Piramal Enterprises','Balajitelifilms','Amalgametionsgroup','Mad Street Den','Nykaa')

print(list((Indian_enter[i],Company[i]) for i in range(len(Indian_enter))))
'''
'''
from functools import reduce
l=['p','e','s']
print(reduce(lambda x,y:x+y,l ))


def myreduce(func,list):
'''
    

#N = ["Abrham Lincoln", "Barrack Obama"]

#print(list(x for x.split() in N))

'''for i in N:
    x = i.find(" ")
    print(i[0], i[x+1],sep="")
'''


#n=10
#print(list(((n for n in range(5,n+1)))))
#print(list(x for n in range(5,n+1) for x in range(1,n+1) if n%x == 0))
#print(list(x for x in range(1,6) if 5%x == 0))

#n=10
#print(list((n,[x for x in range(1,n+1) if n%x == 0]) for n in range(5,n+1)))

#names = ['Abe Lincoln','Barrack Obama','Mahatma Gandhi','Jawaharlal Nehru']

#print(list((n.split()[0][0] + n.split()[1][0]) for n in names))
#print(list(x[0]+x[x.find(" ")+1] for x in names))

'''n = "MALAYALAM"
print(n[::-1])
if n == n[::-1]:
    print("is a palindrome")
else:
    print("not a palindrome")'''

'''
n="apple ball cat"

print(n.center(25))

txt = "H\te\tl\tl\to"

x =  txt.expandtabs(5)

print(x)'''
'''
txt = "For only {price:g} dollars!"
print(txt.format(price = 49))
'''

# mimic reduce function
'''
def red(func, itr, i = None):
    if i == None:
        res = itr[0]
        for x in itr[1:]:
            res = func(res,x)
    else:
        res = i
        for x in itr:
            res = func(res,x)
    return res

l=[1,2,3,4,5,6,7]
print(red(lambda x,y: x*y,l))'''

'''a=ord('a')
for i in range(3):
    for j in range(3):
        print(chr(a),end=" ")
        a+=1
    print()'''
'''
s = "Good Weather Good People Good Food"
f=s.index("Good")
s1=f+len("Good") + s[f + len("Good"):].index("Good")
t = s1 + len("Good") + s[s1 + len("Good"):].index("Good")
print(t)''' 


'''
s=s.split()
s[4]="Bad"
print(" ".join(s))
'''
'''d = {'w':1,'f':3,'e':5}
print(d)

d['g']=9
print(d.get('w'))
'''
'''
a = {1,1,1,1,1,2,8,3,43,43,43,43,43}
print("L did you know, \"Shinigami\" Love apples")'''

'''
f = open("a.txt","r")
fd = f.readlines()
for i in range(len(fd)):
    fd[i].strip()
print(fd)
f.close()   '''

'''
def func(a=[],b={}):
    print(a)
    print(b)
    print("*"*6)
    a.append(len(a))
    b[len(a)]=len(a)
func()
func()
func()
func(a=[1,2,3],b={'B':1})
func()'''

'''def outer(msg):
    def inner():
        return msg
    return inner()
a=outer("hello")
del outer
print(a)
'''
'''
def decora(func):
    def inner():
        print("before decoration")
        func()
        print("after decoration")
    return inner

@decora
def func1():
    print("This has been decorated")
func1()'''
'''
n=int(input())
print(list(range(n,n*10+1,n)))'''

'''a = [1,2,3,4,5]
b = [2,3,4,5,6]
print(list(x for x in -a if x in b))'''

'''def my_gen():
 n = 1
 print('This is printed first')
 # Generator function contains yield statements
 yield n
 n += 1
 print('This is printed second')
 yield n
 n += 1
 print('This is printed at last')
 yield n
a = my_gen()

for i in a:
    print(i)
'''

'''class shape:
    def area():
        return 0

class square(shape):
    def __init__(self,length):
        self.l = length
    def area(self):
        return self.l**2
    def __str__(self):
        return str(self.l)
    
s1 = square(4)
print(s1)'''
'''
class act_range:
    def __init__(self,n):
        self.i=0
        self.n=n
    def __iter__(self):
        return self
    def __next__(self):
        if self.i<self.n:
            i = self.i
            self.i+=1
            return i
        else:
            raise StopIteration

print(list(act_range(10)))'''


'''def fn():
    print("one")

call = fn()
print(call)'''

'''
class LoginError(Exception):
    def __init__(self,str):
        self.str=str
    def __str__(self):
        return self.str
Pass = "12345"
u = input("Enter the password")
try:
    if u != Pass:
        raise LoginError("Incorrect Password")
    else:
        print("Login Successfull")
except LoginError as e:
    print(e)
'''

'''try:
    print(10/0)
    raise ZeroDivisionError()
except:
    print("")'''

req = ['4GB','3 0inch','1TB','2 5 6Mbps']

print(1,2 in [1,2,3,4])