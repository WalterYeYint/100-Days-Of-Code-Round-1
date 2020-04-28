#A loss function measures how far apart the current model is from the provided data
import tensorflow as tf
#Loss function
W = tf.Variable([.3], tf.float32)
b = tf.Variable([-.3], tf.float32)
x = tf.placeholder(tf.float32)
y = tf.placeholder(tf.float32)

linear_model = W*x + b

#.3*1 + -.3 = 0
#(0-0)^2 = 0
#2, 3 = -1
#3, 2 = 1
#0
#x^2 = 2x
#sum(actual - predicted)^2

squared_delta = tf.square(linear_model - y)
loss = tf.reduce_sum(squared_delta)

init = tf.global_variables_initializer()
sess = tf.compat.v1.Session()
sess.run(init)
print(sess.run(loss,{x:[1, 2, 3, 4], y:[0, 1, -2, -3]}))
sess.close()
