import matplotlib.pyplot as plt
import numpy as np
import cv2

img = cv2.imread('pic.png')
width, height, _ = img.shape

# recenter resultant image
T_pos1000 = np.array([
    [1, 0, 1000],
    [0, 1, 1000],
    [0, 0, 1]])
# rotate - opposite angle
T_rotate = np.array([
    [0, -1, 0],
    [1, 0, 0],
    [0, 0, 1]])
# scale
T_scale = np.array([
    [2, 0, 0],
    [0, 2, 0],
    [0, 0, 1]])
# center original to 0,0
T_neg500 = np.array([
    [1, 0, -500],
    [0, 1, -500],
    [0, 0, 1]])
T = T_pos1000 @ T_rotate @ T_scale @ T_neg500

T_opencv = np.float32(T.flatten()[:6].reshape(2, 3))
img_transformed = cv2.warpAffine(img, T_opencv, (width * 2, height * 2))
plt.imshow(cv2.cvtColor(img_transformed, cv2.COLOR_BGR2RGB))
plt.show()
