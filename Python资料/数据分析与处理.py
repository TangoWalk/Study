import pandas as pd
import numpy as np
from matplotlib import pyplot as plt


def run():
    plt.style.use("ggplot")
    plt.rcParams['font.sans-serif'] = ['SimHei']
    plt.rcParams['axes.unicode_minus'] = False

    pd.set_option('display.max_columns',None)
    pd.set_option('display.max_rows',None)
    pd.set_option('max_colwidth',100)

    data = pd.read_csv("C://Users//user//Study//Python资料//Python-Learning-Notebooks//文章：PYTHON数据分析与处理全过程//data.csv")
    data = pd.read_csv("C://Users//user//Study//Python资料//Python-Learning-Notebooks//文章：PYTHON数据分析与处理全过程//data.csv",encoding="utf-8")

    data.shape
    data.head()

    data[["年份","通过与否"]].groupby("年份").count().T
    data.describe()

    isdrop = []
    for index,row in data.iterrows():
        if row.isna().sum()>=2:
            isdrop.append(1)
        else:
            isdrop.append(0)

    data.insert(loc = 0, column = "isdrop", value = pd.array(isdrop))
    data.head()

    datacln = data.drop_duplicates("KEY")
    datacln

    datadropna = data.dropna()
    datadropna

    datafillna = data.fillna(0)
    datafillna

    datacap = pd.DataFrame.copy(data)
    cols = datacap.describe().columns
    for cols in cols:
        datacap.replace(datacap[cols],cap(datacap[cols],0.1,0.9))
        
    print(data.max(),datacap.max(),sep = "\n\n")

    print(data.shape)
    datapass = pd.DataFrame.copy(data[data["通过与否"] == "通过"])
    print(datapass.shape)

    datafail = pd.DataFrame.copy(data[data["通过与否"] == "未通过"])
    print(datafail.shape)

    #cols = datapass.describe().columns
    #for cols in cols:
        #datapass.replace(datapass[cols],cap(datapass[cols],0,1,0.9),inplace = True)
        #datafail.replace(datafail[cols],cap(datapass[cols],0,1,0.9),inplace = True)

    data[["年份","通过与否"]].groupby("年份").count().T.to_csv("按年汇总.csv",encoding = "gbk")

    #range = (data[columns].quantile(0.1),data[columns].quantile(0.9))
    #data.describe().columns
    #Index(['年份','年龄','储蓄','KEY'],dtype = 'object')

    for columns in data.describe().columns:
        plt.figure()
        plt.title(columns)
        plt.hist(data[columns],range=(data[columns].quantile(0.1),data[columns].quantile(0.9)),label = columns,alpha = 0.7)
        plt.legend()

    for columns in ["年龄"]:
        plt.figure()
        #plt.title(columns+"分布\n",loc = "center",fontsize = 18)
        plt.hist(data[data["通过与否"] == "通过"][columns],label = "通过",alpha = 0.7)
        plt.hist(data[data["通过与否"] == "未通过"][columns],label = "未通过",alpha = 0.7)
        plt.legend()

    meantest = []
    np.array(meantest)
    
    mediantest = []
    np.array(mediantest)

    from scipy import stats as st

    cols = ["年龄","储蓄"]
    for cols in cols:
        meantest.append
        t,p = st.ttest_ind(datapass[cols].dropna(),datafail[cols].dropna())[0:2]
        meantest.append([cols,t,p])
        t,p = st.median_test(datapass[cols].dropna(),datafail[cols].dropna())[0:2]
        mediantest.append([cols,t,p])

    print(meantest)
    print(mediantest)

    pd.DataFrame(meantest).to_csv("meantest.csv",encoding = "gbk")
    pd.DataFrame(mediantest).to_csv("meantest.csv",encoding = "gbk")

    classdata = data["年龄"]
    classdata = np.array(classdata)

    a = pd.cut(classdata,3)
    b = pd.cut(classdata,[0,5,10,15,20,25])
    print(a)
    print(b)

    pd.DataFrame(a).to_csv("classa.csv")
    pd.DataFrame(b).to_csv("classb.csv")

    
    

        
def cap(x,a,b):
    qa = x.quantile(a)
    #print(qa)

    qb = x.quantile(b)
    #print(qb)

    for i in x:
        if i <= qa:
            x.replace(i,qa,inplace = True)
        if i >= qb:
            x.replace(i,qb,inplace = True)

    #print(pd.DataFrame(x).describe())
    
    return x
run()
