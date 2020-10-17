import pandas as pd
import numpy as np

def run():

    fileNameStr = 'C:\\Users\\user\\Study\\Python资料\\朝阳医院2018年销售数据.xlsx'
    xls = pd.ExcelFile(fileNameStr)
    #print(xls)
    salesDf = xls.parse('Sheet1',dtype = 'object')

    #print(salesDf.head())
    salesDf.shape


    #SubSaleDf = salesDf.loc[0:4,'购药时间':'销售数量']
    colNameDict = {'购药时间':'销售时间'}
    salesDf.rename(columns = colNameDict, inplace = True)
    #print(salesDf.head())

    #print('删除缺失值大小',salesDf.shape)
    salesDf = salesDf.dropna(subset = ['销售时间','社保卡号'],how = 'any')
    #print('删除缺失后大小',salesDf.shape)

    salesDf['销售数量'] = salesDf['销售数量'].astype('float')
    salesDf['应收金额'] = salesDf['应收金额'].astype('float')
    salesDf['实收金额'] = salesDf['实收金额'].astype('float')
    #print('转换后的数据类型:\n',salesDf.dtypes)

    #testList = '2018-06-03 星期五'.split(' ')
    #print(testList[0])

    timeSer = salesDf.loc[:,'销售时间']
    dateSer = splitSaletime(timeSer)

    salesDf.loc[:,'销售时间'] = dateSer
    #print(salesDf.head())

    salesDf.loc[:,'销售时间'] = pd.to_datetime(salesDf.loc[:,'销售时间'],format = '%Y-%m-%d',errors = 'coerce')
    #print(salesDf.dtypes)

    salesDf = salesDf.dropna(subset = ['销售时间','社保卡号'],how = 'any')

    #print('排序前的数据集')
    #print(salesDf.head())

    salesDf = salesDf.sort_values(by = '销售时间',ascending=True)

    #print('排序后的数据集')
    #print(salesDf.head(3))

    salesDf = salesDf.reset_index(drop = True)
    #print(salesDf.head())

    #print(salesDf.describe())

    querySer = salesDf.loc[:,'销售数量']>0

    print('前',salesDf.shape)
    salesDf = salesDf.loc[querySer,:]

    print('后',salesDf.shape)

    kpi1_Df = salesDf.drop_duplicates(subset = ['销售时间','社保卡号'])
    totalI = kpi1_Df.shape[0]
    print('总消费次数=',totalI)

    kpi1_Df = kpi1_Df.sort_values(by = '销售时间',ascending = True)
    kpi1_Df = kpi1_Df.loc[totalI-1,'销售时间']

    startTime = kpi1_Df.loc[0,'销售时间']
    endTime = kpi1_Df.loc[totalI-1, '销售时间']

    daysI = (endTime - startTime).days
    monthsI = daysI // 30
    print('月份数：',monthsI)
    
def splitSaletime(timeColSer):
    timeList = []
    for value in timeColSer:
        dateStr = value.split(' ')[0]
        timeList.append(dateStr)

    timeSer = pd.Series(timeList)
    return timeSer
run()
