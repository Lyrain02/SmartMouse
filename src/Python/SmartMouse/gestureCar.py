# 手势控制小车
# 需要配合串口监视器使用，在运行该文件后，打开串口监视器，将光标移至输入栏
import serial
import pyautogui
pyautogui.FAILSAFE = False  # 防止鼠标移除屏幕

ser=serial.Serial('com5',9600)  # 智能鼠标hc-06蓝牙连接端口

while 1:
    k=ser.read(8)
    cursor=k[:6]
    click=k[6:]
    x=cursor[:3]
    y=cursor[3:]
    l=click[0]
    r=click[1]
    ax=int(x.decode('utf-8'))-550 #以adxl345方向为准
    ay=int(y.decode('utf-8'))-550 #以adxl345方向为准
    print(ax,ay,l,r)

    # 小车功能控制
    # !!!!使用英文输入法
    if l==49 and r==49:
        pyautogui.typewrite(['s', 'enter'])
    elif l==49:
        pyautogui.typewrite(['u', 'enter'])
    elif r==49:
        pyautogui.typewrite(['d', 'enter'])
    else:
        if ax<-80:
            pyautogui.typewrite(['a', 'enter'])
        elif ax>80:
            pyautogui.typewrite(['b', 'enter'])
        elif ay>80:
            pyautogui.typewrite(['r', 'enter'])
        elif ay<-80:
            pyautogui.typewrite(['l',  'enter'])
