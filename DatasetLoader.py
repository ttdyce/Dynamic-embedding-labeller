import numpy as np


class DatasetLoader:
    def loadDefault(self):
        return self.load("out-dataset/dataset.npz")

    def load(self, datasetPath):
        traces = []
        lengths = []
        labels = []

        with np.load(datasetPath, allow_pickle=True) as dataset:
            traces = dataset["traces"]
            lengths = dataset["lengths"]
            labels = dataset["labels"]

        traces = self.numpy_fillna(traces)
        lengthMax = np.array(lengths).max()

        return traces, labels, labels, lengthMax

    def numpy_fillna(self, data):
        # Get lengths of each row of data
        lens = np.array([len(i) for i in data])

        # Mask of valid places in each row
        mask = np.arange(lens.max()) < lens[:, None]

        # Setup output array and put elements from data into masked positions
        out = np.zeros(mask.shape, dtype=data.dtype)
        out[mask] = np.concatenate(data)
        return out
