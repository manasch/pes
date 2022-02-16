def get_ans(n, string, ques, index):
    rev = string[::-1]
    join = string + rev

    res = []

    for ind in index:
        rem = ind % len(join)
        res.append(join[rem - 1])
    
    return res



if __name__ == '__main__':
    n = int(input().strip())
    string = str(input().strip())
    ques = int(input().strip())
    index = list(map(int, input().rstrip().split()))

    ans = get_ans(n, string, ques, index)
    for i in ans:
        print(i)