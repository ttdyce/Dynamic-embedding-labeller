import numpy as np
import DatasetLoader as loader
import matplotlib.pyplot as plt
from pprint import pprint

# dataset
# x, y, lens, lenMax = loader.variableTrace.load()

y = loader.stateTrace.r5.load()[1]
index = np.argmax(y, axis=1)

plt.hist(index)
plt.xlabel('label id')
plt.ylabel('label count')
plt.show()
# x, y, lengths, lengthsMax = loader.loadDefault()

# print(np.array(x).__len__())
# print(np.array(x[10]).tolist())
# print(np.array(y[10]).tolist())
# print('datasets shape: ', np.array(x).shape)
# print('labels: ', y)
# print('lengths: ', lengths)
# print('lengthsMax: ', lengthsMax)