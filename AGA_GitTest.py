# USING ARTIFICIAL NEURAL NETWORK
import numpy as np
import pandas as pd
import tensorflow as tf
import matplotlib.pyplot as plt

# Importing Dataset
dataset = pd.read_excel('generation_data.xlsx')
dataset=dataset.drop(columns=['Generation'])
X = dataset.iloc[:,:-1].values
y = dataset.iloc[:,-1].values

# Reporting DataSet
print(X)
print(y)

# Splitting the dataset into the Training set and Test set

from sklearn.model_selection import train_test_split
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state = 0)

# Feature Scaling
from sklearn.preprocessing import StandardScaler
sc = StandardScaler()
X_train = sc.fit_transform(X_train)
X_test = sc.transform(X_test)

#Building ANN

from tensorflow.keras.models import Sequential
ann = Sequential()
# Adding 2 Input and 2 Hidden Layer
ann.add(tf.keras.layers.Dense(units=6, activation='relu'))
ann.add(tf.keras.layers.Dense(units=6, activation='relu'))
ann.add(tf.keras.layers.Dense(units=1))
ann.add(tf.keras.layers.Dense(units=1))


# Adding Output Layer
ann.add(tf.keras.layers.Dense(units=1, activation='sigmoid'))


# Compiling ANN
ann.compile(optimizer = 'adam', loss = 'binary_crossentropy' , metrics=['accuracy'])

# Training the ANN model on the Training set
ann.fit(X_train, y_train, batch_size = 12, epochs = 200)


# Predicting the for Single Observation
y_pred=ann.predict(sc.transform([[ 0.5,5.853763,39.508798,8189.668474,5093.404661]]))
print(y_pred)

y_pred = ann.predict(X_test)
np.set_printoptions(precision=2)
print(np.concatenate((y_pred.reshape(len(y_pred),1), y_test.reshape(len(y_test),1)),1))


# Evaluating the Model Performance
from sklearn.metrics import r2_score
r2 = r2_score(y_test, y_pred)
print("R-squared:", r2)

# Visulization
from sklearn.metrics import mean_squared_error, r2_score
import matplotlib.pyplot as plt