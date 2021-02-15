"""tensorflow mechanics
1. build graph using tensorflow operations
2. session run = feed data and run graph(operation)
sess.run(op)
3. update variables and return values
"""

import tensorflow.compat.v1 as tf
tf.disable_v2_behavior()
#computational graph

#(1) build graph (tensors) using tensorflow operations
node1 = tf.constant(3.0, tf.float32)
node2 = tf.constant(4.0)
node3 = tf.add(node1, node2)
#(2) feed data and run graph (operaton)
sess = tf.Session()
print(sess.run([node1, node2]))
print(sess.run(node3))

a = tf.placeholder(tf.float32)
b = tf.placeholder(tf.float32)
adder_node = a + b
print(sess.run(adder_node, feed_dict = {a : 3, b : 4.5}))
print(sess.run(adder_node, feed_dict = {a : [1,3], b : [2,4]}))
"""
[3.0, 4.0]
7.0

7.5
[3. 7.]


print(sess.run([node1, node2])
... )
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "/Users/selimmac/Library/Python/3.8/lib/python/site-packages/tensorflow/python/client/session.py", line 967, in run
    result = self._run(None, fetches, feed_dict, options_ptr,
  File "/Users/selimmac/Library/Python/3.8/lib/python/site-packages/tensorflow/python/client/session.py", line 1116, in _run
    raise RuntimeError('The Session graph is empty.  Add operations to the '
RuntimeError: The Session graph is empty.  Add operations to the graph before calling run().
>>>
"""

# tensor array를 의미한다.
# rank 차원 shape 0 차원 1차원
# shape 모양 [] 로 이용해서 보여줌 [3, 3] 이면 이중 배열 3 * 3 개 있음
# type float~ int32 등 까지

