import matplotlib.pyplot as plt
import numpy as np
from PIL import Image

img = Image.open('pic.png')
plt.figure(figsize=(5, 5))
plt.imshow(np.asarray(img))
plt.show()
