import numpy as np
from numpy.random import randn
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

def draw_1():
    plt.plot([3,1,4,5,2])
    plt.ylabel('grade')
    plt.savefig('test',dpi = 600)
    plt.show()

def draw_2():
    data = np.arange(10)
    draw = (plt.plot(data))
    #创建数组
    plt.show()

def draw_3():
    fig = plt.figure()
    #创建空图像
    
    ax1 = fig.add_subplot(2,2,1)
    
    ax2 = fig.add_subplot(2,2,2)
    
    ax3 = fig.add_subplot(2,2,3)

    #不能直接通过空figure绘图，需要创建多个subplot。意为图像是2×2的，编号是第N个。
    #此处无说明时，会在最后一个用过的图上绘制
    
    plt.plot(np.random.randn(50).cumsum(),'k--')
    #k--是指黑色虚线图

    ax1.hist(np.random.randn(100),bins = 20,color = 'k', alpha = 0.3)

    ax2.scatter(np.arange(30),np.arange(30) + 3 * np.random.randn(30))

    #直接调用可以在指定的图上绘制

    fig,axes = plt.subplots(2,3)
    #创建一个新的Figure，并返回一个含有已创建的subplot对象的NumPy数组

    print(axes)
    
    plt.show()

def draw_4():
    #for i in range(2):
        #for j in range (2):
            #axes[i,j].hist(randn(500),bins = 50,color = 'k', alpha = 0.5)
    #plt.subplots_adjust(wspace = 0, hspace = 0)
    #ax.plot(x,y,linestyle = '--', color = 'g')
    #plt.plot(randn(30).cumsum(),'ko--')使用标记强调数据点
    #或者：plt.plot(randn(30).cumsum(),color = 'k',linestyle = 'dashed',marker = 'o')
    #subplots_adjust(left = None, bottom = None, right = None, top = None, wspace = None, hspace = None)修改间距
    
    #ax.plot(x,y,'g--')
    #ax.plot(x,y,linestyle = '--', color = 'g')
    
    data = randn(30).cumsum()

    plt.plot(data,'k-',label = 'Default')
    plt.plot(data,'k-',drawstyle = 'steps-post',label = 'steps-post')

    plt.show()

def draw_5():
    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)
    ax.plot(np.random.randn(1000).cumsum())

    ticks = ax.set_xticks([0,250,500,750,1000])
    #要将刻度放在数据范围中的哪些位置，默认情况下，这些位置也就是刻度标签。
    
    ticks = ax.set_yticks([0,250,500,750,1000])
    labels = ax.set_xticklabels(['one','two','three','four','five'],rotation = 90,fontsize = 'small')
    #通过set_xticklabels将任何其他的值用作标签，rotation选项设定x刻度标签倾斜30度

    title = ax.set_title('My Matplotlib Plot')
    xlabel = ax.set_xlabel('Stages')
    #用set_xlabel为X轴设置一个名称，并用set_title设置一个标题

    fig,axes = plt.subplots(2,2,sharex = True, sharey = True)


   
    plt.show()

def draw_6():
    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)
    
    ax.plot(np.random.randn(1000).cumsum(),'k',label = 'one')
    ax.plot(np.random.randn(1000).cumsum(),'k--',label = 'two')
    ax.plot(np.random.randn(1000).cumsum(),'k.',label = 'three')
    #分别创建图例

    text = ax.text(500,5,'Hello World!', family = 'monospace', fontsize = 10)
    #将文本绘制在图表的指定坐标(x,y)，还可以加上一些自定义格式
    
    
    ax.legend(loc = 'best')
    #自动创建图例

    plt.savefig('figpath.svg')
    #利用plt.savefig可以将当前图表保存到文件。


    plt.show()

