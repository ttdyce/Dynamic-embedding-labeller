from tensorflow import keras
import tensorflow as tf
import numpy as np

modelOutName = 'simple-demo-model.h5'

class Classifier: 
    def __init__(self, inputLength): 
        self.inputLength = inputLength
        # define model
        model = keras.Sequential(
            [
                keras.layers.Dense(128, input_shape=(inputLength,) ),
                keras.layers.Dense(128, activation="relu"),
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
        model.fit(x, y, epochs=100)

        test_loss, test_acc = model.evaluate(x, y.astype(float), verbose=2)

        print("\nTest accuracy:", test_acc)

        probability_model = tf.keras.Sequential([model, tf.keras.layers.Softmax()])
        predictions = probability_model.predict(x)

        model.save(modelOutName)
        # Recreate the exact same model, including its weights and the optimizer
        the_model = tf.keras.models.load_model(modelOutName)
        # Show the model architecture
        the_model.summary()

        print("Predition result:", 
              predictions[0],
              np.argmax(predictions[0]), 
              y[0], 
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