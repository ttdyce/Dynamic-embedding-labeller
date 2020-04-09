import numpy as np
from DatasetLoader import DatasetLoader as loader
import matplotlib.pyplot as plt
from pprint import pprint

# dataset
# tracesRaw = []
# lengths = []
# labels = []
# with np.load("out-dataset/dataset.npz", allow_pickle=True) as dataset:
#     tracesRaw = dataset["traces"]
#     lengths = dataset["lengths"]
#     labels = dataset["labels"]

# plt.hist(labels)
# plt.xlabel('label id')
# plt.ylabel('label count')
# plt.show()

x, y, lengths, lengthsMax = loader().loadDefault()

# print(np.array(x).__len__())
print(np.array(x[10]).tolist())
print(np.array(y[10]).tolist())
# print('datasets shape: ', np.array(x).shape)
# print('labels: ', y)
# print('lengths: ', lengths)
# print('lengthsMax: ', lengthsMax)