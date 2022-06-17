import matplotlib.pyplot as plt
import numpy as np
import string

T_s = np.array([[2, 0, 0], [0, 2, 0], [0, 0, 1]])

def plot_box(plt, x0, y0, txt, w=1, h=1):
    plt.scatter(x0, y0)
    plt.scatter(x0, y0 + h)
    plt.scatter(x0 + w, y0 + h)
    plt.scatter(x0 + w, y0)
    plt.plot([x0, x0, x0 + w, x0 + w, x0], [y0, y0 + h, y0 + h, y0, y0], color="gray", linestyle='dotted')
    plt.text(x0 + (.33 * w), y0 + (.5 * h), txt)

#             x0, y0, letter
a = np.array((0,  1,  0))
b = np.array((1,  1,  1))
c = np.array((0,  0,  2))
d = np.array((1,  0,  3))

A = np.array([a, b, c, d])
fig = plt.figure()
ax = plt.gca()
for pt in A:
    xt, yt, i = T_s @ pt
    xt, yt, i = int(xt), int(yt), int(i)
    plot_box(plt, xt, yt, f"{string.ascii_letters[i]}' ({xt}, {yt})")

delta_w, delta_h = 0.33, 0.5
plt.text(0 + delta_w, 1 + delta_h, "? (0, 1)")
plt.text(1 + delta_w, 0 + delta_h, "? (1, 0)")
plt.text(1 + delta_w, 1 + delta_h, "? (1, 1)")
plt.text(1 + delta_w, 2 + delta_h, "? (1, 2)")
plt.text(2 + delta_w, 1 + delta_h, "? (2, 1)")

ax.set_xticks(np.arange(-1, 5, 1))
ax.set_yticks(np.arange(-1, 5, 1))
plt.grid()
plt.show()
