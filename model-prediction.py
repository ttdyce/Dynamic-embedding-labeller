import collections
import matplotlib.pyplot as plt
import numpy as np

import tensorflow as tf

from tensorflow.keras import layers
from sklearn.model_selection import train_test_split
import DatasetLoader as Loader
from scipy import stats
#'1': Fixed value, '2': Stepper, '3': Gatherer

model = tf.keras.models.load_model('rnn-stateTrace/model3a/')
# (x1, x2), y, lengths, lengthsMax, exeNames, roleInStates = Loader.stateTrace.r5.load(model='3')
# features = roleInStates.max()

# x1_train, x1_validation, x2_train, x2_validation, y_train, y_validation = train_test_split(x1, x2, y, test_size=0.2)

# print("\n# Evaluate")
# result = model.evaluate([x1_validation, x2_validation], y_validation)
# dict(zip(model.metrics_names, result))

# print("x shape = ",x1_train.shape)


# x, y, lens, lenMax = loader.load(datasetPath="out-dataset/dataset-variable-trace-110.npz")
# x = x.reshape(x.__len__(), 1, lenMax)
# print("x shape = ",x.shape)
# x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.2)
# print(stats.describe(y_test))


# #for arr in y_test: #do not need the loop at this point, but looks prettier
    
# p = model.predict(x)
# p = np.argmax(p,axis=-1)
# print(stats.describe(y_test))

# print('\n# Evaluate')
# result = model.evaluate(x,y)
# dict(zip(model.metrics_names, result))
x,y = Loader.stateTrace.r5.prediction.load(model='3')[0]
p1 = model.predict([x,y])
print("p1 = ",np.argmax(p1,axis=-1), '\n' ,p1)

x,y =Loader.stateTrace.r5.prediction.load(model='3')[1]
p2 = model.predict([x,y])
print("p2 = ",np.argmax(p2,axis=-1), '\n' ,p2)

x,y = Loader.stateTrace.r5.prediction.load(model='3')[2]
p3 = model.predict([x,y])
print("p3 = ",np.argmax(p3,axis=-1), '\n' ,p3)

x,y = Loader.stateTrace.r5.prediction.load(model='3')[3]
p3 = model.predict([x,y])
print("p4 = ",np.argmax(p3,axis=-1), '\n' ,p3)

x,y = Loader.stateTrace.r5.prediction.load(model='3')[4]
p3 = model.predict([x,y])
print("p5 = ",np.argmax(p3,axis=-1), '\n' ,p3)

# print(Loader.stateTrace.r5.prediction.load(model='3')[0])