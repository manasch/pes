def get_ans(n, ele):
    maximum = max(ele)
    temp = [maximum - x for x in ele]
    
    odd, even = [], []
    for i in range(0, len(temp)):
        if i % 2:
            even.append(temp[i])
        else:
            odd.append(temp[i])
    
    res = max(even) + max(odd)
    return res

if __name__ == '__main__':
    n = int(input().strip())

    elements = list(map(int, input().rstrip().split()))
    ans = get_ans(n, elements)
    print(ans)