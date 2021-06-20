import seaborn as sns
from pandas import DataFrame
from pandas import read_excel
from matplotlib.font_manager import FontProperties
from random import random as rdm
import matplotlib.pyplot as plt

class Data_process:
    def __init__(self):
        myfont=FontProperties(fname=r'type/STSONG.TTF',size=5)#规定字体：华文宋体
        sns.set(font=myfont.get_name())

    def init_data(self,df,col_name,value_rate):#批量产生数据
        data_list=[]
        try:
            df.info
            bull=True
        except AttributeError:
            bull=False
            
        if bull:
            amount=df.shape[0]         
        else:amount=int(input("初始数量是："))  
        
        for member in range(amount):
            check_num=rdm()
            for value in range(len(value_rate)):
                if check_num<=value_rate[value][1]:
                    data_list.append(value_rate[value][0])
                    break
        if bull:
            df[col_name]=data_list  
        else:
            df = DataFrame(data_list,columns=[col_name],dtype=type(value_rate[0][0]))
        return df       

    def asclass_(self,x,col,col_wrap,data,name):#绘制分组表
        figure=sns.catplot(x=x, col=col, \
                              col_wrap=col_wrap, \
                              data=data, kind="count", height=10, aspect=.8) 
        figure.savefig(name)

    def asjoint_(self,df,x,y,name):
        figure=sns.jointplot(data=df,x=x,y=y,palette='husl')
        figure.savefig(name)

    def aspair_(self,df,var_list,hue,name):
        figure=sns.pairplot(data=df,vars=var_list,hue=hue,palette="husl")
        figure.savefig(name)

    def aspie_(self,dataname):
        
        freq = dataname.value_counts(normalize = True)
        colors = ['#81ecec','#ff7675','#6c5ce7']
        plt.pie(freq, labels = freq.index, explode = (0.05, 0, 0), autopct = '%.1f%%', colors = colors, startangle = 90, counterclock = False)
        plt.axis('square')
        plt.legend(loc='upper right', bbox_to_anchor=(1.2, 0.2))
        plt.show()
        
