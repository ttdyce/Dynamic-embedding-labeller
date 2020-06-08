import collections
import matplotlib.pyplot as plt
import numpy as np
import tensorflow as tf
from tensorflow.keras.models import Model
from tensorflow.keras.layers import Concatenate, Dense, LSTM, Input, concatenate
from sklearn.model_selection import train_test_split
from sklearn.model_selection import KFold
import DatasetLoader as Loader
import ResultLogger as logger

physical_devices = tf.config.list_physical_devices('GPU')
tf.config.experimental.set_memory_growth(physical_devices[0], enable=True)
# config
log_result = True
batch_size_fit = 100
units = 50
epochs = 650
learning_rate = 0.0005

# dataset
(x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r4mod.load(model='3')
features = roleInStates.max()
output_size = y.shape[1]

####################################model########################################
first_input = Input(shape=(300, 1))
d1 = tf.keras.layers.Dense(4)(first_input)
first_GRU = tf.keras.layers.GRU(units)(d1)
first_dense = tf.keras.layers.Dense(output_size, activation="sigmoid")(first_GRU)

second_input = Input(shape=(300, features - 1))
d2 = tf.keras.layers.Dense((features - 1) * 4)(second_input)
second_GRU = tf.keras.layers.GRU(units)(d2)
second_dense = tf.keras.layers.Dense(output_size, activation="sigmoid")(second_GRU)

merged = concatenate([first_dense, second_dense])
merged_dense = tf.keras.layers.Dense(units / 4, activation="relu")(merged)
merged_dense = tf.keras.layers.Dropout(0.2)(merged_dense)
out = tf.keras.layers.Dense(output_size, activation="softmax")(merged_dense)

model = tf.keras.models.Model(inputs=[first_input, second_input], outputs=out)
#################################################################################

#model
#adam may be too aggresive
opt = tf.keras.optimizers.Adam(
    learning_rate=learning_rate, beta_1=0.9, beta_2=0.999, epsilon=None, decay=0.0, amsgrad=False
)
model.compile(loss="categorical_crossentropy", optimizer=opt, metrics=["accuracy"])

#training data and validation data
x1_train, x1_validation, x2_train, x2_validation, y_train, y_validation = train_test_split(x1, x2, y, test_size=0.2)
x1_train, x1_test, x2_train, x2_test, y_train, y_test = train_test_split(x1_train, x2_train, y_train, test_size=0.2)

model.summary()
if(log_result): 
    logger.plot_model(model, 'model3d')
# callback = tf.keras.callbacks.EarlyStopping(
#     monitor="val_loss", min_delta=0, patience=5, verbose=0, mode="auto"
# )

checkpoint = tf.keras.callbacks.ModelCheckpoint(
    "rnn-stateTrace/model3d_checkpoint/",
    monitor="val_accuracy",
    verbose=1,
    save_best_only=True,
    mode="max",
)

history = model.fit(
    [x1_train, x2_train], y_train, batch_size=batch_size_fit, epochs=epochs, validation_data=([x1_test, x2_test],y_test)
    # , callbacks= [checkpoint]
)

print("\n# Evaluate")
evaluationResult = model.evaluate([x1_validation, x2_validation], y_validation)

model.save("rnn-stateTrace/model3d/", save_format="tf")

# Prediction
(x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r4mod.prediction.load(model='3')
predictions = model.predict([x1,x2])
predictions = [np.argmax(p,axis=-1) for p in predictions]

roles = ['Stepper', 'Gatherer', 'Most-Recent holder', 'One-way flag & Constant']
answers = [np.argmax(item,axis=-1) for item in y]
answersCount = [0 for _ in range(output_size)]
correctAnswersCount = [0 for _ in range(output_size)]

for a in answers: 
    answersCount[a] += 1
    
for i in range(y.__len__()): 
    if(predictions[i] == answers[i]): 
        correctAnswersCount[answers[i]] += 1

predictionDetails = f'''{roles}
{answersCount}
{correctAnswersCount}
'''
print("\n\n# Prediction")
print(predictionDetails)
predictionResult = model.evaluate([x1, x2], y)

# Log result
if(log_result): 
    stringlist = []
    model.summary(print_fn=lambda x: stringlist.append(x))
    summary = "\n".join(stringlist)

    logger.log(summary, history, evaluationResult, predictionResult, predictionDetails, 
               units=units, batch_size_fit=batch_size_fit, epochs=epochs, output_size=output_size, learning_rate=learning_rate, 
               remark='generating graphs, 100 epochs as base line')
    logger.plot_model(model, 'model3d')


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
