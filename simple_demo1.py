from tensorflow import keras
import tensorflow as tf
import numpy as np
from simple_autoencoder import Autoencoder
from simple_classifier import Classifier
from DatasetLoader import DatasetLoader as loader

print(tf.__version__)
encodeLength = 8

# dataset
x, y, lengths, lengthMax = loader().loadDefault()

# encoding/embedding
encoder = Autoencoder(lengthMax, encodeLength)
# load autoencoder
encoder.restore()
# encoder.fit(tracesRaw, epochs=10)

tracesEnc = encoder.encode(x)
tracesDec = encoder.decode(tracesEnc)

encoder.terminate()
print(tracesEnc[0])
print(tracesDec[0])

print(x, y, lengthMax)

# classifier
classifier = Classifier(encodeLength)
classifier.fit(tracesEnc, y)
