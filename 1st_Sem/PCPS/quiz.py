class A:
    def __init__(self):
        self.num1 = 0
class B(A):
    def __init__(self):
        self.num2 = 1

obj = B()
print(obj.num1,obj.num2)