# Deep Learning Fundamentals - Classic Edition

https://deeplizard.com/learn/video/gZmobeGL0Yg

## 1. Deep Learning playlist ==overview== & Machine Learning intro

### (1) 涵盖内容

- 深度学习和神经网络的基础概念
- 使用 Keras（一种用 Python 编写的神经网络 API）实现这些概念
- 人工神经网络中的层级、激活函数、反向传播、卷积神经网络、数据增强、迁移学习等
- 理解不同的术语的含义，将它们融入深度学习框架
- 通过Python和Keras 用代码中实现一些主题

### (2) 内容大纲

- PART 1: 深度学习入门 
  - Section 1: 人工神经网络基础
    - 机器学习入门
    - 深度学习入门
    - 神经网络架构
    - 训练神经网络
    - 损失率和学习率 Loss and learning rate
  - Section 2: 深度学习的数据主题
    - 深度学习的数据集
    - 用神经网络进行预测
    - 过拟合和欠拟合数据 Over and under fitting data
    - 监督、无监督和半监督学习 Supervised, unsupervised, and semi-supervised learning
    - 数据增强 Data augmentation
    - 独热编码 One-hot encoding
- PART 2: 中级深度学习主题
  - Section 1: 卷积神经网络 Convolutional Neural Networks (CNNs) 
    - 什么是 CNN
    - 可视化卷积滤波器 Visualizing convolutional filters
    - 零填充 Zero padding
    - 最大池化 Max pooling
  - Section 2: 反向传播 Backpropagation 
    -  反向推导直觉 Backprop intuition
    - 反向传播数学 Mathematics of backprop
    - 消失梯度和爆炸梯度 Vanishing and exploding gradient
    - 权重初始化 Weight initialization
  - Section 3: 其他深度学习概念
    - 神经网络中的偏差项 Bias terms in neural networks
    - 可学习参数 Learnable parameters
    - 正则化 Regularization
    - 批次和批次大小 Batches and batch size
    - 微调和迁移学习 Fine-tuning and transfer learning
    - 批次规范化 Batch normalization

### (3) 机器学习概念

#### ① 定义

机器学习是使用算法分析数据、从数据中学习，然后对新数据做出判断或预测的实践。 

#### ② 机器学习&传统编程 

##### A. 传统编程

- 编写逻辑算法，指导计算机在特定数据集上执行
- 机器可以用从未见过的数据完成同样的任务

##### B. 机器学习

- 重点在于 "从数据中学习 "
- 机器<u>不是通过手动编写</u>带有特定指令集的代码来完成特定任务，而是通过数据和算法<u>对机器进行训练</u>，使其具备执行任务的能力，而无需明确告诉它如何去做。

##### C. 举例对比

例：让计算机分析热门媒体的情感态度，并将其分类为积极或消极情感态度

###### a. 传统编程方法 

1. 算法首先查找与负面或正面情绪相关的特定词语

2. 通过条件语句，算法会根据已知的正面或负面词语将文章分类为正面或负面

3. 有了正面和负面示例的列表，一种简单的算法就是简单地计算每种类型的单词在给定文章中的出现次数。 
4. 根据正面例子和负面例子中哪个字数更多，将文章分为正面和负面

==例子由程序员选择==

###### b. 机器学习方法 

1. 算法分析给定的媒体数据，并<u>学习</u>将负面文章与正面文章进行分类的<u>特征</u>，通过所学到的知识，将新文章分为正面和负面
2.  算法会根据每篇文章的标签来 "学习 "某些词是正面的还是负面的。

==程序员不明确指定算法要识别的单词==



## 2. ==Deep Learning== explained

### (1) 深度学习是什么

#### ① 定义

- 深度学习是机器学习的一个子领域，它使用的算法受到大脑神经网络结构和功能的启发，其算法或模型都是基于大脑神经网络的结构和功能
- 深度学习像机器学习一样，仍然是关于从数据中学习的算法

#### ② 人工神经网络

- 深度学习中使用的人工神经网络（artificial neural networks）与生物神经网络有一些共同的特征

- 人工神经网络也叫
  - net                                         
  - neural net                                         
  - model                                         

