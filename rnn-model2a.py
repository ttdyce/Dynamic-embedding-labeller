import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

from sklearn.model_selection import train_test_split
import DatasetLoader as Loader
from sklearn.model_selection import KFold

batch_size_fit = 64
units = 8
output_size = 3  # labels are from 0 to 3
epochs = 650


# Build the RNN model
def build_model():
    model = tf.keras.models.Sequential(
        [
            tf.keras.layers.GRU(units, input_shape=(None, 2)),
            #Dense (units to output_size 3?4?)
            tf.keras.layers.Dense(output_size,activation='softmax')
        ]
    )
    return model

x, y, lengths, lengthsMax , exeNames, roleInStates = Loader.stateTrace.load(model='1')

model = build_model()

opt = tf.keras.optimizers.Adam(lr=0.0005, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False)
model.compile(
    loss='categorical_crossentropy',
    optimizer=opt,
    metrics=["accuracy"],
)

print("x.shape",x.shape)
x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)

model.summary()
callback = tf.keras.callbacks.EarlyStopping(monitor='val_loss',
                                            min_delta=0,
                                            patience=5,
                                            verbose=0, mode='auto')

model.fit(
    x_train, y_train, batch_size=batch_size_fit, epochs=epochs, validation_split=0.2
)

print('\n# Evaluate')
result = model.evaluate(x_test,y_test)
dict(zip(model.metrics_names, result))

predictionData = Loader.stateTrace.prediction.load(model='1') # same return format with stateTrace.load(model='1')

predictions = model.predict(predictionData[0])
print(predictions) #result
print(predictionData[1])

model.save('rnn-stateTrace/model2a/', save_format="tf")