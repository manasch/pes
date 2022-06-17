# output should be like
'''
1
22
333
4444
55555
'''
'''
for i in range(1,6):
    print(i*str(i))
'''

'''
for i in range(1,6):
    for j in range(1,i+1):
        print(i,end='')
    print()
'''


'''
Output
1
12
123
1234
12345
'''
'''
for i in range(1,6):
    for j in range(1,i+1):
        print(j,end='')
    print()
'''

'''
Output to be
100
010
001

'''
'''
m=n=3
for i in range(m):
    for j in range(n):
        if i==j:
            print(1,end='')
        else:
            print(0,end='')
    print()
    
'''
