'''l=['pani puri','dosa','bhel puri','masala dosa','dahi puri','rava dosa','pizza topings','pizza mania']
piz,pur,dos=[],[],[]
print("Original list: ",l)
for i in l:
    if i.startswith('pizza'):
        piz.append(i)
    elif i.endswith('puri'):
        pur.append(i)
    elif i.endswith('dosa'):
        dos.append(i)
print("Pizza: ",piz)
print("Puri: ",pur)
print("Dosa: ",dos)'''

'''s=input("Enter a string: ")
b=''
s=s.split('.')
for i in s:
    print(''.join(i))'''

'''mac=['00','11','23','45','67','70']
print(":".join(mac))'''

'''f=[]
n=int(input("Enter the number of friends: "))
for i in range(n):
    t=input("Enter name: ")
    t=t.title()
    f.append(t)

print(" Merry Christmas!,".join(f)," Merry Christmas!")'''

'''srn="PE101 PE102 PE103 PE104 PE105 PE106"
print("SRN before replacing: ",srn)
srn=srn.replace("PE","PES",3)
print("SRN after replacing: ",srn)
f=input("Enter the SRN to be found: ")

if f.upper() in srn:
    print("Found")
else:
    print("Not Found")'''

#3
'''cap_list=['Kohli','Dhoni','Rohit']
team_list=['RCB','CSK','MI']
print("Captains: ",cap_list)
print("Teams: ",team_list)
a=zip(cap_list,team_list)
print(list(a))'''

'''score,a = [("a", 85), ("b", 80), ("c",95), ('d',90), ('e',87)],[]
print("List of names and marks: ",score)
for i in score:
    a.append(i[0])
print("List of names only: ",a)
'''

# 4

'''l="mohanDas Karamchand gandhi"
l1=[]
a=l.split()
for i in a[:-1]:
    print (i[0],end=' ')
    l1.append(i[0])
print(a[-1])
l1.append(a[-1])
l1=" ".join(l1)
print(l1.title())
print(l1.upper())
print(l.title())'''

'''s = "bad python bad teacher bad lecture"
print("Initial string: ",s)
print(s.replace("bad","good"))
print(s.replace("bad","good",1))
a=s.find("bad")
print("Leftmost bad: ",a)
print("Secondmost bad: ",s.find("bad",a+1,-1))
r=s.replace('bad','worst',2)
r=r.replace('worst','bad',1)
print(r)
print(r[r.find('worst'):])'''

''''a="pen pinapple apple pen"
print("Initial string: ",a)
for i in a.split():
    print(i[1:],end='')
    print(i[0],end=' ')
print()
for i in range(len(a)-1):
    print(a[i],'p',sep='',end='')''''
