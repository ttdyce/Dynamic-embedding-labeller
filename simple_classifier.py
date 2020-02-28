from tensorflow import keras
import tensorflow as tf
import numpy as np
from sklearn.model_selection import train_test_split

modelOutName = 'simple-demo-classifier.h5'

class Classifier: 
    def __init__(self, inputLength): 
        self.inputLength = inputLength
        # define model
        model = keras.Sequential(
            [
                keras.layers.Dense(8, input_shape=(inputLength,) ),
                keras.layers.Dense(8, activation="relu"),
                keras.layers.Dense(4),
            ]
        )
        model.compile(
            optimizer="adam",
            loss=tf.keras.losses.SparseCategoricalCrossentropy(from_logits=True),
            metrics=["accuracy"],
        )
        self.model = model
    
    def fit(self, x,y): 
        'fit & save & try predict'
        model = self.model
        x_train,x_test,y_train,y_test=train_test_split(x, y,test_size=0.2)
        model.fit(x_train, y_train, epochs=100)

        test_loss, test_acc = model.evaluate(x_test, y_test, verbose=2)

        print("\nTest accuracy:", test_acc)

        probability_model = tf.keras.Sequential([model, tf.keras.layers.Softmax()])
        predictions = probability_model.predict(x_test)

        model.save(modelOutName)
        # Recreate the exact same model, including its weights and the optimizer
        the_model = tf.keras.models.load_model(modelOutName)
        # Show the model architecture
        the_model.summary()

        print("Predition:", 
              "Result 1", 
              predictions[0],
              np.argmax(predictions[0]), 
              y_test[0], 
              "Result 2", 
              predictions[1],
              np.argmax(predictions[1]), 
              y_test[1], 
              "Result 3", 
              predictions[2],
              np.argmax(predictions[2]), 
              y_test[2], 
              sep='\n')


def numpy_fillna(data):
    # Get lengths of each row of data
    lens = np.array([len(i) for i in data])

    # Mask of valid places in each row
    mask = np.arange(lens.max()) < lens[:, None]

    # Setup output array and put elements from data into masked positions
    out = np.zeros(mask.shape, dtype=data.dtype)
    out[mask] = np.concatenate(data)
    return out


traces = []
lengths = []
labels = []

with np.load("dataset.npz", allow_pickle=True) as dataset:
    traces = dataset["traces"]
    lengths = dataset["lengths"]
    labels = dataset["labels"]

traces = numpy_fillna(traces)
lengthMax = np.array(lengths).max()

print(traces, labels, lengthMax)

classifier = Classifier(inputLength=lengthMax)
classifier.fit(traces, labels)