''' The replace() method returns a copy of the string where all occurrences of a 
substring is replaced with another substring.

str.replace(old, new [, count]) 

count is optional.
 If not specified, the replace() method replaces all occurrences of the old substring with 
the new substring.

Ex 1: '''

a="this is python replace"
print(a.replace('this','This'))

#output:
#C:\Users\Chitra GM\Desktop>Python pgm.py
#This is python replace

#Note: the original string remains same.

#Ex 2:

a="this is python programming and python string replace"
print(a.replace('p','P'))

#output:
#C:\Users\Chitra GM\Desktop>Python pgm.py
#this is Python Programming and Python string rePlace


#Ex 3:

a="this is python programming and python string replace"
print(a.replace('p','P',3))

#count : the number of times you want to replace the old substring with the new substring
#in this case 3 times 'p' is replaced with 'P'.
#output
#C:\Users\Chitra GM\Desktop>Python pgm.py
#this is Python Programming and Python string replace



#Write a Python Program to Check whether a  given number is an Armstrong Number or not.

       
#Armstrong number of 3 digits, the sum of cubes of each digits is equal to the number itself. For example:
#153 = 1*1*1 + 5*5*5 + 3*3*3  // 153 is an Armstrong number.

num = int(input("Enter a number: "))
# initialize sum
sum = 0
# find the sum of the cube of each digit
temp = num
while temp > 0:
          digit = temp % 10
          sum += digit ** 3
          temp //= 10
       
# display the result
if num == sum:
          print(num,"is an Armstrong number")
else:
          print(num,"is not an Armstrong number")


#find GCD using Euclid's method
'''
def gcd(x,y):
	while y!=0:
		#temp = x
		#x = y
		#y = temp%y
		x,y = y , x%y
		print(x,y)
	return x
	
print(gcd(91,65))
'''
