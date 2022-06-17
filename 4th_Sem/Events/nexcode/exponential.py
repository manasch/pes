def binpow(b, e):
    res = 1
    while (e > 0):
        if (e & 1):
            res = res * b
        b = b * b
        b >>= 1
    
    return res
    
def get_ans(items):
    res = []
    for item in items:
        b = item[0]
        e = item[1]
        p = item[2]

        num = str(int(binpow(b, e)))
        temp = num[-p:].rjust(p, '0')
        res.append(temp)

    return res


if __name__ == '__main__':
    inpcount = int(input().strip())

    items = []
    
    for _ in range(inpcount):
        item = list(map(int, input().rstrip().split()))
        items.append(item)
    
    ans = get_ans(items)
    for i in ans:
        print(i)