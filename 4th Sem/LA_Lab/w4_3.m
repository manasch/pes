syms c
P = [2, 1, 0] + c * [1, 1, -1]
s = 1 * (c + 2) + 1 * (c + 1) - (-c) == 0
s1 = solve(s, c)
p = [2, 1, 0] + s1 * [1, 1, -1]