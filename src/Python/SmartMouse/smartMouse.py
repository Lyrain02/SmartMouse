# 基本鼠标操作
# Windows系统下，运行该脚本，配合智能鼠标使用
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
    dx=int(y.decode('utf-8'))-550 #adxl345和屏幕的xy坐标相反
    dy=int(x.decode('utf-8'))-550 #adxl345和屏幕的xy坐标相反
    print(dx,dy,l,r)

    # 进行相应的鼠标操作
    if l==49:
        if abs(dx)<= 30 and abs(dy)<=30:
            pyautogui.click()  # 单击左键
        else:
            pyautogui.dragRel(dx,dy)  # 拖拽
    elif r==49:
        pyautogui.click(button="right")  # 单击右键
    else:
        pyautogui.moveRel(dx,dy)   # 移动