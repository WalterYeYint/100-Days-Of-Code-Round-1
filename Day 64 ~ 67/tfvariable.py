#########################################
# #Variables allow us to add trainable parameters to a graph
# #y = .2 + .3*x

# import tensorflow as tf

# W1 = tf.Variable([.5], tf.float32)
# #important: need to run below code to initialize the Variables()
# init = tf.global_variables_initializer()
# sess = tf.compat.v1.Session()
# sess.run(init)
# print(sess.run(W1))

########################################
#Y = b + W*x
import tensorflow as tf
W = tf.Variable([.3], tf.float32)
b = tf.Variable([-.9], tf.float32)
x = tf.placeholder(tf.float32)

linear_model = W*x + b
init = tf.global_variables_initializer()
sess = tf.compat.v1.Session()
sess.run(init)
print(sess.run(linear_model, {x:[1, 2, 3, 4, 5, 7]}))   #no need to add feed_dict, the code auto understands



