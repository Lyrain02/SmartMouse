#include <Servo.h> 
Servo sv1;
int E1 = 3;    //左侧电机，数字
int M1 = 5;    //左侧电机，模拟
int E2 =11;    //右侧电机，数字
int M2 =6;     //右侧电机，模拟
int up = 30;    //舵机向上旋转角度
int down = 10;  //舵机向下旋转角度

void setup() {
   sv1.attach(7);
   pinMode(M1, OUTPUT);  
   pinMode(E1, OUTPUT); 
   pinMode(M2, OUTPUT);
   pinMode(E2, OUTPUT); 
   Serial.begin(115200);   //定义串口波特率
   sv1.write(90);
}

void loop() {
    if (Serial.available()>0){         //表示判断如果串口有数据发送过来
     char value=Serial.read();         //定义”字符型变量“value，赋值为接收到的串口信息

      switch(value){                  
        case 's':                     
        Serial.println("stop");      
        digitalWrite(E1,LOW);        
        digitalWrite(M1,LOW);         
        digitalWrite(E2,LOW);         
        digitalWrite(M2,LOW);       
        break;                        

        case 'a':                  
        Serial.println("go ahead");  
        digitalWrite(E1,LOW);        
        digitalWrite(M1,HIGH);       
        digitalWrite(E2,LOW);        
        digitalWrite(M2,HIGH);       
        break;                        
        
        case 'b':                 
        Serial.println("go back");
        digitalWrite(E1,HIGH);
        digitalWrite(M1,LOW);
        digitalWrite(E2,HIGH);
        digitalWrite(M2,LOW);   
        break; 
        
        case 'l':                       
        Serial.println("go front left"); 
        digitalWrite(E1,HIGH);            //定义引脚3为低电平
        analogWrite(M1,150);              //定义引脚5为PWM模拟输出，并定义输出数值，输出值范围为0-255
        digitalWrite(E2,LOW);            //定义引脚11为低电平
        digitalWrite(M2,HIGH);           //定义引脚6为高电平
        break; 
        
        case 'r':                       
        Serial.println("go front right");
        digitalWrite(E1,LOW);
        digitalWrite(M1,HIGH);
        digitalWrite(E2,HIGH);
        analogWrite(M2,150);
        break;   

        case 'u':
        for(int i =90; i<= 90+up;i++){
          sv1.write(i); 
          delay(20); 
        }
        break;

        case 'd':
        sv1.write(90-down);
        break;
      }
    }
  }
