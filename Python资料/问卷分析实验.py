#!/usr/bin/env python
# coding: utf-8

import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt
import sys

def read():

    global Filecsv
    
    Filecsv = pd.read_csv('D://git数据库//Python资料//data.csv',encoding = 'utf-8')

    '''encode = sys.getdefaultencoding()
    print(encode)'''
    #编码检测

    head = Filecsv.head()
    print(head)
    #读取检测
    
read()
    