def draw_7():
    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)

    rect = plt.Rectangle((0.2,0.75),0.4,0.15,color = 'k',alpha = 0.3)
    circ = plt.Circle((0.7,0.2),0.15,color = 'b',alpha = 0.3)
    pgon = plt.Polygon([[0.15,0.15],[0.35,0.4],[0.2,0.6]],color = 'g',alpha = 0.5)

    ax.add_patch(rect)
    ax.add_patch(circ)
    ax.add_patch(pgon)

    #创建一个块对象shp，然后通过ax.add_patch(shp)将其添加到subplot中
    plt.show()


    plt.savefig('figpath.png',dpi = 400   , bbox_inches = 'tight')
    #dpi（控制“每英寸点数”分辨率）和bbox_inches（可以剪除当前图表周围的空白部分）

def draw_8():
    s = pd.Series(randn(10).cumsum(),index = np.arange(0,100,10))
    s= s.plot()
    #默认情况下，它们所生成的是线型图.

    plt.show()
    

def draw_9():
    df = pd.DataFrame(randn(10,4).cumsum(0),columns = ['A','B','C','D'],index = np.arange(0,100,10))
    df = df.plot()
    #DataFrame的plot方法会在一个subplot中为各列绘制一条线，并自动创建图例
    
    plt.show()

def draw_10():
    fig,axes = plt.subplots(2,1)

    data = pd.Series(pd.random.rand(16),index = list('abcdefghijklmnop'))

    data.plot.bar(ax = axes[0], color = 'k', alpha = 0.7)

    data.plot.barh(ax = axes[1], color = 'k', alpha = 0.7)

    #plot.bar()和plot.barh()分别绘制水平和垂直的柱状图。这时，Series和DataFrame的索引将会被用作X（bar）或Y（barh）刻度

    plt.show()

def draw_11():
    df = pd.DataFrame(np.random.rand(6,4),index = ['one','two','three','four','five','six'],columns = pd.Index(['A','B','C','D'], name = 'Genus'))

    #color='k'和alpha=0.7设定了图形的颜色为黑色，并使用部分的填充透明度。对于DataFrame，柱状图会将每一行的值分为一组，并排显示
    
    df_2 = df
        
    print(df)

    df = df.plot.bar()


    df_2.plot.barh(stacked = 1, alpha = 0.5)
    #设置stacked=True即可为DataFrame生成堆积柱状图，这样每行的值就会被堆积在一起

    #利用value_counts图形化显示Series中各值的出现频率，比如s.value_counts().plot.bar()
    plt.show()


def draw_12():
    '''X = pd.read_csv('address')读取文件
    X = pd.crosstab(X['a'],X['b'])创建交叉表
    X_pcts = X.div(X.sum(1),axis = 0)数据规格化，使各行的和为1
    tips['tip_pct'] = tips['tip'] / (tips['total_bill'] - tips['tip'] )
    X = sns.barplot(x = 'tip_pct', y = 'day',data = tips, orient = 'h')
    sns.set(style="whitegrid")在不同的图形外观之间切换

    tips['tip_pct'].plot.hist(bins=50)生成直方图

    comp1 = np.random.normal(0, 1, size=200)

    comp2 = np.random.normal(10, 2, size=200)

    values = pd.Series(np.concatenate([comp1, comp2]))

    sns.distplot(values, bins=100, color='k')

    tips['tip_pct'].plot.density()生成密度图'''


def draw_13():
    '''macro = pd.read_csv('examples/macrodata.csv')
    data = macro[['cpi', 'm1', 'tbilrate', 'unemp']]
    trans_data = np.log(data).diff().dropna()
    trans_data[-5:]
    
    sns.regplot('m1', 'unemp', data=trans_data)
    plt.title('Changes in log %s versus log %s' % ('m1', 'unemp'))生成线性回归

    sns.pairplot(trans_data, diag_kind='kde', plot_kws={'alpha': 0.2})生成散布图矩阵
    sns.factorplot(x='day', y='tip_pct', hue='time', col='smoker',kind='bar', data=tips[tips.tip_pct < 1])制作分面网络

    sns.factorplot(x='day', y='tip_pct', row='time',col='smoker',kind='bar', data=tips[tips.tip_pct < 1])给每个时间值添加一行来扩展分面网格

    sns.factorplot(x='tip_pct', y='day', kind='box',data=tips[tips.tip_pct < 0.5])生成盒图'''


    


