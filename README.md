# SmartMouse
This is the class project for Innovation Practice. Its a simple implementation of a smartmouse built by Arduino and python. Arduino is used in the implementation of the smartmouse, and python is used to realize bluetooth communicaition and GUI control. 

For this project, you can use the smart mouse to control the cursor on the screen of computer. Besides, you can use it to control the movement of the drawing car built by Arduino Uno.

**why smartmouse?**
Tranditional mouse need a smooth and solid surface. BUt sometimes, when you want to use your computer and mouse on a sofa, it may be difficult for you to use the mouse, because the sofa is so soft and sometimes rough. Then you may need a smart mouse which can be used in the air, so that you can get rid of the dependence on the solid surface. Maybe sounds a little silly, but that's the originl intention why I conduct this project. 

This smart mouse is designed for non-solid surface, which means you can use it in the air. 

## Implementation

### Hardware
#### Smart Mouse
![image](https://user-images.githubusercontent.com/71683792/137585064-d9e89662-c9ad-4f06-9493-e6558c085deb.png)
Arduino Nano, adxl345, hc-06 module, 3 button, 1 led, 1 resistence, wires and power.

#### Drawing Car
![image](https://user-images.githubusercontent.com/71683792/137585076-6dc9d784-2310-434b-984a-dd3b422f529b.png)
Arduino Uno, Uno expansion board, L298N motor drive, 2 motors, 3D printing car materials, wires and power. 

In fact, the car is not designed by meself, and I just bought the materials online and assembled the car. This car is only used to show the control of the smart mouse. It's not the core of the design but an application.

### Software
Python is so powerful that I use serial to realize Bluetooth communication between mouse and computer, and pyautogui to control the cursor movement of a computer screen. 
