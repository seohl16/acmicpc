import numpy as np
import tensorflow as tf

x_train = [1, 2, 3, 4] # 정의역
y_train = [0, -1, -2, -3] # 치역

tf.model = tf.keras.Sequential()
# units == output shape, input_dim == input shape
tf.model.add(tf.keras.layers.Dense(units=1, input_dim=1))

sgd = tf.keras.optimizers.SGD(lr=0.1)  # SGD == standard gradient descendent, lr == learning rate
#sgd 기울기가 가장 작을 때

tf.model.compile(optimizer=sgd, loss='mse')  # mse == mean_squared_error, 1/m * sig (y'-y)^2
# Optimizer - sgd, adam, rmsprop
# Loss Function - mse
# Metrics - accruracy 등

# prints summary of the model to the terminal
tf.model.summary()
"""
_________________________________________________________________
Layer (type)                 Output Shape              Param #
=================================================================
dense (Dense)                (None, 1)                 2
=================================================================
Total params: 2
Trainable params: 2
Non-trainable params: 0
"""


# fit() executes training
tf.model.fit(x_train, y_train, epochs=200)
# Epochs 200번 반복
# batch_size 가중치 갱신 시점

# predict() returns predicted value
y_predict = tf.model.predict(np.array([5, 4]))
print(y_predict)

"""
Epoch 199/200
1/1 [==============================] - 0s 1ms/step - loss: 2.7446e-06
Epoch 200/200
1/1 [==============================] - 0s 1ms/step - loss: 2.5826e-06
[[-3.9973278]
 [-2.998625 ]]
"""
