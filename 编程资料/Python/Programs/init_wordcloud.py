from spacy import load
from os import listdir
from xlwt import Workbook
from wordcloud import WordCloud
from xlrd import open_workbook

class Write_graph:
    def __init__(self,addr):
        self.addr=addr
        self.nlp=load('zh_core_web_sm')

    def open_file(self):#打开目标文本文档
        file_names = listdir(self.addr)
        print("搜索到以下文件：")
        print(file_names)
        file_num = int(input("请选择需要读取的文件序号："))
        file_name = listdir(self.addr)[file_num]
        address = self.addr + '/' + file_name
        self.address=address

    def read_details(self):#读取内容
        aticl=open(self.address,'r',encoding = 'utf-8')
        strs=aticl.read()
        return strs

    def filter(self,strs):
        usls_items=['，','。','?','；','！','、','“','”','',' ','[',']','{',\
                    '}','!','？',';','：','\n','\u3000']
        for each in range(len(usls_items)):
            strs.strip(usls_items[each])
        doc=self.nlp(strs)
        return doc

    def to_list(self,doc):
        ent_text=[]
        ent_label=[]
        ent_total=[ent_text,ent_label]
        
        for ent in doc.ents:
            ent_text.append(ent.text)
            ent_label.append(ent.label_)

        return ent_total

    def count(self,doc,ent_total):
        text_reset=[]
        text_count=[]
        label_reset=[]

        for ent in range (len(doc.ents)):
            for text_num in range (len(ent_total[0])):
                if text_num<len(text_reset) and \
                   ent_total[0][ent]==text_reset[text_num]:
                    break
                elif text_num==len(text_reset):
                    text_reset.append(ent_total[0][ent])
                    text_count.append(ent_total[0].count(ent_total[0][ent]))
                    label_reset.append(ent_total[1][ent])
                    break

        total_info=[text_reset,text_count,label_reset]
        return total_info
        

    def count_to_xl(self,total_info):
        book = Workbook(encoding='utf-8')
        sheet = book.add_sheet('实体统计')
        header = ['名词','出现次数','标签']
   
        for h in range(0,len(header)):
            sheet.write(0,h,header[h])

        i=1
        for ent in range(len(total_info[0])):
            j=0
            for cou_amo in range(len(total_info)):
                sheet.write(i,j,total_info[cou_amo][ent])
                j+=1
            i+=1
            
        name = self.addr + '/count.xls'
        book.save(name)

    def xl_arr(self,name,sheet,row_bgn,col,wc_name):#
        workbook=open_workbook(self.addr+'/'+name+'.xls')
        worksheet=workbook.sheet_by_index(sheet)
        num_cols=worksheet.ncols
        num_rows=worksheet.nrows
        
        arr=[]
        for curr_row in range(row_bgn,num_rows):
            for value in range(int(worksheet.cell_value(curr_row,1))):
                arr.append(worksheet.cell_value(curr_row,col))
            
        arr_to_wordcloud(wc_name+".jpg")
                
            
            
def arr_to_wordcloud(arr,path):
    arr_to_str=' '.join(arr)
    wc=WordCloud(\
        font_path="STSONG.TTF",\
        background_color='white',\
        width=1000,\
        height=800,\
        collocations=False,\
        )
    wc.generate_from_text(arr_to_str)
    wc.to_file(path)

if __name__=='__main__':
    address = 'C:/Users/win10/Desktop/主题'
    #请修改地址
    run = Write_graph(address)
    run.open_file()
    strs=run.read_details()
    doc=run.filter(strs)
    ent_total=run.to_list(doc)
    print(ent_total[0])
    total_info=run.count(doc,ent_total)
    run.count_to_xl(total_info)
    run.xl_arr('count',0,1,0,'f')
