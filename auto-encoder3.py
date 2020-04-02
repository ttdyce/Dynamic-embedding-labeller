import tensorflow as tf
from sklearn.model_selection import train_test_split
from DatasetLoader import DatasetLoader as loader

traces, labels, lengths, lengthMax = loader().loadDefault()

x_train=traces

x_train = x_train.astype('float32') / 255.

class Encoder(tf.keras.layers.Layer):
  def __init__(self, intermediate_dim):
    super(Encoder, self).__init__()
    self.hidden_layer = tf.keras.layers.Dense(
      units=intermediate_dim,
      activation=tf.nn.relu,
      kernel_initializer='he_uniform'
    )
    self.output_layer = tf.keras.layers.Dense(
      units=intermediate_dim,
      activation=tf.nn.sigmoid
    )
    
  def call(self, input_features):
    activation = self.hidden_layer(input_features)
    return self.output_layer(activation)

class Decoder(tf.keras.layers.Layer):
  def __init__(self, intermediate_dim, original_dim):
    super(Decoder, self).__init__()
    self.hidden_layer = tf.keras.layers.Dense(
      units=intermediate_dim,
      activation=tf.nn.relu,
      kernel_initializer='he_uniform'
    )
    self.output_layer = tf.keras.layers.Dense(
      units=original_dim,
      activation=tf.nn.sigmoid
    )
  
  def call(self, code):
    activation = self.hidden_layer(code)
    return self.output_layer(activation)

class Autoencoder(tf.keras.Model):
  def __init__(self, intermediate_dim, original_dim):
    super(Autoencoder, self).__init__()
    self.encoder = Encoder(intermediate_dim=intermediate_dim)
    self.decoder = Decoder(intermediate_dim=intermediate_dim, original_dim=original_dim)
  
  def call(self, input_features):
    code = self.encoder(input_features)
    reconstructed = self.decoder(code)
    return reconstructed

#compare the result of encoder and the original input. And see the "reconstruction error" (reconstruction error)
def loss(model, original):
  reconstruction_error = tf.reduce_mean(tf.square(tf.subtract(model(original), original)))
  return reconstruction_error

#simple backpropagation
def train(loss, model, opt, original):
  with tf.GradientTape() as tape:
    gradients = tape.gradient(loss(model, original), model.trainable_variables)
    gradient_variables = zip(gradients, model.trainable_variables)
    opt.apply_gradients(gradient_variables)


autoencoder = Autoencoder(intermediate_dim=8, original_dim=lengthMax)
opt = tf.optimizers.Adam(learning_rate=0.001)
epochs = 10

training_dataset = tf.data.Dataset.from_tensor_slices(x_train)
batch_size = 20 #devide the work to many times. 1 mini work include batch_size samples
training_dataset = training_dataset.batch(batch_size)
training_dataset = training_dataset.prefetch(batch_size * 4)

writer = tf.summary.create_file_writer('tmp')

with writer.as_default():
    with tf.summary.record_if(True):
        for epoch in range(epochs):
            for step, batch_features in enumerate(training_dataset):
                train(loss, autoencoder, opt, batch_features)
                loss_values = loss(autoencoder, batch_features)
                #original = tf.reshape(batch_features, (batch_features.shape[0], 28, 28, 1))
                #reconstructed = tf.reshape(autoencoder(tf.constant(batch_features)), (batch_features.shape[0], 28, 28, 1))
                tf.summary.scalar('loss', loss_values, step=step)
                #tf.summary.image('original', original, max_outputs=10, step=step)
                #tf.summary.image('reconstructed', reconstructed, max_outputs=10, step=step)


                #tensorboard --logdir=path/to/log-directory