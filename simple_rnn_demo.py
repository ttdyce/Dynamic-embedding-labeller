import collections
import matplotlib.pyplot as plt
import numpy as np

import tensorflow as tf

from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
import DatasetLoader as loader
from sklearn.preprocessing import LabelBinarizer

batch_size = 20

input_dim = 1
units = 100
output_size = 3  # labels are from 0 to 3
epochs = 20

# Build the RNN model
def build_model():
    embedding_layer = layers.Embedding(999+1, output_dim=100)
    gru_layer = tf.keras.layers.GRU(units) #, input_shape=(None, input_dim)

    model = tf.keras.models.Sequential(
        [
            embedding_layer,
            gru_layer,
            # tf.keras.layers.BatchNormalization(),
            tf.keras.layers.Dense(output_size, activation='softmax'),
        ]
    )

    model.summary()
    return model


x, y, lens, lenMax, _names, _counts = loader.stateTrace.load()

# x = x.reshape(x.__len__(), lenMax, 1)
y = LabelBinarizer().fit_transform(y)

model = build_model()

model.compile(loss="categorical_crossentropy", optimizer="adam", metrics=["accuracy"])

x_train, x_test, y_train, y_test = train_test_split(
    x.astype(int), y.astype(int), test_size=0.1
)  # replaced by validation_split=0.2

history = model.fit(x_train, y_train, validation_split=0.1, batch_size=batch_size, epochs=epochs)

print('')
print('# Evaluate')
result = model.evaluate(x_test,y_test)
dict(zip(model.metrics_names, result))

# draw loss
plt.plot(history.history["loss"])
plt.plot(history.history["val_loss"])
plt.title("Model loss")
plt.ylabel("Loss")
plt.xlabel("Epoch")
plt.legend(["Train", "Test"], loc="upper left")
plt.show()

# draw acc
plt.plot(history.history["accuracy"])
plt.plot(history.history["val_accuracy"])
plt.title("Model accuracy")
plt.ylabel("Accuracy")
plt.xlabel("Epoch")
plt.legend(["Train", "Test"], loc="upper left")
plt.show()
