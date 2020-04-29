import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

from sklearn.model_selection import train_test_split
import DatasetLoader as Loader

batch_size_fit = 50
units = 50
output_size = 3  # labels are from 0 to 3
epochs = 100


# Build the RNN model
def build_model():
    model = tf.keras.models.Sequential(
        [
            tf.keras.layers.GRU(units, input_shape=(300, 5)),
            tf.keras.layers.Dense(output_size,activation='softmax')
        ]
    )
    return model

# loader = Loader()
x, y, lengths, lengthsMax , exeNames, roleInStates = Loader.stateTrace.load(model='2a')
#x, y, lens, lenMax = loader().loadDefault()

model = build_model()

opt = tf.keras.optimizers.Adam(lr=0.0005, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)
model.compile(
    loss='categorical_crossentropy',
    optimizer=opt,
    metrics=["accuracy"],
)

# x = x.reshape(x.__len__(),300,2)
print("x.shape",x.shape)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

model.summary()
callback = tf.keras.callbacks.EarlyStopping(monitor='val_loss',
                                            min_delta=0,
                                            patience=5,
                                            verbose=0, mode='auto')

checkpoint = tf.keras.callbacks.ModelCheckpoint('rnn-trace/', monitor='val_accuracy',callbacks=[callback], verbose=1, save_best_only=False, mode='max')

history = model.fit(
    x_train, y_train, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2
)

print('\n# Evaluate')
result = model.evaluate(x_test,y_test)
dict(zip(model.metrics_names, result))


model.save('rnn-trace/', save_format="tf")


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
