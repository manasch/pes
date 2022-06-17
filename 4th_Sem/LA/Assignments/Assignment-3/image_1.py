import matplotlib.pyplot as plt
import numpy as np
import string

img = plt.imread('pic.png')
width, height, _ = img.shape

plt.figure(figsize=(5, 5))
plt.imshow(img)
plt.show()