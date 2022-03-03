import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

img = Image.open('pic.png')
width, height = img.size

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
T_inv = np.linalg.inv(T)

img_transformed = img.transform((width * 2, height * 2), Image.Transform.AFFINE,
 data=T_inv.flatten()[:6], resample=Image.Resampling.NEAREST)
plt.imshow(np.asarray(img_transformed))
plt.show()