### (2) 深度学习中的“深度”是什么

#### ① 了解人工神经网络的结构

- 利用**神经元**构建（neurons）
- 人工神经网络中的神经元被组织成**层**（layers）
- 人工神经网络中输入层和输出层除外的各层称为**隐藏层**（hidden layers）

#### ② 如何定义“深度”

如果一个人工神经网络有一个以上的隐藏层，那么这个人工神经网络就被称为<u>深度人工神经网络</u>（deep ANN）

![](https://sevanthea7.oss-cn-beijing.aliyuncs.com/QGworks/202403271700279.png)

## 3. ==Artificial Neural Networks== explained

### (1) ANN是什么

#### ① 定义

- 人工神经网络是一种计算系统，由连接的神经元单元组成，这些单元被组织成层
- 连接的神经元单元构成网络，神经元之间的连接将信号从一个神经元传输到另一个神经元
- 接收到信号的神经元处理信号，继续向网络中与其相连的下游神经元发送信号

#### ② 层的分类

- -神经元通常也被称为节点（nodes），节点被组织成层
- 最高级别的分类上，每个 ANN 有三种层：
  1. 输入层
  2. 隐藏层
  3. 输出层

- 网络的前向传递：不同的层对输入内容进行不同的转换，数据在网络中流动，从输入层开始，经过隐藏层，直到到达输出层。
- 隐藏层：位于输入层和输出层之间的层

#### ③ 不同层包含的节点数量

1. 输入层：输入数据的每个组成部分都有一个节点
2. 隐藏层：每个隐藏层的节点数量可任意选择
3. 输出层：每个可能的预期输出都有一个节点

### (2) 可视化ANN

举例：

![](https://sevanthea7.oss-cn-beijing.aliyuncs.com/QGworks/202403271718529.png)

- 结构
  - 共三层，左边一层是输入层，右边一层是输出层，中间一层是隐藏层
  - 每一层都由神经元或节点组成，节点用圆圈表示

- 每层的节点数
  - 输入层：2（该网络的每个输入必须有两个维度，例如身高+体重）
  - 隐藏层：3 
  - 输出层：2 （通过该网络向前传递的每个输入都有两个可能的输出类别，例如超重/体重不足。输出类也称为预测类）

### (3) Keras 序列模型

#### ① 为什么用Keras模型

Keras可以构建顺序模型，它将顺序模型定义为线性层的顺序堆栈，这与按层组织的神经元模型相符，所以用它可以实现构造人工神经网络

#### ② 基本的模型定义示例

1. 导入所需的Keras类

```python
from keras.models import Sequential
from keras.layers import Dense, Activation
```

2. 创建一个名为`model`的变量，并将其设置为`Sequential`对象的实例

```python
model = Sequential(layers)
```

3. 构造函数，传递一个叫`Dense`的对象数组，作为层

```python
layers = [
    Dense(units=3, input_shape=(2,), activation='relu'),
    Dense(units=2, activation='softmax')
]
```

- Dense一词表示这些层属于`Dense`类型(type)

- `Dense`是一种最基本的层类型，还有许多其他类型

- `Dense`层的每个输出都是通过该层的每个输入计算得出的

  ![](https://sevanthea7.oss-cn-beijing.aliyuncs.com/QGworks/202403271718529.png)

  - 从隐藏层到输出层的箭头可知隐藏层中的每个节点都与输出层中的所有节点相连 --> 隐藏层、输出层都是`Dense`层

4. 传入形状参数，输入层有多少个神经元就传递相应形状参数给每个`Dense`层构造函数 如本例有两个神经元： `input_shape=(2,)`

5. 激活函数的参数

```python
activation='relu'
activation='softmax'
```

- 激活函数是一个非线性函数，通常遵循`Dense`层

## 4. ==Layers== in a Neural Network explained

### (1) ANN中的层

#### ① 多类型的层

- 密集层（全连接层） Dense (or fully connected) layers
- 卷积层 Convolutional layers
- 池化层 Pooling layers
- 递归层 Recurrent layers
- 归一化层 Normalization layers

#### ② 层多类型的意义

不同的层对输入可以进行不同的转换，特定的层会更适合特定任务，例如：

- 卷积层常用于处理图像数据的模型
- 递归层常用于处理时间序列数据的模型
- 全连接层常用于需要将层内的每个输入完全连接到每个输出的模型

### (2) ANN图解示例

![](https://sevanthea7.oss-cn-beijing.aliyuncs.com/QGworks/202403271700279.png)

#### ① 输入层

- 由八个节点组成，八个节点分别代表数据集中给定样本的一个特征
  - 即数据集中的单个样本由八个维度组成
- 从数据集中选择一个样本传递给模型时，样本中包含的八个值中的每一个都将提供给输入层中的对应节点
- 八个输入节点都与下一层的每个节点相连，两层之间的每个连接都会将前一个节点的输出传送到下一个节点的输入

#### ② 层权重

相对于隐藏层来讲

##### a. 权重的定义

每两个节点之间的连接都有一个相关的权重（一个数字），它代表两个节点之间连接的强度

##### b. 权重的意义

- 当网络在输入层的某个节点接收到输入时，该**输入会乘以分配给该连接的权重**,通过连接传递到下一个节点

- 对于第二层中的每个节点，都会计算每个输入连接的加权和，然后将该和传递给激活函数，激活函数会对给定的和进行某种转换
  - 如激活函数可将总和转换为介于 0 和 1 之间的数字
  - 实际变换会根据使用的激活函数而有所不同

##### c. 使用

节点输出 = 激活函数( 输入加权和 )

##### d. 找到最佳权重

随着模型的学习，所有连接的权重都会得到更新和优化，从而使输入数据点映射到正确的输出预测类别

#### ③ 神经网络的前向传递

##### a. 过程

- 当得到了某个节点的输出时，这个输出值就会作为输入传入下一层的节点，这一过程一直持续到输出层

- 输出层的节点数量取决于可能的输出或预测类别的数量
  - 分类或类别取决于我们的数据集样本中的内容要分成多少个类别
  - 示例图中有四个可能的预测类别
    - 假设对四种动物进行分类，输出层的每个节点将代表四种可能性中的一种
    - 如猫、狗、骆驼、蜥蜴

##### b. 定义

对于数据集中的给定样本，从输入层到输出层的整个过程称为网络的前向传递。

### (3) 使用Keras在代码中定义神经网络

![](https://sevanthea7.oss-cn-beijing.aliyuncs.com/QGworks/202403271700279.png)

1. 导入必要的库

   ~~~python
   from keras.models import Sequential
   from keras.layers import Dense, Activation
   ~~~

2. 定义一个`Dense`层，然后将此层<u>列表</u>传递给顺序模型的构造函数

   ~~~python
   layers = [
       Dense(units=6, input_shape=(8,), activation='relu'),
       Dense(units=6, activation='relu'),
       Dense(units=4, activation='softmax')
   ]
   ~~~

   - 列表中指定的第一个`Dense`对象并不是输入层，第一个`Dense`对象是隐藏层，它构造函数的参数才输入层(即`input_shape=(8,)`)
     - 输入层形状：8
     - 隐藏层1节点数：6（激活函数：relu）
     - 隐藏层2节点数：6（激活函数：relu）
     - 输出层：4（激活函数：softmax）
   - layers定义的是一个列表

3. 创建一个名为`model`的变量，并将其设置为`Sequential`对象的实例

```python
model = Sequential(layers)
```

## 5. ==Activation Functions== in a Neural Network explained

### (1) 神经网络中的激活函数

#### ① 激活函数是什么

##### A. 定义

在人工神经网络中，激活函数是将节点的输入映射到相应输出的函数

##### B. 使用

节点输出 = 激活函数( 输入加权和 )

- 激活函数会进行某种运算，将总和转换为一个数字，这个数字通常介于某个下限和某个上限之间
- 这种变换通常是非线性变换

#### ② 激活函数有什么用

##### A. 示例：Sigmoid激活函数

$$
sigmoud(x) = \frac{e^x}{e^x+1}
$$

Sigmoid函数会接收输入并执行以下操作：

- 对于大多数负输入，sigmoid 会将输入转化为一个非常接近 0 的数字
- 对于大多数正输入，sigmoid 会将输入转化为一个非常接近 1 的数字
- 对于相对接近 0 的输入，sigmoid 会将输入变换成介于 0 和 1 之间的数字

所以这个函数的上限是1，下限是0

##### B.  激活函数直觉

###### a. 生物学示例

激活函数的生物学灵感来源于我们大脑中的活动，不同的刺激会激发不同的神经元

如：

- 闻到令人愉悦的饼干气味，大脑中的某些神经元就会兴奋

- 如果你闻到不愉快的变质牛奶气味，就会导致大脑中的其他神经元兴奋

在大脑中，神经元要么激活要么不激活，即要么为1要么为0

###### b. ANN中应用示例

通过人工神经网络中的 Sigmoid 激活函数可以看到，神经元的激活程度可以介于 0 和 1 之间，越接近 1，神经元的激活程度越高，而越接近 0，神经元的激活程度越低。

##### C. Relu激活函数

- 激活函数并不总是要对输入进行转换使输出介于 0 和 1 之间

- 最广泛使用的激活函数之一 ReLU 就不这样
  - ReLU 是整流线性单元的简称，它将输入转化为 0 或输入本身的最大值
    - 输入小于或等于 0，relu 将输出 0
    - 输入大于 0，relu将输出<u>输入的内容</u>

$$
relu(x) = max(0,x)
$$

- 即神经元的正向性越强，它就越被激活

### (2) 为什么使用激活函数

#### ① 深度学习对于非线性映射的需要

线性函数的一个重要特征是，两个线性函数的组合也是一个线性函数。所以如果在深度神经网络中，前向传递过程中只对数据值进行线性变换，那么网络中从输入到输出的学习映射也将是线性的。

而对通过深度神经网络学习的映射类型的期望要比简单的线性映射更为复杂。

#### ② 激活函数的作用

大多数激活函数都是非线性且是有意选择的，非线性激活函数允许我们的神经网络计算任意复杂的函数，达到复杂映射的期望。

### (3) Keras代码中的激活函数

1. 导入必要的库

   ~~~python
   from keras.models import Sequential
   from keras.layers import Dense, Activation
   ~~~

2. 指定激活函数

   a. 方法1，直接构造时指定

   ~~~
   model = Sequential([
       Dense(units=5, input_shape=(3,), activation='relu')
   ])
   ~~~

   b. 方法2，模型实例化后添加

   ~~~
   model = Sequential()
   model.add(Dense(units=5, input_shape=(3,)))
   model.add(Activation('relu'))
   ~~~

3. 结果预测

   节点输出 = 激活函数( 输入加权和 )

   ​					:arrow_down:
   节点输出 = relu( 输入的加权和 )

## 6. ==Training== a Neural Network explained

### (1) 训练是什么

#### ① 目的

训练模型的目的是优化模型中的权重，要找到最准确地将输入数据映射到正确输出类别的权重，在训练过程中，这些权重会反复更新，并逐渐趋向最佳值。

#### ② 过程

用于训练的每个数据点经过网络，在从输入到输出的网络前向传递，最终输出结果取决于网络内部每个连接的权重。

### (2) 优化算法

- 权重的优化是通过优化算法实现的

- 优化过程取决于所选的优化算法(optimizer)，最常见是随机梯度下降算法(SGD)
- SGD的优化目标是最小化损失函数，这个过程中SGD不断更新模型权重，使损失函数尽可能的小

### (3) 损失函数

#### ① 损失

损失是网络对图像的预测结果与图像真实标签之间的误差或差异，SGD将尽量减小这一误差，使模型预测尽可能准确。

#### ② 过程

1. 向模型提供数据和与数据的对应标签

2. 为模型提供猫和狗的图像以及标签，说明每张图像是猫还是狗

3. 给模型提供一张图像，前向传递完成后，这个图像数据流经网络，模型将在最后提供一个输出：模型认为图像是猫还是狗

4. 输出结果将由猫或狗的概率组成，如：
   - 75%的几率是猫
   - 25%的几率是狗

5. 所有数据传递给模型后，模型重复传递相同的数据。 这种通过网络反复传递相同数据的过程被视为训练。

## 7. How a Neural Network ==Learns== explained

### (1) 人工神经网络的学习

- 一轮训练(epoch)：整个数据集传递给网络，数据集中的所有数据点都通过网络

- 随着模型的学习，在整个训练过程中会出现很多次epoch

#### ① 学习意味着什么

1. 模型初始化时，网络的权重被设置为任意值

2. 在网络结束时，模型将为给定输入提供输出

3. 得到输出后，通过观察模型预测结果与真实标签的对比，所选的损失函数就可以计算出该特定输出的误差

#### ② 损失函数梯度

4. 计算出损失后，根据网络中的每个权重计算出该损失函数的梯度，梯度是多个变量函数的导数

5. 接下来只关注模型中的一个权重，已知单个输出的损失与该损失相对于所选单个权重的梯度（其中的计算叫反向传播 backpropagation）

6. 得到损失函数的梯度值后，就可以使用该值更新模型的权重：梯度表现出哪个方向会使损失趋于最小值，所以目标就是朝着降低损失的方向一步步接近这个最小值

#### ③ 学习率

- 学习率是介于 0.01 和 0.0001 之间的小数，它表明应该朝着最小值的方向迈多大的步子

#### ④ 更新权重

$$
new\quad weight = old \quad weight - (learning rate * gradient)
$$

7. 将梯度与学习率相乘，再从权重中减去这个乘积，得到的就是权重的新更新值

- 这里只关注了一个权重，但每次数据通过时，模型中的每个权重都会进行相同的操作过程
  - 唯一不同的是，在计算损失函数的梯度时，每个权重的梯度值都会不同，因为梯度是针对每个权重计算出来的
  - 所有这些权重都会在每个时间点进行迭代更新，这些更新即表面模型在学习

### (2) 用Keras与代码进行训练

1. 导入必要的库

   ~~~python
   import keras
   from keras.models import Sequential
   from keras.layers import Activation
   from keras.layers.core import Dense
   from keras.optimizers import Adam
   from keras.metrics import categorical_crossentropy
   ~~~

2. 创建模型

   ~~~python
   model = Sequential([
       Dense(units=16, input_shape=(1,), activation='relu'),
       Dense(units=32, activation='relu'),
       Dense(units=2, activation='sigmoid')
   ])
   ~~~

3. 训练前先编译

   ~~~python
   model.compile(
       optimizer=Adam(learning_rate=0.0001), 
       loss='sparse_categorical_crossentropy', 
       metrics=['accuracy']
   )
   ~~~

- `compile()`函数中，我们传递了优化函数、损失函数和我们希望看到的指标
- 我们指定的优化器名为 Adam，它是 SGD 的一个变体，
  - 在Adam构造函数中指定学习率
  - `Adam(learning_rate=.0001)`，即学习率为0.0001。

4. 将模型与数据拟合，即在数据上训练模型

   ~~~python
   model.fit(
       x=scaled_train_samples, 
       y=train_labels, 
       batch_size=10, 
       epochs=20, 
       shuffle=True, 
       verbose=2
   )
   ~~~

- `scaled_train_samples`是一个由<u>训练样本</u>组成的`numpy`数组
- `train_labels`是一个由<u>训练样本的相应标签</u>组成的`numpy`数组。

- `batch_size=10`表示应一次性向模型发送多少训练样本
- `epochs=20`表示完整的训练集（所有样本）将<u>总共</u>传递给模型 20 次

- `shuffle=True`表示在将数据传递给模型之前先把它打乱

- `verbose=2`表示在模型训练过程中输出多少日志记录

5. 运行结果

   ~~~
   Epoch 1/20 0s - loss: 0.6400 - acc: 0.5576
   Epoch 2/20 0s - loss: 0.6061 - acc: 0.6310
   Epoch 3/20 0s - loss: 0.5748 - acc: 0.7010
   Epoch 4/20 0s - loss: 0.5401 - acc: 0.7633
   Epoch 5/20 0s - loss: 0.5050 - acc: 0.7990
   Epoch 6/20 0s - loss: 0.4702 - acc: 0.8300
   Epoch 7/20 0s - loss: 0.4366 - acc: 0.8495
   Epoch 8/20 0s - loss: 0.4066 - acc: 0.8767
   Epoch 9/20 0s - loss: 0.3808 - acc: 0.8814
   Epoch 10/20 0s - loss: 0.3596 - acc: 0.8962
   Epoch 11/20 0s - loss: 0.3420 - acc: 0.9043
   Epoch 12/20 0s - loss: 0.3282 - acc: 0.9090
   Epoch 13/20 0s - loss: 0.3170 - acc: 0.9129
   Epoch 14/20 0s - loss: 0.3081 - acc: 0.9210
   Epoch 15/20 0s - loss: 0.3014 - acc: 0.9190
   Epoch 16/20 0s - loss: 0.2959 - acc: 0.9205
   Epoch 17/20 0s - loss: 0.2916 - acc: 0.9238
   Epoch 18/20 0s - loss: 0.2879 - acc: 0.9267
   Epoch 19/20 0s - loss: 0.2848 - acc: 0.9252
   Epoch 20/20 0s - loss: 0.2824 - acc: 0.9286
   ~~~

    输出结果为我们提供了每个epoch的以下数值：

   - 训练轮数编号 Epoch number
   - 持续时间 Duration in seconds
   - 损失 Loss
   - 精确度 Accuracy

   可见随着时间的推移，损失减少，准确率上升

## 8. ==Loss== in a Neural Network explained

###  (1) 神经网络中的损失函数

- 之前提到的SGD中，一直在试图最小化损失函数来优化权重

- 在训练过程中的每个epoch结束时，将使用网络的输出预测和相应输入的真实标签来计算损失
- 例：
  - 假设用模型对猫和狗的图像进行分类，猫的标签为 0，狗的标签为 1
  - 假设向模型传递了一张猫的图像，而模型提供的输出结果是$0.25$，此时模型的预测值与真实标签之间的差值为$0.25-0.00=0.25$
  -  这个差值也称为误差

### (2) 均方误差 (Mean squared error, MSE)

#### ①  误差计算思路

- 对单个样本使用 MSE
  1. 计算输出预测值与标签之间的差值( 误差 )
  2. 将误差平方

$$
MSE(input) = (output-label)(output-label)
$$

- 多个样本使用 MSE
  - 取所有这些样本的平方误差的平均值

- 除了MSE，还有多种不同的损失函数，但是这个计算单个样本误差的思路对所有类型的损失函数都适用

#### ② 进行计算的时刻

- 整个训练集一次性传递给模型：那么刚才计算损失的过程将在训练过程中的每轮训练结束时进行
- 训练集分成若干批次依次传递给模型：那么损失将在每个批次结束后计算

### (3) Keras代码中的损失函数

~~~python
import keras
from keras.models import Sequential
from keras.layers import Activation
from keras.layers.core import Dense
from keras.optimizers import Adam
from keras.metrics import categorical_crossentropy

model = Sequential([
    Dense(16, input_shape=(1,), activation='relu'),
    Dense(32, activation='relu'),
    Dense(2, activation='sigmoid')
])

model.compile(
    Adam(learning_rate=.0001), 
    loss='sparse_categorical_crossentropy', 
    metrics=['accuracy']
)
~~~

- 这里指定的损失函数是`loss='sparse_categorical_crossentropy'`

## 9. ==Learning Rate== in a Neural Network explained

### (1) 学习率和神经网络

#### ① 学习率介绍

- 训练过程中，SGD的目标是尽量减少实际输出与训练样本预测输出之间的损失，实现损失最小化
  - 任意设定的权重开始训练，随着越来越接近最小化损失，权重逐步更新

- 为达到最小化损失而采取步骤的大小将取决于学习率，可以把它看作步长( step size )
  1. 计算损失
  2. 计算出该损失相对于模型中每个权重的梯度
  3. 梯度*学习率

#### ② 更新网络权重

4. **新权重 = 旧权重 - ( 梯度*学习率 )**

- 舍弃之前为每个连接设置的权重并用这些新值更新

- 选择的学习率值前，需要先进行一些测试来权衡它的大小
  - 学习率是超参数( hyperparameters，是事先给定的、用来控制学习过程的参数 )，我们必须对每个模型进行测试和调整，然后才能知道我们想要设置的确切位置，但如前所述，
  - 一般将其设置在 0.01 到 0.0001 之间。
    - 学习率较高，我们就有可能出现超调( overshooting )，最小化损失函数的方向上的步长过大时，就会出现这种情况
    - 学习率较低，步长会非常小，需要更长的时间才能达到损失最小点

### (2) Keras中的学习率 

~~~python
model = Sequential([
    Dense(units=16, input_shape=(1,), activation='relu'),
    Dense(units=32, activation='relu', kernel_regularizer=regularizers.l2(0.01)),
    Dense(units=2, activation='sigmoid')
])

model.compile(
    optimizer=Adam(learning_rate=0.0001), 
    loss='sparse_categorical_crossentropy', 
    metrics=['accuracy']
)
~~~

1. 指定优化器，使用 Adam 作为该模型的优化器。

2. 指定`learning_rate`参数，向优化器传递学习率，这里为0.0001

   - `learning_rate`参数是可选的，如果不明确设置它，就会被设置成 Keras 分配给这个特定优化器的默认学习率

   - 另一种指定方法：编译模型后，通过 `model.optimizer.learning_rate`设置

     ~~~python
     model.optimizer.learning_rate = 0.01
     ~~~

## 10. Train, Test, & Validation ==Sets== explained

### (1) 深度学习的数据集

为了训练和测试模型，数据分成三个不同的数据集：

- 训练集
- 验证集
- 测试集

#### ① 训练集

- 训练集是用于训练模型的数据集
- 在每个epoch期间，模型将在训练集中的相同数据上反复训练、不断学习这些数据的特征
- 训练后，模型可以根据所学到的训练数据对它从未见过的新数据进行预测

#### ② 验证集

- 验证集是一组独立于训练集的数据，用于在训练过程中验证我们的模型，提供帮助我们调整超参数( 学习率 )的信息

- 在每轮训练的过程中，模型都将对训练集中的数据进行训练，同时还将在验证集的数据上进行验证

- 过程
  1. 模型将对训练集中的每个输入进行输出分类，也将对验证集中的每个输入进行分类
  2. 计算损失，仅根据训练集的损失调整模型中的权重，不会根据验证集的损失进行更新
  3. 新一轮训练，再次对相同的输入进行分类

- <u>验证集的数据与训练集的数据是分开的</u>，所以当模型在这些数据上进行验证时，这些数据里并不包含模型在训练中已经熟悉的样本

- 在验证集上对模型进行验证
  - 模型没有过拟合：模型在验证数据上得到的结果与在训练数据上得到的结果一样好
  - 模型过拟合：训练数据的结果非常好，但验证数据的结果却落后于训练数据模型
- 验证集展现模型在<u>训练过程中</u>的泛化效果

#### ③ 测试集

- 测试集是一组用于在模型训练完成后对模型进行测试的数据，与训练集和验证集是分开的

- 使用训练集和验证集对我们的模型进行训练和验证后，就使用这个模型来预测测试集中未标记数据的输出

- 与其他两个集的一个主要区别：训练集和验证集必须有标记，而测试集无标记
  - 这样才能看到训练过程中得到的指标，比如每个历时的损失和准确率。

- 测试集展现模型在<u>最终</u>的泛化效果

### (2) 总结

| 数据集 | 更新权重 | 描述                                                     |
| ------ | -------- | -------------------------------------------------------- |
| 训练集 | 是       | 用于训练模型，使模型适合训练集，同时能泛化到未见过的数据 |
| 验证集 | 否       | 用于在训练过程中检查模型的泛化程度                       |
| 测试集 | 否       | 用于测试模型的最终泛化能力                               |

- 最终目标：使模型能在事先不知道数据是什么的情况下完成分类

- 机器学习和深度学习的最终目标是建立能够很好泛化的模型