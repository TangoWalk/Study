from xlutils.copy import copy
import xlrd
import xlwt

def one():
    xlsx = xlrd.open_workbook('D:\新建 XLS 工作表.xlsx')
#打开文件所在位置
    table = xlsx.sheet_by_index(0)
    table2 = xlsx.sheet_by_name("第二个表")
#打开第一个表；用名字打开表。
#文件 选项 公式 R1C1 引用样式可以直接看到列数字
    print(table.cell_value(1,3))
    print(table.cell(1,3).value)
    print(table.row(1)[3].value)
#打印在第一个表第2行第4列的值

def two():
    new_workbook = xlwt.Workbook()
    worksheet = new_workbook.add_sheet('new_test')
#新建工作簿
    worksheet.write(1,3,'test')
#在第2行第4列新建内容test
    new_workbook.save('D:\新建 XLS 工作表.xlsx')
#将工作簿保存为test.xls

def three():
    tem_excel = xlrd.open_workbook('D:\模板.xls',formatting_info = True)
#打开模板，打开格式代理器
    tem_sheet = tem_excel.sheet_by_index(0)

    new_excel = copy(tem_excel)
    new_sheet = new_excel.get_sheet(0)

    style = xlwt.XFStyle()
#创建一个空格式
    
    font = xlwt.Font()
    font.name = '微软雅黑'
    font.bold = True
#加粗
    font.height = 360
#将字号×20形成代码
    style.font = font
#将字体添加到格式中

    borders = xlwt.Borders()
#创建一个空格式
    borders.top = xlwt.Borders.THIN
    borders.bottom = xlwt.Borders.THIN
    borders.left = xlwt.Borders.THIN
    borders.right = xlwt.Borders.THIN
    style.borders = borders
#加入细线框，并添加到格式中

    alignment = xlwt.Alignment()
    alignment.horz = xlwt.Alignment.HORZ_CENTER
    alignment.vert = xlwt.Alignment.VERT_CENTER
    style.alignment = alignment
#进行水平对齐和中心对齐，只需修改后面的代码，并添加到格式中

    new_sheet.write(2,1,12,style)
    new_sheet.write(3,1,18,style)
    new_sheet.write(4,1,19,style)
    new_sheet.write(5,1,15,style)
    new_excel.save('D:\模板.xls')

def four():
    xlsx = xlrd.open_workbook('D:\2018年应付账款.xls')

    table = xlsx.sheet_by_name('钧达莱')
    
    all_data = []
    for n in range(4,table.nrows):
        amount  = table.cell(n,4).value
        price = table.cell(n,5).value

        data = {'amount':amount,'price':price}
        all_data.append(data)
#存取所有在excel读取的内容
    a_weight = []
    a_total_price = []
    b_weight = []
    b_total_price = []
    c_weight = []
    c_total_price = []
    d_weight = []
    d_total_price = []

    for i in all_data:
        if i['company'] == ['A']:
            a_weight.append(i['weight'])
            a_total_price,append(i['weight'] * i['price'])
        if i['company'] == ['B']:
            b_weight.append(i['weight'])
            b_total_price,append(i['weight'] * i['price'])
        if i['company'] == ['C']:
            c_weight.append(i['weight'])
            c_total_price,append(i['weight'] * i['price'])
        if i['company'] == ['D']:
            d_weight.append(i['weight'])
            d_total_price,append(i['weight'] * i['price'])
            
    tem_excel = xlrd.open_workbook('D:\新建 XLS 工作表.xlsx',formatting = True)
    tem_sheet = tem_excel.sheet_by_index(0)

    new_excel = copy(tem_excel)
    new_sheet = new_excel.get_sheet(0)

    style = xlwt.XFStyle()

    font = xlwt.Font()
    font.name = '微软雅黑'
    font.bold = True
#加粗
    font.height = 360
#将字号×20形成代码
    style.font = font
#将字体添加到格式中

    borders = xlwt.Borders()
#创建一个空格式
    borders.top = xlwt.Borders.THIN
    borders.bottom = xlwt.Borders.THIN
    borders.left = xlwt.Borders.THIN
    borders.right = xlwt.Borders.THIN
    style.borders = borders
#加入细线框，并添加到格式中

    alignment = xlwt.Alignment()
    alignment.horz = xlwt.Alignment.HORZ_CENTER
    alignment.vert = xlwt.Alignment.VERT_CENTER
    style.alignment = alignment
#进行水平对齐和中心对齐，只需修改后面的代码，并添加到格式中

    new_sheet.write(2,1,len(a_weight),style)
    new_sheet.write(2,2,round(sum(a_weight),2),style)
    new_sheet.write(2,3,round(sum(a_total_price),2),style)
    new_sheet.write(3,1,len(b_weight),style)
    new_sheet.write(3,2,round(sum(b_weight),2),style)
    new_sheet.write(4,1,len(c_weight),style)
    new_sheet.write(4,2,round(sum(c_weight),2),style)
    new_sheet.write(4,3,round(sum(c_total_price),2),style)
    new_sheet.write(5,1,len(d_weight),style)
    new_sheet.write(5,2,round(sum(d_weight),2),style)
    new_sheet.write(5,3,round(sum(d_total_price),2),style)
    new_excel.save('D:\模板.xls')
    
three()
