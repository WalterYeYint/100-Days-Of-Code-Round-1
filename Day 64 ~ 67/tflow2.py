# #########################################
# #first program session

# import tensorflow as tf

# #initiate tensorflow constant
# node1 = tf.constant(3.0, tf.float32)
# node2 = tf.constant(4.0)  #also tf.float32 implicitly
# print(node1, node2)

# sess = tf.compat.v1.Session()
# print(sess.run([node1, node2]))
# sess.close()

# #########################################
# #multiply two constants
# import tensorflow as tf
# a = tf.constant(4.0)
# b = tf.constant(6.0)
# c = a * b
# print(c)


# #evaluate the tensor
# sess = tf.compat.v1.Session()
# print(sess.run(c))
# sess.close()

#########################################
#converting data types
#tf.subtract(tf.constant(2.0), tf.constant(1))  #fails with value error tensor conversion requested...
import tensorflow as tf
with tf.compat.v1.Session() as sess:
    print(sess.run(tf.subtract(tf.cast(tf.constant(5.0), tf.int32), tf.constant(2))))  #3

# #########################################
# #what if you wanna use non-constant? This is where tf.placeholder and feed_dict come into place
# import tensorflow as tf
# a = tf.placeholder(tf.float32)
# b = tf.placeholder(tf.float32)

# adder_node = a + b
# sess = tf.compat.v1.Session()
# print(sess.run(adder_node, feed_dict = {a:[1, 7, 6], b:[3, 20, 2]}))

# #Do another calculation
# Mult_5 = adder_node * 5
# print(sess.run(Mult_5, {a:[[1, 2, 3],
#         [2, 3, 4],
#         [3, 2, 1]], b:[[10, 2, 3],
#         [2, 3, 4],
#         [3, 2, 1]]}))