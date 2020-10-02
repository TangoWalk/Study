import matplotlib.pyplot as plt
import numpy as np
from numpy.random import randn

def draw_1():
    plt.plot([3,1,4,5,2])
    plt.ylabel('grade')
    plt.savefig('test',dpi = 600)
    plt.show()

def draw_2():
    data = np.arange(10)
    draw = (plt.plot(data))
    plt.show()

def draw_3():
    fig = plt.figure()
    
    ax1 = fig.add_subplot(2,2,1)
    
    ax2 = fig.add_subplot(2,2,2)
    
    ax3 = fig.add_subplot(2,2,3)

    plt.plot(np.random.randn(50).cumsum(),'k--')

    ax1.hist(np.random.randn(100),bins = 20,color = 'k', alpha = 0.3)

    ax2.scatter(np.arange(30),np.arange(30) + 3 * np.random.randn(30))

    fig,axes = plt.subplots(2,3)

    print(axes)
    
    plt.show()

def draw_4():
    #ax.plot(x,y,linestyle = '--', color = 'g')
    #plt.plot(randn(30).cumsum(),'ko--')

    data = randn(30).cumsum()

    plt.plot(data,'k-',label = 'Default')
    plt.plot(data,'k-',drawstyle = 'steps-post',label = 'steps-post')

    plt.show()

def draw_5():
    fig = plt.figure()
    ax = fig.add_subplot(1,1,1)
    ax.plot(np.random.randn(1000).cumsum())

    ticks = ax.set_xticks([0,250,500,750,1000])
    ticks = ax.set_yticks([0,250,500,750,1000])
    labels = ax.set_xticklabels(['one','two','three','four','five'],rotation = 90,fontsize = 'small')

    ax.set_title('My Matplotlib Plot')
    ax.set_xlabel('Stages')

    plt.show()
    
draw_5()