if __name__ == '__main__':
    func=Data_process()
    df=DataFrame(read_excel('data.xlsx'))

    df=func.init_data('','学历',[['高中以下',0.15],['高中',0.35],\
                               ['大专',0.45],['本科',0.7],\
                               ['硕士',0.9],['博士',1]])
    df=func.init_data(df,'年龄',[['18岁以下',0.35],['19岁到40岁',0.75],['40岁到60岁',0.9],['60岁以上',1]])
    df=func.init_data(df,'性别',[['男',0.5],['女',1]])
    df=func.init_data(df,'使用时间',[['2小时以下',0.2],['2到4小时',0.55],['4到6小时',0.9],['6小时',1]])
    df=func.init_data(df,'可信度',[[0,0.05],[1,0.1],[2,0.3],[3,0.7],[4,0.95],[5,1]])
    df=func.init_data(df,'不可信：具有选择性，是推送者希望读者看到的信息',[[None,0.3],[0,0.58],[1,1]])
    df=func.init_data(df,'不可信：夸大成分',[[None,0.3],[0,0.4],[1,1]])
    df=func.init_data(df,'不可信：发布时间较晚',[[None,0.3],[0,0.8],[1,1]])
    df=func.init_data(df,'不可信：与我的价值观不符',[[None,0.3],[0,0.6],[1,1]])
    df=func.init_data(df,'不可信：二次创作，感情倾向',[[None,0.3],[0,0.7],[1,1]])
    df=func.init_data(df,'可信：有严格的校验和举报机制',[[None,0.7],[0,0.75],[1,1]])
    df=func.init_data(df,'可信：官方机构入驻，信息可信',[[None,0.7],[0,0.72],[1,1]])
    df=func.init_data(df,'可信：有知名人士与权威人士支撑，保证信息可信度',[[None,0.7],[0,0.73],[1,1]])
    df=func.init_data(df,'信息满意度',[[0,0.05],[1,0.15],[2,0.3],[3,0.7],[4,0.95],[5,1]])
    df=func.init_data(df,'需求满足度',[[0,0.05],[1,0.1],[2,0.4],[3,0.7],[4,0.95],[5,1]])
    df=func.init_data(df,'不满意：融入价值观，删减信息',[[None,0.6],[0,0.7],[1,1]])
    df=func.init_data(df,'不满意：信息收集不全面',[[None,0.6],[0,0.65],[1,1]])
    df=func.init_data(df,'不满意：对其它领域不感兴趣',[[None,0.6],[0,0.63],[1,1]])
    df=func.init_data(df,'不满意：筛除了一些信息，只能从其它渠道获取',[[None,0.6],[0,0.68],[1,1]])
    df=func.init_data(df,'满意：信息二次加工，符合作者价值观',[[None,0.4],[0,0.47],[1,1]])
    df=func.init_data(df,'满意：针对我的兴趣发布我感兴趣的信息',[[None,0.4],[0,0.42],[1,1]])
    df=func.init_data(df,'满意：信息收集比较全面',[[None,0.4],[0,0.42],[1,1]])
    df=func.init_data(df,'可信因素：由知名博主转发或发布',[[0,0.2],[1,1]])
    df=func.init_data(df,'可信因素：由官方机构转发或发布',[[0,0.1],[1,1]])
    df=func.init_data(df,'可信因素：彼此相识的同学、朋友或亲属等转发或发布',[[0,0.65],[1,1]])
    df=func.init_data(df,'可信因素：权威人士转发或发布',[[0,0.6],[1,1]])
    df=func.init_data(df,'可信因素：标题足够吸引',[[0,0.85],[1,1]])
    df=func.init_data(df,'可信因素：阅读量比较多',[[0,0.8],[1,1]])
    df=func.init_data(df,'可信因素：内容足够合理',[[0,0.45],[1,1]])
    df=func.init_data(df,'看待价值观',[['以经济利益或诱导转发等为主，不可轻信',0.35],['理性看待，自主思考',0.85],['大多数契合主流价值观，值得相信',1]])
    df=func.init_data(df,'标准：客观事实佐证',[[0,0.15],[1,1]])
    df=func.init_data(df,'标准：标题或内容等足够吸引读者',[[0,0.65],[1,1]])
    df=func.init_data(df,'标准：经济利益',[[0,0.85],[1,1]])
    df=func.init_data(df,'标准：组建高质量社群，分享高质量信息',[[0,0.65],[1,1]])
    df=func.init_data(df,'标准：内容对我或读者有较大的帮助',[[0,0.15],[1,1]])
    df=func.init_data(df,'标准：提升我在该领域的知名度',[[0,0.85],[1,1]])
    df=func.init_data(df,'算法：便于查找信息',[[0,0.15],[1,1]])
    df=func.init_data(df,'算法：我可以从中结识新朋友，组建社群',[[0,0.2],[1,1]])
    df=func.init_data(df,'算法：我可以从中发现新的感兴趣的领域',[[0,0.1],[1,1]])
    df=func.init_data(df,'算法：它增加了我的个人信息泄露的风险',[[0,0.15],[1,1]])
    df=func.init_data(df,'算法：它助长了人们的从众心理，削弱了人与人之间的个性',[[0,0.15],[1,1]])
    df=func.init_data(df,'算法：可能会助长平台为经济利益增加算法偏好的倾向',[[0,0.08],[1,1]])
    df.to_excel('data.xlsx')
    print(df)
    func.asclass_('学历',"不可信：夸大成分",3,df,'figure1.jpg')
    func.asclass_('学历',"不可信：二次创作，感情倾向",3,df,'figure2.jpg')
    func.asclass_('学历',"可信：官方机构入驻，信息可信",3,df,'figure3.jpg')
    func.asclass_('学历',"不满意：融入价值观，删减信息",3,df,'figure4.jpg')
    func.asclass_('学历',"标准：经济利益",2,df,'figure5.jpg')
    func.asclass_('学历',"算法：便于查找信息",2,df,'figure6.jpg')
    func.aspair_(df,["可信度","信息满意度","需求满足度"],"学历",'figure7.jpg')
    func.asclass_('学历',"标准：客观事实佐证",2,df,'figure8.jpg')

    func.asclass_('性别',"不可信：夸大成分",3,df,'figure11.jpg')
    func.asclass_('性别',"不可信：二次创作，感情倾向",3,df,'figure12.jpg')
    func.asclass_('性别',"可信：官方机构入驻，信息可信",3,df,'figure13.jpg')
    func.asclass_('性别',"不满意：融入价值观，删减信息",3,df,'figure14.jpg')
    func.asclass_('性别',"标准：经济利益",2,df,'figure15.jpg')
    func.asclass_('性别',"算法：便于查找信息",2,df,'figure16.jpg')
    func.aspair_(df,["可信度","信息满意度","需求满足度"],"性别",'figure17.jpg')
    func.asclass_('性别',"标准：客观事实佐证",2,df,'figure18.jpg')
    
    func.asclass_('年龄',"不可信：夸大成分",3,df,'figure21.jpg')
    func.asclass_('年龄',"不可信：二次创作，感情倾向",3,df,'figure22.jpg')
    func.asclass_('年龄',"可信：官方机构入驻，信息可信",3,df,'figure23.jpg')
    func.asclass_('年龄',"不满意：融入价值观，删减信息",3,df,'figure24.jpg')
    func.asclass_('年龄',"标准：经济利益",2,df,'figure25.jpg')
    func.asclass_('年龄',"算法：便于查找信息",2,df,'figure26.jpg')
    func.aspair_(df,["可信度","信息满意度","需求满足度"],"年龄",'figure27.jpg')
    func.asclass_('年龄',"标准：客观事实佐证",2,df,'figure28.jpg')

    
