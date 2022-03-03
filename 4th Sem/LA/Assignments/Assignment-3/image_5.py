import matplotlib.pyplot as plt
import numpy as np
import string

img = plt.imread('pic.png')
width, height, _ = img.shape
T_s = np.array([[2, 0, 0], [0, 2, 0], [0, 0, 1]])
T_r = np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 1]])
T = T_s @ T_r
T_inv = np.linalg.inv(T)

# nearest neighbors interpolation
def nearest_neighbors(i, j, M, T_inv):
    x_max, y_max = M.shape[0] - 1, M.shape[1] - 1
    x, y, _ = T_inv @ np.array([i, j, 1])
    if np.floor(x) == x and np.floor(y) == y:
        x, y = int(x), int(y)
        return M[x, y]
    if np.abs(np.floor(x) - x) < np.abs(np.ceil(x) - x):
        x = int(np.floor(x))
    else:
        x = int(np.ceil(x))
    if np.abs(np.floor(y) - y) < np.abs(np.ceil(y) - y):
        y = int(np.floor(y))
    else:
        y = int(np.ceil(y))
    if x > x_max:
        x = x_max
    if y > y_max:
        y = y_max
    return M[x, y,]

img_transformed = np.empty((width * 2, height * 2, 4))

for i, row in enumerate(img):
    for j, col in enumerate(row):
        pixel_data = img[i, j, :]
        input_coords = np.array([i, j, 1])
        i_out, j_out, _ = T @ input_coords
        img_transformed[i_out, j_out, :] = pixel_data

img_nn = np.empty((2000, 2000, 4))
for i, row in enumerate(img_transformed):
    for j, col in enumerate(row):
        img_nn[i, j, :] = nearest_neighbors(i, j, img, T_inv)

plt.figure(figsize=(5, 5))
plt.imshow(img_nn)
plt.show()
