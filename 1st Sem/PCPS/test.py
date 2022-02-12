'''s ='we love python very much'
for i in s.split():
    print(i[1:],end='')
    print(i[0],end=' ')
print()
for i in range(len(s)):
    print(s[i],"p",sep='',end='')'''
'''
l=[(10,2),(4,3),(12,4)]
print(list(filter(lambda x:x if x[0]%x[1]==0 else None,l)))'''

def filt(fn,itr):
    res=[]
    for i in itr:
        if fn(itr):
            res.append(i)
    return res

st=['12GB','RAM','256GB','HDD']
print(list(filt(lambda i:i if i[0].isdigit()==False else None),st)))
