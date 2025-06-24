import os,stat
import tkinter as tk


#imufile = 'dcs.txt'

IMU_CODE_FILE_PATH = r'D:\Python\IMU_test'

imufile = os.path.join(IMU_CODE_FILE_PATH, 'ImuSgPoolMgr.c')
codefile = os.path.join(IMU_CODE_FILE_PATH, 'IMU测试模拟输入.c')


sensitivity = {"Primary_LOG":"5000","Primary_ARS":"100","Primary_dir":"1",
               "Second_LOG":"2000", "Second_ARS":"50",   "Second_dir":"-1"}


def insert_code():
    """insert code in ImuSgPoolMgr.c"""
    const_code = genaret_code()
    """read the source code """
    with open(codefile,'r') as cfile:
        codes = cfile.readlines()
        #print(code)
    
    """insert code in function imusgpoolmgr_ReadChannel()"""
    i = 0
    output_txt = ""
    #文件可读
    os.chmod(imufile,stat.S_IWRITE)
    
    with open(imufile,'r') as imufilecode, open('%s.bak' % imufile, 'w') as codefile_bak:
        isinsert = True
        isok = True
        needwrit = False
        
        listcode = imufilecode.readlines()
        #print(listcode)
        
        try:
            indxs = listcode.index("uint8 IMUdateSwitch;\n") 
        except:
            isinsert = False
        
        if isinsert == False:
            try:
                indeex = listcode.index('imusgpoolmgr_ReadChannel\n') #返回函数所在的列数
            except:
                isok = False
       
            if isok == True:
                listcode[indeex-1:indeex-1] = const_code
            
                for code in codes[1:]:
                    listcode.insert(indeex+16+i,code)
                    i += 1
                
                codefile_bak.writelines(listcode)
                needwrit = True
                output_txt = "insert code successfully\n"
            else:
                output_txt = "Don't find: imusgpoolmgr_ReadChannel\n"
        else:
            output_txt = "Code already inserted\n"

    if needwrit == True:
        os.remove(imufile)
        os.rename("%s.bak" % imufile, imufile)
    else:
        pass  
    
    prn_output.insert(tk.END,output_txt)

def sensor_type(primary,secondary,pri_dir,sec_dir):
    
    if primary == "SMI8":
        sensitivity["Primary_LOG"] = "5000"
        sensitivity["Primary_ARS"] = "100"
    else:
        sensitivity["Primary_LOG"] = "2000"
        sensitivity["Primary_ARS"] = "50"
        
    if secondary == "SMI8":
        sensitivity["Second_LOG"] = "5000"
        sensitivity["Second_ARS"] = "100"
    else:
        sensitivity["Second_LOG"] = "2000"
        sensitivity["Second_ARS"] = "50"
        
    if pri_dir == "POSITIVE":
        sensitivity["Primary_dir"] = "1"
    else:
        sensitivity["Primary_dir"] = "-1"
        
    if sec_dir == "POSITIVE":
        sensitivity["Second_dir"] = "1"
    else:
        sensitivity["Second_dir"] = "-1"
        
    #print(sensitivity)

def genaret_code():
    const_code = ["uint8 IMUdateSwitch;\n"]
    const_code.append("const sint16 P_G_Sensitivity = " + sensitivity["Primary_LOG"] + ";\n")
    const_code.append("const sint16 P_A_Sensitivity = " + sensitivity["Primary_ARS"] + ";\n")
    const_code.append("const sint16 PZ_Direct = " + sensitivity["Primary_dir"] + ";\n")
    const_code.append("const sint16 S_G_Sensitivity = " + sensitivity["Second_LOG"] + ";\n")
    const_code.append("const sint16 S_A_Sensitivity = " + sensitivity["Second_ARS"] + ";\n")
    const_code.append("const sint16 SZ_Direct = " + sensitivity["Second_dir"] + ";\n")
    const_code.append("\n")
    
    return const_code
        
def creat_option_gui():
    # 创建一个标签
    prn_label = tk.Label(root, text="请选择sensor type:",font=("黑体",14))
    prn_label.grid(row=0, column=0, padx=10, pady=5,sticky="w")  # 使用 grid 布局
    
    # 创建一个标签
    p_label = tk.Label(root, text="Primary:",font=("黑体",12))
    p_label.grid(row=1, column=0, padx=10, pady=0,sticky="e")  # 使用 grid 布局
    # 创建一个标签
    p_label = tk.Label(root, text="Secondary:",font=("黑体",12))
    p_label.grid(row=1, column=2, padx=10, pady=5,sticky="e")  # 使用 grid 布局
    
    # 创建一个 type 变量
    pri_type = tk.StringVar(root)
    pri_type.set("PAN6")  # 设置默认值
    sec_type = tk.StringVar(root)
    sec_type.set("SMI8")  # 设置默认值
    
    # 创建 type OptionMenu
    options = ["SMI8", "PAN6"]
    p_option_menu = tk.OptionMenu(root, pri_type, *options)
    p_option_menu.grid(row=1, column=1, padx=10, pady=0,sticky="w")
    s_option_menu = tk.OptionMenu(root, sec_type, *options)
    s_option_menu.grid(row=1, column=3, padx=0, pady=0,sticky="w")

    # 创建一个 direction 变量
    pri_dir = tk.StringVar(root)
    pri_dir.set("POSITIVE")  # 设置默认值
    sec_dir = tk.StringVar(root)
    sec_dir.set("NAGETIVE")  # 设置默认值
    
    # 创建 direction OptionMenu
    options = ["POSITIVE", "NAGETIVE"]
    p_option_menu = tk.OptionMenu(root, pri_dir, *options)
    p_option_menu.grid(row=2, column=1, padx=10, pady=0,sticky="w")
    s_option_menu = tk.OptionMenu(root, sec_dir, *options)
    s_option_menu.grid(row=2, column=3, padx=0, pady=0,sticky="w")
    
    # 定义回调函数
    def callback():
        sensor_type(pri_type.get(),sec_type.get(),pri_dir.get(),sec_dir.get())
        #print("你选择了:", pri_type.get())
        #print("你选择了:", sec_type.get())

    # 创建按钮并绑定回调函数
    button = tk.Button(root, text="确认选择", command=callback)
    button.grid(row=1, column=5, padx=10, pady=0,sticky="e")

    # 创建按钮并绑定回调函数
    button2 = tk.Button(root, text="insert_code", command=insert_code)
    button2.grid(row=3, column=5, padx=10, pady=0,sticky="e")
    # 更改按钮的背景颜色和前景颜色
    button2.config(activebackground="yellow", activeforeground="red",highlightbackground="black")
    

        

if __name__ == "__main__":
    root = tk.Tk()
    root.title("IMU test")
    root.iconbitmap("rubble.ico")#添加图标
    root.geometry("650x300")
    root.resizable(True,False)

    creat_option_gui()

    # 创建一个输出框
    prn_output = tk.Text(root, height=5, width=55)
    prn_output.grid(row=4, column=0, columnspan=5, padx=20, pady=0,sticky="w")  # 使用 grid 布局 

    tk.mainloop()


