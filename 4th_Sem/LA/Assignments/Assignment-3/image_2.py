import matplotlib.pyplot as plt
import numpy as np
import string

img = plt.imread('pic.png')
width, height, _ = img.shape
T_s = np.array([[2, 0, 0], [0, 2, 0], [0, 0, 1]])
T_r = np.array([[0, 1, 0], [-1, 0, 0], [0, 0, 1]])
T = T_s @ T_r

img_transformed = np.empty((width * 2, height * 2, 4))

for i, row in enumerate(img):
    for j, col in enumerate(row):
        pixel_data = img[i, j, :]
        input_coords = np.array([i, j, 1])
        i_out, j_out, _ = T @ input_coords
        img_transformed[i_out, j_out, :] = pixel_data

plt.figure(figsize=(5, 5))
plt.imshow(img_transformed)
plt.show()

