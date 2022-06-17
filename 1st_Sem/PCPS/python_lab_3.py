import random as r

#1 Write a python program to input 4 characters from the user and print out the next letter
'''
i = 0
l = []
l[0] = 87
print(l)
'''





#2 Program to swap the contents of 2 memory locations using bitwise operator (no temp or arithmatic operators)
'''
a = int(input("Enter a: "))
b = int(input("Enter b: "))
print("a before swapping: ",a)
print("b before swapping: ",b)
a=a^b
b=a^b
a=a^b
print("a after swapping: ",a)
print("b after swapping: ",b)
'''

#3 Program to clear rightmost set bit of a number
'''
a = int(input("Enter an even number: "))

if a%2 == 0:
    print("Nothing to clear")
else:
    print("The entered number in binary is: ",bin(a))
    res=a&(a-1)
    print("Result is ",res,bin(res))
    
'''

#4,5 Write a program to perform multiplication of 2 random float numbers (range from 10.5 to 20.5)
'''
n1 = random.random()
n2 = random.random()
print("n1 =",n1,"\nn2 =",n2)
print("Result of the multiplication of random float numbers: ",n1*n2)

print("The range for the numbers is 10.5 to 20.5")
n1 = random.uniform(10.5,20.5)
n2 = random.uniform(10.5,20.5)
print("n1 =",n1,"\nn2 =",n2)
print("Result of the multiplication of random float numbers: ",n1*n2)
'''

#6 Write a program to generate the same random number everytime
'''
random.seed(20)
print(random.randint(10,20))
'''

#7 Roll a dice such that you get the same number everytime
'''
dice = [1,2,3,4,5,6]
r.seed(20)
print(r.choice(dice))
'''

#8 Write a program to 
# 1) Shuffle students in a class
# 2) Choose one student
# 3) Create a random samlple of size 2 and size 4 from available no. of population who are potential candidates to become event coordinators

#9 TO get a random single character from a specific string
'''
s = [1,2,3,4,5,6,7,8,9,10]
r.shuffle(s)
print(s)
print(r.sample(s,2))
print(r.sample(s,4))


p = "python"
print(r.choice(p))
'''
# Not a part of the lab assignment but class
'''
lst = []
i=0
n = int(input("Enter the number of elements: "))
while i<n:
    n1 = int(input("Enter the element: "))
    lst.append(n1)
    i+=1
print("The list contains: ",lst)
'''


