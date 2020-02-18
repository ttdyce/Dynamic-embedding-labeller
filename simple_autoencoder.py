import tensorflow as tf
import numpy as np


class Autoencoder:
    def __init__(self, D, d):
        # Input placeholder, "None" here means any size e.g. (13,D), (420,D), etc.
        self.X = tf.placeholder(tf.float32, shape=(None, D))

        # Input to hidden (D -> d)
        self.W1 = tf.Variable(tf.random_normal(shape=(D, d)))
        self.b1 = tf.Variable(np.zeros(d).astype(np.float32))

        # Hidden -> output (d -> D)
        self.W2 = tf.Variable(tf.random_normal(shape=(d, D)))
        self.b2 = tf.Variable(np.zeros(D).astype(np.float32))

        variables_dict = {'W1': self.W1, 'W2': self.W2, 'b1': self.b1, 'b2': self.b2}

        # Output
        self.Z = tf.nn.relu(tf.matmul(self.X, self.W1) + self.b1)
        logits = tf.matmul(self.Z, self.W2) + self.b2
        self.X_hat = tf.nn.sigmoid(logits)

        # Define loss function
        self.loss = tf.reduce_sum(
            tf.nn.sigmoid_cross_entropy_with_logits(
                # Expected result (a.k.a. itself for autoencoder)
                labels=self.X,
                logits=logits,
            )
        )

        self.optimizer = tf.train.RMSPropOptimizer(learning_rate=0.005).minimize(
            self.loss
        )

        self.init_op = tf.global_variables_initializer()
        self.saver = tf.train.Saver(variables_dict, max_to_keep=1)
        
        self.sess = tf.get_default_session()
        if self.sess == None:
            self.sess = tf.Session()
        self.sess.run(self.init_op)

    def fit(self, X, epochs=10, bs=64):
        n_batches = len(X) // bs
        print("Training {} batches".format(n_batches))

        for i in range(epochs):
            print("Epoch: ", i)
            X_perm = np.random.permutation(X)
            for j in range(n_batches):
                batch = X_perm[j * bs : (j + 1) * bs]
                _, _ = self.sess.run(
                    (self.optimizer, self.loss), feed_dict={self.X: batch}
                )

    def predict(self, X):
        return self.sess.run(self.X_hat, feed_dict={self.X: X})

    def encode(self, X):
        return self.sess.run(self.Z, feed_dict={self.X: X})

    def decode(self, Z):
        return self.sess.run(self.X_hat, feed_dict={self.Z: Z})
    
    def save(self):
        self.saver.save(self.sess, "simple-demo-encoder.ckpt")

    def restore(self):
        self.saver.restore(self.sess, "simple-demo-encoder.ckpt")

    def terminate(self):
        self.sess.close()
        del self.sess


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

encoder = Autoencoder(lengthMax, 8)
encoder.fit(traces, epochs=10)
enc = encoder.encode(traces)
dec = encoder.decode(enc)

encoder.save()
# encoder.restore()
encoder.terminate()
print(enc[0])
print(dec[0])
