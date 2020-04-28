#import the required libraries
import matplotlib.pyplot as plt
import tensorflow as tf
import numpy as np
import pandas as pd
from sklearn.preprocessing import LabelEncoder
from sklearn.utils import shuffle
from sklearn.model_selection import train_test_split

#function to read the sonar dataset
def read_dataset():
    df = pd.read_csv("sonar.csv")
    print(len(df.columns))
    X = df[df.columns[1:60]].values
    y = df[df.columns[60]]
    #encode the dependent variable, single it has more than one class
    encoder = LabelEncoder()
    encoder.fit(y)
    y = encoder.transform(y)
    Y = one_hot_encode(y)
    return(X, Y, y)

#normalise the features of the dataset
def feature_normalize(features):
    mu = np.mean(features, axis = 0)
    sigma = np.std(features, axis = 0)
    normalize_features = (features - mu) / sigma
    return(normalize_features)

#appending the bias
def append_bias_reshape(features):
    n_training_samples = features.shape[0]
    n_dim = features.shape[1]
    features = np.reshape(np.c_[np.ones(n_training_samples)])