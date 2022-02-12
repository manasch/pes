# Python Lab 3

'''import random as r
'''
# 1
'''
# To input principal, rate of interest and time
p=int(input("Enter the principal amount: "))
r=float(input("Enter the rate of interest: "))
t=int(input("Enter the time: "))
# Formula to calculate SI
si=(p*r*t)/100
# Print the answer
print("The simple interest is:",si)
'''

# 2
'''
print("Enter your name, roll number and field of interest\n")

name=input("Name: ")
rno=int(input("Roll No.: "))
fint=input("Field of Interest: ")
print("My name is", name ,"and my roll number is" ,rno,". My field of interest is",fint)
'''

# 3

'''r=float(input("Enter the radius of the sphere: "))
print("The volume of the sphere is: ",4/3*3.14*r**3)
print("The surface area of the sphere is: ",4*3.14*r**2)
'''

# 4

'''m1=float(input("Enter the mass of the first object(in KG): "))
m2=float(input("Enter the mass of the second object(in KG): "))
r=float(input("Enter the distance between them(in M): "))
print("The gravitational force between the two objects is: ",(m1*m2/r**2)*6.67*(10**-11),"N")'''


# 5

'''c1=input("Enter the 1st Character: ")
c2=input("Enter the 2nd Character: ")
c3=input("Enter the 3rd Character: ")
c4=input("Enter the 4th Character: ")
print(chr(ord(c1)+1), chr(ord(c2)+1) , chr(ord(c3)+1) , chr(ord(c4)+1))'''


# 6
'''
x=int(input("Enter the first number: "))
y=int(input("Enter the second number: "))
print("The numbers before exchanging:",x,y)
x=x^y
y=x^y
x=y^x
print("The numbers after exchanging:",x,y)
'''

# 7
'''
print("Cover price of a book is $24.95")
cp=24.95
dp=0.6*cp # dp = discount price
n=60
total_cost=(dp*n)+3+(n-1)*0.75
print("The totoal cost is:",total_cost)
'''

# 8
'''
print("Time at which he began running: 6:52 AM")
h1=6 
m1=52
# Calculating the amount of time he ran - 2 miles at 8 min 15 sec per mile and 3 miles at 7 min 12 sec per mile
t=(2*(60*8+15)+3*(60*7+12))/60
print("Time ran:",t,"min")

if m1+t>60 or m1+t==60: # if the hour changes
    m1=t-(60%m1)
    h1+=1
else:
    m1=m1+t # if the hour does not change

print("The person reaches home at: ",h1,":",m1," AM",sep='')
'''

# 9

'''a = int(input("Enter a number: "))

if a%2 == 0:
    print("The entered number in binary is: ",bin(a))
    print("Nothing to clear")
else:
    print("The entered number in binary is: ",bin(a))
    res=a&(a-1)
    print("Result is ",res,bin(res))'''


# 10

# A
'''s1=input("Enter a string: ")
print("Random character from",s1,r.choice(s1))'''

# B

'''a=[1,2,3,4,5,6,7,8,9,10]
print("Original order of the class: ",a)
r.shuffle(a)
print("Order after shuffling the class: ",a)
print("Class representative: ",r.choice(a))
print("Randomly chosen event coordinators: ",r.sample(a,2))'''

# C

'''n1 = r.random()
n2 = r.random()
print("n1 =",n1,"\nn2 =",n2)
print("Result of the multiplication of random float numbers: ",n1*n2)'''


# D

'''ll=int(input("Enter the lower limit: "))
ul=int(input("Enter the upper limit: "))
if ul>=ll:
    print("Random floating-point number from the range: ",r.uniform(ll,ul))
else:
    print("invalid range")'''


# E

'''ll=int(input("Enter the lower limit: "))
ul=int(input("Enter the upper limit: "))
if ul>=ll:
    print("Random integer number from the range: ",r.randint(ll,ul))
else:
    print("invalid range")'''


# F

'''r.seed(2) # Setting the seed
n1=r.random() # Generating a random number
print("Printing a random number 1st time: ",n1)
r.seed(2)
n2=r.random() # Generating another random number
print("Printing a random number 2nd time: ",n2)
'''

# G

'''dice = [1,2,3,4,5,6]
r.seed(10)
print("First roll: ",r.choice(dice))
r.seed(10)
print("Second Roll: ",r.choice(dice))
'''
# 4

'''a = int(input("Enter the 1st number: "))
b = int(input("Enter the 2nd number: "))
print("Before Exchange: ", a, b)
a = a^b
b = a^b
a = b^a
print("Exchanged values: ", a, b)'''

# 7

'''v=float(input("Enter wind speed in Km/hr: "))
t=float(input("Enter temperature in Celsius: "))
print("Wind Chill Index: ",float((round(13.12+0.6125*t-11.37*(v**0.16)+0.3965*t*(v**0.16),2))))'''

'''r=float(input("Enter angle in radians: "))
print(r,"in degrees:",r*(180/3.14))'''

'''from math import radians,sin,cos,acos
a1=radians(float(input(("Enter latitude of point 1: "))))
b1=radians(float(input(("Enter longitude of point 1: "))))
a2=radians(float(input(("Enter latitude of point 2: "))))
b2=radians(float(input(("Enter longitude of point 2: "))))
print("The distance in Km is: ",float(round(6371.01*acos(sin(a1)*sin(a2)+cos(a1)*cos(a2)*cos(b1-b2)),2)))'''

import math

n=-4.3
print("Initial number:",n)
print("Rounded off value:",round(n),"\nAbsolute value:",abs(round(n)))
print("\nCeil of Sin(34.5):",math.ceil(math.sin(34.5)))
print("\nFloor of -2.8:",math.floor(-2.8))