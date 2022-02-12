from tkinter import *
'''
root=Tk() # Creates a window
root.geometry("300x300")
lab=Label(root,text="Welcome")
lab.grid(row=0,column=0)

def onclick():
    l=Label(root,text="congrats, you just had fun")
    l.grid(row=50,column=50)


bt1=Button(root,text="Click here for fun",command=onclick,bg="yellow",fg="green")
bt1.grid(row=0,column=20)
root.mainloop() # makes it run for a long time
'''

root=Tk()
root.geometry("300x300")
l=Label(root,text="Enter something scam")
l.pack()
e=Entry(root,width=20)
e.pack()
e.insert(0,"Enter your name")
def myclick():
    msg="hello " + e.get()
    l2=Label(root,text=msg)
    l2.pack()

bt=Button(root,text="Click here",command=myclick,bg="green",fg="red")
bt.pack()
root.mainloop()