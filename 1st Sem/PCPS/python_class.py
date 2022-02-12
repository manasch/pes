# 18/01/21
# Remove an element from a set which are multiples of 2
import sys


'''
s1={1,2,3,4,5,6,7,8,9,10}
for i in range(2,11,2):
    s1.remove(i)

print(s1)
'''
# This doesn't work because 
'''
s={1,2,3,4,5,6,7,8,9,10}
for i in s:
    if i%2==0:
        s.remove(i)
'''

# 19/01/21

# Create a dictionary which contains the squares of the numbers from 1 to 10
'''
i=1
d={}
for i in range(1,11):
    d[i]=i*i*i

print(d)
'''


#Files
#input()
#Command line arguements
#import system
'''
print("Enter the values")
print(sys.argv[1],sys.argv[2])
x=int(sys.argv[1])
y=int(sys.argv[2])
print("Sum: ", x+y)
'''
#python name.py 20 30

# 21/01/21

# Find the number of times the word "python" is present in a.txt 
'''
f=open("a.txt",'r')
rd=f.readlines()
f.close()
count = 0 
for i in rd:
    i=i.strip()
    count+=i.count("python")
print(count)
'''

# 25/01/21

# Given two strings, find the common letters present and print it
'''
def f_com(s1,s2):
    set1=set(s1)
    set2=set(s2)
    res=""
    for i in set1&set2:
        res+=i
    return res

s1="cat"
s2="concat"
print("the common letter are:",f_com(s1,s2))
'''

# Input --> "python reutrn mechanism" output --> Length of every word
# reverse all the word in a given sentence
'''
s1=input("Enter a sentence: ")
def s_len(s):
    wlist=s.split()
    print(wlist)
    for i in wlist:
        print(len(i),end=' ')
    print()


s_len(s1)
'''
'''
s1=input("Enter a sentence: ")
def s_rev(s):
    ns=s.split()
    print(ns)
    for i in ns:
        print(i[::-1],end=' ')

s_rev(s1)
'''

