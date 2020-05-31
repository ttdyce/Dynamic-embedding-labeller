import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Concatenate, Dense, LSTM, Input, concatenate
from sklearn.model_selection import train_test_split
from sklearn.model_selection import KFold
import DatasetLoader as Loader

# config
physical_devices = tf.config.list_physical_devices('GPU')
tf.config.experimental.set_memory_growth(physical_devices[0], enable=True)
batch_size_fit = 500
units = 100
# output_size = 5  # labels are from 0 to 3
epochs = 300

# dataset
(x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r4mod.load(model='3')
features = roleInStates.max()
output_size = y.shape[1]

####################################model########################################
first_input = Input(shape=(300, 1))
d11 = tf.keras.layers.Dense(4)(first_input)
first_GRU = tf.keras.layers.GRU(units)(d11)
first_dense = tf.keras.layers.Dense(units/2, activation="sigmoid")(first_GRU)

second_input = Input(shape=(300, features - 1))
d21 = tf.keras.layers.Dense((features - 1) * 4)(second_input)
second_GRU = tf.keras.layers.GRU(units)(d21)
second_dense = tf.keras.layers.Dense(units/2, activation="sigmoid")(second_GRU)

merged = concatenate([first_dense, second_dense])
merged_dense = tf.keras.layers.Dense(units/2, activation="relu")(merged)
out = tf.keras.layers.Dense(output_size, activation="softmax")(merged_dense)

model = tf.keras.models.Model(inputs=[first_input, second_input], outputs=out)
#################################################################################

#model
#adam may be too aggresive
opt = tf.keras.optimizers.Adam(
    lr=0.0002, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False
)
model.compile(loss="categorical_crossentropy", optimizer=opt, metrics=["accuracy"])

#training data and validation data
x1_train, x1_validation, x2_train, x2_validation, y_train, y_validation = train_test_split(x1, x2, y, test_size=0.2)
x1_train, x1_test, x2_train, x2_test, y_train, y_test = train_test_split(x1_train, x2_train, y_train, test_size=0.2)

model.summary()
# callback = tf.keras.callbacks.EarlyStopping(
#     monitor="val_loss", min_delta=0, patience=5, verbose=0, mode="auto"
# )

checkpoint = tf.keras.callbacks.ModelCheckpoint(
    "rnn-stateTrace/model3c_checkpoint/",
    monitor="val_accuracy",
    verbose=1,
    save_best_only=True,
    mode="max",
)

history = model.fit(
    [x1_train, x2_train], y_train, batch_size=batch_size_fit, epochs=epochs, validation_data=([x1_test, x2_test],y_test)
)

print("\n# Evaluate")
result = model.evaluate([x1_validation, x2_validation], y_validation)
dict(zip(model.metrics_names, result))

model.save("rnn-stateTrace/model3c/", save_format="tf")


(x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r4mod.prediction.load(model='3')
predictions = model.predict([x1,x2])
predictions = [np.argmax(p,axis=-1) for p in predictions]

roles = ['Constant', 'Stepper', 'Gatherer', 'Most-Recent holder', 'One-way flag']
answers = [np.argmax(item,axis=-1) for item in y]
answersCount = [0 for i in range(output_size)]
correctAnswersCount = [0 for i in range(output_size)]

for a in answers: 
    answersCount[a] += 1
    
for i in range(y.__len__()): 
    if(predictions[i] == answers[i]): 
        correctAnswersCount[answers[i]] += 1
        
print("\n\n# Prediction")
print(roles, answersCount, correctAnswersCount, sep='\n')
result = model.evaluate([x1, x2], y)

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
