import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

from sklearn.model_selection import train_test_split
from DatasetLoader import DatasetLoader as Loader
from sklearn.model_selection import KFold

batch_size_fit = 64
units = 8
output_size = 3  # labels are from 0 to 3
epochs = 50


# Build the RNN model
def build_model():
    model = tf.keras.models.Sequential(
        [
            tf.keras.layers.GRU(units, input_shape=(None, 1)),
            tf.keras.layers.Dense(output_size,activation='softmax')
        ]
    )
    return model

loader = Loader()
x, y, lens, lenMax = loader.load(datasetPath="out-dataset/dataset-variable-trace-110.npz")
#x, y, lens, lenMax = loader().loadDefault()

input_dim = lenMax
model = build_model()

opt = tf.keras.optimizers.Adam(lr=0.0005, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)
model.compile(
    loss='categorical_crossentropy',
    optimizer=opt,
    metrics=["accuracy"],
)

x = x.reshape(x.__len__(),lenMax,1)
print("x.shape",x.shape)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

model.summary()
callback = tf.keras.callbacks.EarlyStopping(monitor='val_loss',
                                            min_delta=0,
                                            patience=5,
                                            verbose=0, mode='auto')

checkpoint = tf.keras.callbacks.ModelCheckpoint('rnn-trace/', monitor='val_accuracy',callbacks=[callback], verbose=1, save_best_only=False, mode='max')

model.fit(
    x_train, y_train, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2
)

print('\n# Evaluate')
result = model.evaluate(x_test,y_test)
dict(zip(model.metrics_names, result))


model.save('rnn-trace/', save_format="tf")