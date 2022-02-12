
# ISA 2
'''
n=int(input("Enter a number: "))
print(list(range(n,n*10+1,n)))
'''
'''
a=["apple","ball","cat"]
print(list(map(str.upper,a)))
'''
'''import functools
def fact(x,y):
    return x*y
n=int(input("Enter the number: "))
print(functools.reduce(int.__mul__,list(range(1,n+1))))'''

'''import functools
a=input("Enter a number: ")
print(functools.reduce(lambda x,y:x+y,map(int,a))) # or print(functools.reduce(int.__add__,(map(int,a)))
'''
'''
a=[1,2,3,4]
b=[2,3,4,5,6]
c=zip()
print(type(c))
c=zip(a,b)
print(list(c))
'''
'''
n=[1,2,3,4]
print(list(map(lambda x:x+x,filter(lambda x:x>2,n))))'''

#import e_prep

'''import math
print(math.__doc__)'''

'''import pytest

def testmethod1():
    x=2
    y=3
    assert x+1==y, "passed"
    assert x==y, "failed"

def testmethod2():
    x=5
    y=6
    assert x+1==y, "Passed "
'''

'''
class A:
    a=20
    #print("this is in class a")
class B(A):
    print("this is in class b")
    #print(A.a)
a=A()
b=B()
print(B.a)
'''
'''
class Shape:
    def area(self):
        self.area=0
        return self.area

class Square(Shape):
    def __init__(self,l):
        self.length=l
    def area(self):
        return self.length**2

aSquare=Square(3)
print(aSquare.area())
aShape=Shape()
print(aShape.area())
'''
'''class c1:
    def __init__(self,num):
        self.num=num
        print("INit")
    def __str__(self):
        return str(self.num)
    
c=c1(10)
print(c)
'''
'''
class mydate:
    def __init__(self,dd,mm,yy):
        self.dd=dd
        self.mm=mm
        self.yy=yy
    def __str__(self):
        return str(self.dd) + "-" + str(self.mm) + "-" + str(self.yy)
    
class event:
    def __init__(self,dd,mm,yy,detail):
        self.date=mydate(dd,mm,yy)
        self.detail=detail
    def __str__(self):
        return str(self.date) + "------>" + str(self.detail)

e=event(16,6,2002,"BDAY")
print(e)
'''

# Iter functions
'''
x=iter([1,2,3,4,5,6])
for i in range(7):
    print(next(x))'''


# Exceptions

'''try:
    print(5)
    print(5/0)
except ZeroDivisionError as e:
    print(e)
except:
    print("ZeroDivisionError")
finally:
    print("end")'''


class exc(Exception):
    def __init__(self,msg):
        self.msg=msg
    def __Str__(self):
        return self.msg
n=int(input("Enter a number: "))
try:
    if not 1<=n<=100:
        raise exc("OutOfRange")
    else:
        print("no error")
except exc as e:
    print(e)