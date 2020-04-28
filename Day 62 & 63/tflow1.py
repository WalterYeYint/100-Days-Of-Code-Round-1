import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import sklearn
from sklearn.datasets import load_boston

#import data
boston = load_boston()
bos = pd.DataFrame(boston.data)
print(bos.head(10))

bos.columns = boston.feature_names
boston.feature_names
#array(['CRIM', 'ZN', 'INDUS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 
#        'TAX', 'PTRATIO', 'B', 'LSTAT'], dtype = 'S7')

bos['PRICE'] = boston.target
Y = bos['PRICE']
X = bos.drop('PRICE', axis = 1)
print(X.head())

#price = intercept + B1*CRIM + B2*Zn...
print(Y.head())

#starting ML from here
from sklearn.linear_model import LinearRegression
X_train, X_test, Y_train, Y_test = sklearn.model_selection.train_test_split(X, Y, test_size = 0.33, random_state = 5)

print(X_train.shape)
print(X_test.shape)
print(Y_train.shape)
print(Y_test.shape)

lm = LinearRegression()

a = lm.fit(X_train, Y_train)

a = 12
b1 = 2
b2 = 32

Y_train_pred = lm.predict(X_train)
#Y = 12 + 2*2 + 32*1

Y_test_pred = lm.predict(X_test)
df = pd.DataFrame(Y_test_pred, Y_test)
print(df)

#Mean square error
from sklearn.metrics import mean_squared_error
mse = mean_squared_error(Y_test, Y_test_pred)
print(mse)

# #mistake somewhere
# from sklearn.metrics import confusion_matrix
# cm = confusion_matrix(Y_test, Y_test_pred)
# cm

#plot the values
fig, ax = plt.subplots()
ax.scatter(Y_test, Y_test_pred)
ax.plot([Y_test.min(), Y_test.max()], [Y_test.min(), Y_test.max()], 'k--', lw = 3)
ax.set_xlabel('Measured')
ax.set_ylabel('Predicted')
plt.show()  

