#1 Create a module for accessing students marks calculate.py
# should support sum(list), avg (list), grade_relative(total,highest) import calculate.py in academic.py

def sumu(list):
    return sum(list)

def avgu(list):
    return sum(list)/len(list)

def grade_relative(m, highest):
    if (0.35*highest)==m:
        return "D"
    elif m in range(int(0.36*highest),int(0.5*highest)):
        return "C"
    elif m in range(int(0.51*highest),int(0.8*highest)):
        return "B"
    elif m in range(int(0.81*highest),int(0.9*highest)):
        return "A"
    elif m >= 0.91*highest:
        return "S"


