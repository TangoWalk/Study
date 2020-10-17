def read():
    global multiplier_collect
    global sign_collect
    global result_collect
    global result
    
    multiplier_collect = []
    sign_collect = []
    result_collect = []
    list_result = []
    
    amount = int(input("请输入不等式的个数"))
    list_collect = []
    for each in range(0,amount):
        read_detail()


def read_detail():

    detail = input("请输入不等式")
    address = int(detail.index("="))
    count = int((address/4))
    count_sign = 0
    count_result = len(detail)-1
    print(count_result)
    
    
    for each in range(0,count):
        details_sign = detail[count_sign]
        multiplier_collect.append(details_sign)
        count_sign += 4
    
        
        result = int(detail[address+1:count_result+1])
        #list_result = list_result.insert(result,each-1)
        type(result)
        print(result)
        print(list_result)
read()
