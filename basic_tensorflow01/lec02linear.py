"""
predicting exam score : regression 학습 시킨다. 줄
x 는 자료 y 는 결과

간단하게 그래프로 그리면 이렇게 1,1 2,2 3,3 각각 점을 찍을 수 있다.

linear hypothesis
세상한 많은 사례들이 이렇게 드러난다. 증가-> 증가

H(x) = Wx + b
선의 모양은 w, b의 값에 따라 달라지겠죠

어떤 선이 잘 맞는 선일까? 당연 이 경우에는 1,1 2,2 3,3을 지나는 선이 최고

Cost function : how fit the line to our (training) data
우리 가설과 실제 데이터가 얼마나 다른지 계산해주는 함수
가장 처음에는 H(x) - y 하지만 음수 양수 구별을 못한다.
다음으로 (h(x) - y ) ^ 2 이건 잘 표현할 수 있지

일반화한다면
cost = 1/m * E ( H(x) - y ) ^ 2
H(x) = wx + b

cost(W, b) 에서 wb 를 최소화 하는 것이 중요
minimize cost(w, b)

"""

import tensorflow.compat.v1 as tf
tf.set_random_seed(777)  # for reproducibility
with tf.compat.v1.Session() as sess:
  x_train = [1,2,3]
  y_train = [1,2,3]

  W = tf.Variable(tf.random_normal([1]), name='weight')
  b = tf.Variable(tf.random_normal([1]), name='bias')
  # trainable한 변수라고 보면 좋을 듯

  hypothesis = x_train * W + b
  cost = tf.reduce_mean(tf.square(hypothesis - y_train))


  optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
  train = optimizer.minimize(cost)

  # Run and update graph
  sess = tf.Session()
  #sess.run(tf.initialize_all_variables())
  sess.run(tf.global_variables_initializer())
  for step in range(2001):
    sess.run(train)
    if step % 20 == 0: # 0 20 40 ... 1980 2000
        print(step, sess.run(cost), sess.run(W), sess.run(b))
# Learns best fit W:[ 1.],  b:[ 0.]
"""
0 2.82329 [ 2.12867713] [-0.85235667]
20 0.190351 [ 1.53392804] [-1.05059612]
40 0.151357 [ 1.45725465] [-1.02391243]
...
1960 1.46397e-05 [ 1.004444] [-0.01010205]
1980 1.32962e-05 [ 1.00423515] [-0.00962736]
2000 1.20761e-05 [ 1.00403607] [-0.00917497]
"""

