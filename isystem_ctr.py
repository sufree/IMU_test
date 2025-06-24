import isystem.connect as ic
import serial
import serial.tools.list_ports
import time
import os, sys,stat


string_testcase_xml_start='''<?xml version="1.0" encoding="iso-8859-1"?>
<?xml-stylesheet type='text/xsl' href='test_report_stylesheet.xsl'?>
<testmodule title="Project AAA AAU BBB ITI Test" version="1.13">
	<description>Integration Tests for Developement</description>
	<variants>
		<variant name="All_Tests">All Tests</variant>
	</variants>
	<preparation>
		<initialize title="Initialize test module" wait="200">
		</initialize>
	</preparation>
	     
<testgroup title="Smoke Tests">
'''
''

string_testcase_xml_stop='''</testgroup>

<completion>
		<!--<capltestfunction name="InsertDUTInfo" title="Identification"/>-->
		<initialize title="Adding testreport info." wait="200">
			
		</initialize>
</completion>
</testmodule>
'''

#获取安装版本
#print('isystem version: ' + ic.getModuleVersion())

def get_com_port(port_name):
   if port_name == None or port_name.replace(" ", "") == "" or port_name.startwith("COM") == False:
      com_ports = serial.tools.list_ports.comports()
      if len(com_ports) == 0:
         print("Can't find any COM port, please check the Power supply connector!")
         return None
      else:
         for port in com_ports:
            print("Find first COM port: "+ port.device)
            return port.device
   else:
      return port_name

def GetVar(var_strname,timestamp,print_info):
   Value = None
   try:
      Value = dataCtrl.evaluate(ic.IConnectDebug.fRealTime, var_strname).getLong()
      if print_info == True:
         print('Get "'+var_strname+ '":'+str(Value)+", Delay: "+str(time.time() *1000 - timestamp)+"ms")
   except:
      Value = None
      if print_info == True:
         print('Get "'+var_strname+ '" in winIDEA FAILED! Please check the VAR and elf file!')
   return Value

def SetVar(var_strname, var_strvalue,timestamp):
   try:
      dataCtrl.modify(ic.IConnectDebug.fRealTime, var_strname, var_strvalue)
      print('Set "'+var_strname+ '":'+var_strvalue +", Delay: "+str(time.time() *1000 - timestamp)+"ms")
   except:
      print('Set "'+var_strname+ '" in winIDEA FAILED! Please check the VAR and elf file!')

def write_cfg_xml(path_case_xml):  
   file_case_xml_target = open(path_case_xml, 'w')
   file_case_xml_target.write(string_testcase_xml_start)
   testcase_index =0

   file_case_xml_target.write('''<capltestcase name= "'''+"testcase"+'''" title= "'''+"testcase"+'''" variants="All_Tests"/>\n''')
   file_case_xml_target.write(string_testcase_xml_stop)
   file_case_xml_target.close()
   print("\rWrite testcase configuration xml file...ok        ")  


timestamp = time.time() *1000


if __name__ == "__main__":
    #链接debug
    cmgr = ic.ConnectionMgr("C:\iSYSTEM\winIDEA_9_17_39\iConnect.DLL")
    cmgr.connectMRU()
    #print(f"Is connected: {cmgr.isConnected()}")

    debug = ic.CDebugFacade(cmgr)
    dataCtrl = ic.CDataController(cmgr)
   
    #debug.download()

    #debug.reset()
    #debug.run()

    #value = GetVar('SysModMgr_IntlSt.u8CurrentState',timestamp,True)
    #print('value = ', value)
    
    #SetVar('ImuMgr_ExtCalNvmData.ExtCalResult','4',timestamp)
    #debug.runUntilFunction("main")
    #debug.waitUntilStopped()
    
    # 获取当前连接的端口信息
    #port_info = port.getPort()
    #print(f"当前连接的端口: {port_info}")
    
    cfg_xml_path = "Cfg_testcase.xml"
    if os.path.exists(cfg_xml_path):
        os.chmod(cfg_xml_path,stat.S_IWRITE)
        os.remove(cfg_xml_path)
        print("File "+cfg_xml_path+"already exist, remove it ...")
    write_cfg_xml(cfg_xml_path)
