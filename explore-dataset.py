import numpy as np
import matplotlib.pyplot as plt

# dataset
tracesRaw = []
lengths = []
labels = []
with np.load("out-dataset/dataset.npz", allow_pickle=True) as dataset:
    tracesRaw = dataset["traces"]
    lengths = dataset["lengths"]
    labels = dataset["labels"]

plt.hist(labels)
plt.xlabel('label id')
plt.ylabel('label count')
plt.show()