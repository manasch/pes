import math

def add_sum(smallest):
    num = smallest
    s = 0
    while(len(str(num)) > 1):
        while(num != 0):
            s += int((num % 10))
            num = num / 10
        num = s
        s = 0
        if (len(str(num)) == 1):
            break
    return num

def get_ans(items):
    res = []
    smallest = 0
    for item in items:
        smallest = min(item)
        # print(smallest)
        res.append(add_sum(smallest))
    
    return res

if __name__ == '__main__':
    n = int(input().strip())

    items = []
    for _ in range(n):
        item = list(map(int, input().rstrip().split()))
        items.append(item)
    
    ans = get_ans(items)
    for i in ans:
        print(i)