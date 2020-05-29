import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Model, Sequential
from tensorflow.keras.layers import Concatenate, Dense, LSTM, Input, concatenate, Flatten, TimeDistributed, Dropout
from keras.layers.convolutional import Conv1D
from keras.layers.convolutional import MaxPooling1D

from sklearn.model_selection import train_test_split
from sklearn.model_selection import KFold
import DatasetLoader as Loader

# tensorflow gpu work around
gpus = tf.config.experimental.list_physical_devices("GPU")
print(gpus)
for gpu in gpus:
    tf.config.experimental.set_memory_growth(gpu, True)

# config
batch_size_fit = 100
units = 25
output_size = 5  # label size
epochs = 100

# dataset
x, y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r5.load(model='2b')
features = roleInStates.max()
length = 300
step = 7

# model
model = Sequential()
model.add(TimeDistributed(Conv1D(filters=8, kernel_size=3, activation='relu'), input_shape=(None,length,features)))
model.add(TimeDistributed(Conv1D(filters=8, kernel_size=3, activation='relu')))
model.add(TimeDistributed(Dropout(0.5)))
model.add(TimeDistributed(MaxPooling1D(pool_size=2)))
model.add(TimeDistributed(Flatten()))
model.add(LSTM(100))
model.add(Dropout(0.5))
model.add(Dense(100, activation='relu'))
model.add(Dense(output_size, activation='softmax'))

opt = tf.keras.optimizers.Adam(
    lr=0.0005, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False
)
model.compile(loss="categorical_crossentropy", optimizer=opt, metrics=["accuracy"])

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

model.summary()
callback = tf.keras.callbacks.EarlyStopping(
    monitor="val_loss", min_delta=0, patience=5, verbose=0, mode="auto"
)

checkpoint = tf.keras.callbacks.ModelCheckpoint(
    "rnn-trace/",
    monitor="val_accuracy",
    callbacks=[callback],
    verbose=1,
    save_best_only=False,
    mode="max",
)

history = model.fit(
    x_train, y_train, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2
)

print("\n# Evaluate")
result = model.evaluate(x_test, y_test)
dict(zip(model.metrics_names, result))

model.save("rnn-trace/", save_format="tf")


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
