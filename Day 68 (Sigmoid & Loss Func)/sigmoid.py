#Sigmoid
import tensorflow as tf
import numpy as np
a = [.2, 1, 0, 3, -2]
sigmoid_Activation = tf.sigmoid(a)
tanh_Activation = tf.tanh(a)
relu_Activation = tf.nn.relu(a)
with tf.compat.v1.Session() as sess:
    output1 = sess.run(sigmoid_Activation)
    output2 = sess.run(tanh_Activation)
    output3 = sess.run(relu_Activation)
    print("Sigmoid Activation: ", output1)
    print("Tanh Activation: ", output2)
    print("ReLU Activation: ", output3)