import collections
import matplotlib.pyplot as plt
import numpy as np

import tensorflow as tf

from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
from DatasetLoader import DatasetLoader as loader

batch_size_fit = 12
# Each MNIST image batch is a tensor of shape (batch_size, 28, 28).
# Each input sequence will be of size (28, 28) (height is treated like time).
# input_dim = 21086 # declared below

units = 32
output_size = 3  # labels are from 0 to 3
epochs = 40

# Build the RNN model
def build_model(allow_cudnn_kernel=True):
    # CuDNN is only available at the layer level, and not at the cell level.
    # This means `LSTM(units)` will use the CuDNN kernel,
    # while RNN(LSTMCell(units)) will run on non-CuDNN kernel.
    if allow_cudnn_kernel:
        # The LSTM layer with default options uses CuDNN.
        gru_layer = tf.keras.layers.GRU(units, input_shape=(None, input_dim))
    else:
        # Wrapping a LSTMCell in a RNN layer will not use CuDNN.
        gru_layer = tf.keras.layers.GRU(
            tf.keras.layers.LSTMCell(units), input_shape=(None, input_dim)
        )
    model = tf.keras.models.Sequential(
        [
            gru_layer,
            tf.keras.layers.BatchNormalization(),
            tf.keras.layers.Dense(output_size),
        ]
    )
    return model

x, y, lens, lenMax = loader().loadDefault()
input_dim = lenMax

model = build_model(allow_cudnn_kernel=True)

model.compile(
    loss='categorical_crossentropy',
    optimizer="sgd",
    metrics=["accuracy"],
)

x = x.reshape(x.__len__(), 1, lenMax)
# print(x.shape)
# print(y.shape)

# print(x[0])
# print(y[0])
# x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2) #replaced by validation_split=0.2

model.fit(
    x, y, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2
)

