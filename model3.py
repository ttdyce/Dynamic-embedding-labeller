import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Concatenate, Dense, LSTM, Input, concatenate
from sklearn.model_selection import train_test_split
from sklearn.model_selection import KFold
import DatasetLoader as Loader

# tensorflow gpu work around
# gpus = tf.config.experimental.list_physical_devices("GPU")
# print(gpus)
# for gpu in gpus:
#     tf.config.experimental.set_memory_growth(gpu, True)

# config
batch_size_fit = 100
units = 50
output_size = 5  # labels are from 0 to 3
epochs = 100

# dataset
(x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r5.load(model='3')
features = roleInStates.max()
# x, y, lens, lenMax = loader().loadDefault()

# model
first_input = Input(shape=(300, 1))
first_GRU = tf.keras.layers.GRU(units)(first_input)
first_dense = tf.keras.layers.Dense(output_size, activation="sigmoid")(first_GRU)

second_input = Input(shape=(300, features - 1))
second_GRU = tf.keras.layers.GRU(units)(second_input)
second_dense = tf.keras.layers.Dense(output_size, activation="sigmoid")(second_GRU)

merged = concatenate([first_dense, second_dense])
#dense
#third_dense = tf.keras.layers.Dense(output_size, activation="softmax")(second_GRU)
out = tf.keras.layers.Dense(output_size, activation="softmax")(merged)

model = tf.keras.models.Model(inputs=[first_input, second_input], outputs=out)

#adam 太進取
opt = tf.keras.optimizers.Adam(
    lr=0.0005, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False
)
model.compile(loss="categorical_crossentropy", optimizer=opt, metrics=["accuracy"])

x1_train, x1_test, x2_train, x2_test, y_train, y_test = train_test_split(x1, x2, y, test_size=0.2)

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
    [x1_train, x2_train], y_train, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2, callbacks= [checkpoint]
)

print("\n# Evaluate")
result = model.evaluate([x1_test, x2_test], y_test)
dict(zip(model.metrics_names, result))

model.save("rnn-stateTrace/model3/", save_format="tf")


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
