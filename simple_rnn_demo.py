import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf

from sklearn.model_selection import train_test_split
import DatasetLoader as Loader
import ResultLogger as logger

batch_size_fit = 128
units = 30
epochs = 100
lr = 0.001

gpus = tf.config.experimental.list_physical_devices("GPU")
print(gpus)
for gpu in gpus:
    tf.config.experimental.set_memory_growth(gpu, True)

# Build the RNN model
def build_model():
    model = tf.keras.models.Sequential(
        [
            tf.keras.layers.Input(shape=features), 
            tf.keras.layers.Dense(features[1] * 4),
            tf.keras.layers.GRU(units),
            tf.keras.layers.Dense(output_size, activation="softmax"),
        ]
    )
    return model


# loader = Loader()
# x, y, lengths, lengthsMax, exeNames, roleInStates = Loader.variableTrace.load()
x, y, lengths, lengthsMax = Loader.variableTrace.load()
features = (x.shape[1], x.shape[2])
output_size = 3
# x, y, lens, lenMax = loader().loadDefault()

model = build_model()

opt = tf.keras.optimizers.Adam(
    lr=0.0005, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False
)
opt = tf.keras.optimizers.Adam(
    learning_rate=lr
)
model.compile(loss="categorical_crossentropy", optimizer=opt, metrics=["accuracy"])

# x = x.reshape(x.__len__(),300,2)
print("x.shape", x.shape)
x_train, x_, y_train, y_ = train_test_split(x, y, test_size=0.2)
x_test, x_val, y_test, y_val = train_test_split(x_, y_, test_size=0.5)

model.summary()
# callback = tf.keras.callbacks.EarlyStopping(
#     monitor="val_loss", min_delta=0, patience=5, verbose=0, mode="auto"
# )

# checkpoint = tf.keras.callbacks.ModelCheckpoint('rnn-trace/', monitor='val_accuracy',callbacks=[callback], verbose=1, save_best_only=False, mode='max')

history = model.fit(
    x_train, y_train, batch_size=batch_size_fit, epochs=epochs, validation_data=(x_test, y_test)
)

print("\n# Evaluate")
result = model.evaluate(x_val, y_val)
dict(zip(model.metrics_names, result))


# Prediction
# (x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.variableTrace.prediction.load(model='3')
# predictions = model.predict([x1,x2])
# predictions = [np.argmax(p,axis=-1) for p in predictions]

# roles = ['Stepper', 'Gatherer', 'Most-Recent holder', 'One-way flag & Constant']
# answers = [np.argmax(item,axis=-1) for item in y]
# answersCount = [0 for _ in range(output_size)]
# correctAnswersCount = [0 for _ in range(output_size)]

# for a in answers: 
#     answersCount[a] += 1
    
# for i in range(y.__len__()): 
#     if(predictions[i] == answers[i]): 
#         correctAnswersCount[answers[i]] += 1

# predictionDetails = f'''{roles}
# {answersCount}
# {correctAnswersCount}
# '''
# print("\n\n# Prediction")
# print(predictionDetails)
# predictionResult = model.evaluate([x1, x2], y)


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
