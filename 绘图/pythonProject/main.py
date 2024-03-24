import pandas as pd
import matplotlib.pyplot as plt

# 读取CSV文件
# df = pd.read_csv('D:\HuaweiMoveData\Users\weiweiwei\Desktop')  # 替换为你的CSV文件路径
df = pd.read_csv('D:/HuaweiMoveData/Users/weiweiwei/Desktop/链路优化.csv',encoding='UTF-8')
# 假设你的CSV文件有多列，第一列是x轴数据，后面的列是各条折线的y轴数据
x = df.iloc[:, 0]  # 取第一列作为x轴数据
y1 = df.iloc[:, 1]  # 取第二列作为第一条折线的y轴数据
y2 = df.iloc[:, 2]  # 取第三列作为第二条折线的y轴数据
y3 = df.iloc[:, 3]  # 取第二列作为第一条折线的y轴数据
y4 = df.iloc[:, 4]  # 取第三列作为第二条折线的y轴数据
# # 如果还有更多折线，继续按此方式读取数据
y5= df.iloc[:, 5] # 取第二列作为第一条折线的y轴数据
# y6= df.iloc[:, 6]
# y7= df.iloc[:, 7]
# y8= df.iloc[:, 8]
# y9= df.iloc[:, 12]
# y10= df.iloc[:, 13]
# y11= df.iloc[:, 14]
# 绘制折线图
plt.plot(x, y1, label='two ways', marker='o')  # 绘制第一条折线并显示数据点，'o'代表圆圈标记
plt.plot(x, y2, label='four ways', marker='x')
plt.plot(x, y3, label='six ways', marker='s')  # 绘制第一条折线并显示数据点，'o'代表圆圈标记
plt.plot(x, y4, label='eight ways', marker='^')
plt.plot(x, y5, label='sixteen ways', marker='*')
# plt.plot(x, y6, label='arm_optimization_2way', marker='v')
# plt.plot(x, y7, label='arm_optimization_recursion', marker='o')
# plt.plot(x, y8, label='arm_optimization_circulation', marker='x')
# plt.plot(x, y9, label='2ways', marker='o')
# plt.plot(x, y10, label='recursion', marker='s')
# plt.plot(x, y11, label='circulation', marker='*')

# 如果还有更多折线，继续调用plt.plot()函数进行绘制

# 设置图表标题和坐标轴标签
# plt.title('Multi-platform algorithm performance comparison')
plt.title('X86 algorithm performance accelerate rate')
plt.xlabel('n')
plt.ylabel('accelerate rate/%')
#plt.ylim(0.9,6 )
# 显示图例
plt.legend()

# 显示图表
plt.show()