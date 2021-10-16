#include <SoftwareSerial.h>
#include <Wire.h>  // Wire library - used for I2C communication

float X_out, Y_out, Z_out;  // Outputs
int xcord, ycord;
int lstate = 0;
int rstate = 0;

int ADXL345 = 0x53; // The ADXL345 sensor I2C address
const int rxpin = 2, txpin = 3;
SoftwareSerial bluetooth(rxpin, txpin);
const int trigger = 5;
const int lclick = 6;
const int rclick = 7;
const int led = 8;

void setup()
{
  pinMode(trigger,INPUT_PULLUP);
  pinMode(lclick,INPUT_PULLUP);
  pinMode(rclick,INPUT_PULLUP);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  bluetooth.begin(9600);

  Wire.begin(); // Initiate the Wire library
  // Set ADXL345 in measuring mode
  Wire.beginTransmission(ADXL345); // Start communicating with the device
  Wire.write(0x2D); // Access/ talk to POWER_CTL Register - 0x2D
  // Enable measurement
  Wire.write(8); // (8dec -> 0000 1000 binary) Bit D3 High for measuring enable
  Wire.endTransmission();
  delay(10);

  // Off-set Calibration
  //X-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1E);  // X-axis offset register
  Wire.write(-1);
  Wire.endTransmission();
  delay(10);
  //Y-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x1F); // Y-axis offset register
  Wire.write(0);
  Wire.endTransmission();
  delay(10);
  //Z-axis
  Wire.beginTransmission(ADXL345);
  Wire.write(0x20); // Z-axis offset register
  Wire.write(-8);
  Wire.endTransmission();
  delay(10);
}

void loop()
{
  digitalWrite(led,LOW);
  while(digitalRead(trigger)==LOW)
  { 
    digitalWrite(led, HIGH);
    lstate = digitalRead(lclick);
    rstate = digitalRead(rclick);
    Wire.beginTransmission(ADXL345);
    Wire.write(0x32); // Start with register 0x32 (ACCEL_XOUT_H)
    Wire.endTransmission(false);
    Wire.requestFrom(ADXL345, 6, true); // Read 6 registers total, each axis value is stored in 2 registers
    X_out = ( Wire.read()| Wire.read() << 8); // X-axis value
    X_out = X_out/256*100;
    Y_out = ( Wire.read()| Wire.read() << 8); // Y-axis value
    Y_out = Y_out/256*100;
    xcord=map(X_out,-200,200,100,999);
    ycord=map(Y_out,-200,200,100,999);
    Serial.print(xcord);
    Serial.print(ycord);
    if (lstate == LOW)
    Serial.print(1);
    else 
    Serial.print(0);
    if (rstate == LOW)
    Serial.println(1);
    else 
    Serial.println(0);
    bluetooth.print(xcord);
    bluetooth.print(ycord);
    if (lstate == LOW)
    bluetooth.print(1);
    else 
    bluetooth.print(0);
    if (rstate == LOW)
    bluetooth.print(1);
    else 
    bluetooth.print(0);
//    delay(4000);
    delay(500);
   }
}
