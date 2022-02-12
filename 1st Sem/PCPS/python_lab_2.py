#Python Lab 2

#1
'''
# Taking the name and age input
name = input("Enter your name: ")
age = int(input("Enter your age: "))
# Subtracting the age from the current year and then adding 100 to get the final year
year = 2021 - age + 100
print(name + " will turn 100 in the year",year)
'''

#2
'''
# Taling the input of number of students and apples
n = int(input("Enter the number of students: "))
k = int(input("Enter the number of apples: "))
get = k//n
rem = k%n
# Prints the number of apples each student gets
print ("Each student will get",get,"apples")
# Prints the number of apples that will be remaining in the box
print (rem,"apples will be remaining inside the basket")
'''

#3
'''
# Input both X values and Y values
x1 = int(input("Enter the value of X1: "))
y1 = int(input("Enter the value of y1: "))
x2 = int(input("Enter the value of x2: "))
y2 = int(input("Enter the value of Y2: "))
# Calculate distance using the formula
d = ((x2-x1)**2 + (y2-y1)**2)**0.5
# Print the distance between the two points
print("The distance between the two points is",d)
'''

#4
'''
# Input the hour, minute and seconds for both the timestamps
h1 = int(input("Enter the hour for the first timestamp: "))
m1 = int(input("Enter the minute for the first timestamp: "))
s1 = int(input("Enter the seconds for the first timestamp: "))
h2 = int(input("Enter the hour for the second timestamp: "))
m2 = int(input("Enter the minute for the second timestamp: "))
s2 = int(input("Enter the seconds for the second timestamp: "))
# Converting all of them to seconds and finding the difference
result = (h2 - h1)*3600 + (m2 - m1)*60 + (s2 - s1)
# Printing the result
print("The difference between the two timestamps in seconds is:",result)
'''

#7
'''
# To input temperature in celsius
tc1 = float(input("Enter the temperature in celsius: "))
tf1 = 32 + (9*tc1)/5
# Print the temperature in fahrenheit
print("The temperature in fahrenheit is",tf1)
# To input the temperature in fahrenheit
tf2 = float(input("Enter the temperature in fahrenheit: "))
tc2 = 5/9*(tf2-32)
# Print the temperature in celsius
print("The temperature in celsius is",tc2)
'''

#8
'''
# Input distance 
dist = float(input("Enter the distance between 2 cities in KM: "))
# Converting to the required measure 
meter = dist*1000
c_meter = meter*100
feet = meter*3.28
inch = meter*39.37
# Printing the result
print("The distance in meters:",meter)
print("The distance in centimeters:",c_meter)
print("The distance in feet:",feet)
print("The distance in inches:",inch)
'''

#6
'''
# Input the content into two variables
a = input("Enter first content (a): ")
b = input("Enter second content (b): ")

# Using temporary variable
temp = a
a = b
b = temp
print("a =",a,"\nb =",b)

# Without using temporary variable
#a,b = b,a
#print("a =",a,"\nb =",b)
'''

#5
'''
# Input a 4 digit number
Num = int(input("Enter a 4 digit number: "))
# Getting reminder and then dividing the number by 10 to remove the last digit
a = Num%10
Num = Num//10
b = Num%10
Num = Num//10
c = Num%10
Num = Num//10
d = Num%10
Num = Num//10

s = a + b + c + d
# Print the result
print("The individual digits are",d,c,b,a,"and the sum is",s)
'''

#9
'''
# Input the number of students in each class
a = int(input("Enter the number of students is class A: "))
b = int(input("Enter the number of students is class B: "))
c = int(input("Enter the number of students is class C: "))

# This calculates the number of desks required
no_desks = a//2 + a%2 + b//2 + b%2 + c//2 + c%2
# Print the result
print("The number of desks required: ",no_desks)
'''

#10
'''
# Input the number of seconds passed since midnight
N = int(input("The number of seconds that has passed since midnight: "))
# H is the number of hours that has passed
H = N//3600
# M is the number of minutes that has passed
M = N//60
# Print the output
print(H,"full hour(s) has passed since midnight,",M,"full minute(s) has passed since midnight")
'''