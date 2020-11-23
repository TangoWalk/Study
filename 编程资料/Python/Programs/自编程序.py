#-*- coding:utf-8 -*-
import xlrd
import xlwt
import os
from xlutils.copy import copy

def start():
    print("程序即将运行。请将文件放入D:\python学习资料中，并将文件备份")
    open()
    
def open():
    list_all = []
    global file
    global xlsx
    file = str("D:\python学习资料\\")
    for root,dirs,files in os.walk('D:\python学习资料'):
        for name in files:
            file_path = os.path.join(root,name)
            file_name = os.path.split(file_path)[-1]
            list_all.append(file_name)
    print("搜索到以下文件：",list_all)
    filenum = int(input("请选择您要运行的文件：\n"))-1
    choice = str(list_all[filenum])
    file = file[:14]+choice
    xlsx = xlrd.open_workbook(file)
    print("当前成功加载文件：",choice)
    help()

def read():
    total_rows = []
    
    for each in range(0,xlsx.nsheets):
        table = xlsx.sheet_by_index(each)
        for each_sheet in range(0,table.nrows):
            row_each = table.row_values(each_sheet-1)
            print(row_each)
            #total_rows = total_rows.append(row_each)
            break
        continue
    print(total_rows)

    
def format():
    style = xlwt.XFStyle()
    
    font = xlwt.Font()
    font.name = '微软雅黑'
    font.bold = True
    font.height = 360
    style.font = font


    borders = xlwt.Borders()

    borders.top = xlwt.Borders.THIN
    borders.bottom = xlwt.Borders.THIN
    borders.left = xlwt.Borders.THIN
    borders.right = xlwt.Borders.THIN
    style.borders = borders

    alignment = xlwt.Alignment()
    alignment.horz = xlwt.Alignment.HORZ_CENTER
    alignment.vert = xlwt.Alignment.VERT_CENTER
    style.alignment = alignment

    #new_sheet.write(2,1,12,style)


def help():
    help = input("当前程序运行结束。打开新表请输入1：\n")
    if help == '1':
        open()
    if help == '2':
        format()
    if help == '3':
        read()
open()
