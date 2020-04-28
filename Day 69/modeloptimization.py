#Model Optimization
#Loss function
import tensorflow as tf
W = tf.Variable([.5], tf.float32)
b = tf.Variable([.1], tf.float32)
x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

linear_model = W*x + b

squared_delta = tf.square(linear_model - y)
loss = tf.reduce_sum(squared_delta)

optimizer = tf.train.GradientDescentOptimizer(0.01)
train = optimizer.minimize(loss)
init = tf.global_variables_initializer()
sess = tf.compat.v1.Session()
sess.run(init)
for i in range(3):
    sess.run(train, {x:[1, 2, 3, 4], y:[0, -1, -2, -3]})

print(sess.run([W, b])) 

sess.close()