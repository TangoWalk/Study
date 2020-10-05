import numpy as np
import seaborn as sns
import pandas as pd
import matplotlib.pyplot as plt

def read():

    FileNameStr = 'C://Users//user//Study//Python资料//问卷分析实验.xlsx'
    Filexls = pd.ExcelFile(FileNameStr)

    print(Filexls)
read()
    
