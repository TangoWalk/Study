import seaborn as sns
from pandas import DataFrame
from pandas import read_excel

class Write_figure:
    def __init__(self):
        pass

    def read_excel(self,excel):
        df=DataFrame(read_excel(excel))
        return df

    def classes_(self,data):
        figure=sns.factorplot(x='sex', col="open", col_wrap=3, data=data, kind="count", size=2.5, aspect=.8) 
        figure.savefig('hist.jpg')
if __name__ == '__main__':
    func=Write_figure()
    df=func.read_excel('test.xlsx')
    print(df)
    func.classes_(df)
