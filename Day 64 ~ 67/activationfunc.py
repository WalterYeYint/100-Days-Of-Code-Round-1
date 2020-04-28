import numpy as np

# #########################################################
# #sigmoid function --> used to map values bet. 0 & 1
# #1 / (1 + exp(-x))
# def sigmoid_(a):
#     return 1/(1 + np.exp(-a))
# print(sigmoid_(.3))
# a = [1, 2, 4, 0, 5, -6, 7]
# for i in a:
#     print(sigmoid_(i))

# #########################################################
# #tan hyperbolic function --> used to map values bet. -1 & 1
# #better at handling negative values than sigmoid
# #tanh(a) = (e^a + e^-a)/e^a + e^-a  --> ??? --> then he called return tanh(a) in tanh_(a) function
# from numpy import exp as e

# def tanh_(a):
#     return 2 / (1 + e(2*a)) - 1
# tanh_(.3)
# a = [-4, -2, 0, 2, 4]
# for i in a:
#     print(tanh_(i))

# #########################################################
# #rectified linear unit activation function --> 0 when x < 0, =x when x > 0
# def relu_(a):
#     return np.maximum(0, a)
# relu_(.3)
# a = [-4, -2, 2, 4]
# for i in a:
#     print(relu_(i))

#########################################################
#Softmax function
#will give the Porbability distribution of each classes of outputs
#used to find out the class with max. probability
#can find these functions at the output layer of classifiers
Scores = [12, 8, .3]
def softmax(x):
    return np.exp(x) / np.sum(np.exp(x), axis = 0)
print(softmax(Scores))
print(sum(softmax(Scores)))


