import collections
import matplotlib.pyplot as plt
import numpy as np

import tensorflow as tf

from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
from DatasetLoader import DatasetLoader as Loader

batch_size_fit = 64
# Each input sequence will be of size (28, 28) (height is treated like time).

units = 128
output_size = 3  # labels are from 0 to 3
epochs = 50

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
            #tf.keras.layers.BatchNormalization(),
            tf.keras.layers.Dense(output_size,activation='softmax'),
        ]
    )
    return model

loader = Loader()
x, y, lens, lenMax = loader.load(datasetPath="out-dataset/dataset-variable-trace-110.npz")

#x, y, lens, lenMax = loader().loadDefault()
input_dim = lenMax

model = build_model(allow_cudnn_kernel=True)

opt = tf.keras.optimizers.Adam(lr=0.0001, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)

model.compile(
    loss='categorical_crossentropy',
    optimizer=opt,
    metrics=["accuracy"],
)

x = x.reshape(x.__len__(), 1, lenMax)
print("x.shape",x.shape)
# print(y.shape)

# print(x[0])
# print(y[0])
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

model.summary()

model.fit(
    x_train, y_train, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2
)

print('\n# Evaluate')
result = model.evaluate(x_test,y_test)
dict(zip(model.metrics_names, result))


model.save('rnn-trace/', save_format="tf")
#prepared for predictions
# Xnew = np.array([[0.89337759, 0.65864154]])
# ynew = model.predict_classes(Xnew)
# print("X=%s, Predicted=%s" % (Xnew[0], ynew[0]))