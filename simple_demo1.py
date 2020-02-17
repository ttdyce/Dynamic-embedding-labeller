from tensorflow import keras
import tensorflow as tf
import numpy as np
from simple_autoencoder import Autoencoder
from simple_classifier import Classifier

print(tf.__version__)
encodeLength = 8

def numpy_fillna(data):
    # Get lengths of each row of data
    lens = np.array([len(i) for i in data])

    # Mask of valid places in each row
    mask = np.arange(lens.max()) < lens[:, None]

    # Setup output array and put elements from data into masked positions
    out = np.zeros(mask.shape, dtype=data.dtype)
    out[mask] = np.concatenate(data)
    return out

# dataset
tracesRaw = []
lengths = []
labels = []

with np.load("dataset.npz", allow_pickle=True) as dataset:
    tracesRaw = dataset["traces"]
    lengths = dataset["lengths"]
    labels = dataset["labels"]

tracesRaw = numpy_fillna(tracesRaw)
lengthMax = np.array(lengths).max()

# encoding/embedding
encoder = Autoencoder(lengthMax, encodeLength)
encoder.fit(tracesRaw, epochs=10)
tracesEnc = encoder.encode(tracesRaw)
tracesDec = encoder.decode(tracesEnc)

encoder.terminate()
print(tracesEnc[0])
print(tracesDec[0])

print(tracesRaw, labels, lengthMax)

# classifier
classifier = Classifier(encodeLength)
classifier.fit(tracesEnc, labels)
