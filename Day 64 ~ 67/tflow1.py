import tensorflow as tf

#create tensorflow object called tensor
hello_constant = tf.constant('Hello World!')
hello_constant

with tf.Session() as sess:
    #Run the tf.constant operation in the session
    output = sess.run(hello_constant)#.decode()
    print(output)

print(tf.__version__)

