int state = 0;//0 未啟動；1 從半圓啟動；2 從正方形啟動

//控制設定
const int startCircleButton = ;
const int startSquareButton = ;
const int emergencyButton = ;

//馬達設定
const int leftFrontPWM= ;
const int rightFrontPWM= ;
const int leftRearPWM= ;
const int rightRearPWM= ;

const bool leftFrontDirection= ;
const bool rightFrontDirection= ;
const bool leftRearDirection= ;
const bool rightRearDirection= ;//正轉：TURE 反轉：FALSE

void setup() {
  // general setting
  serial.begin(9600);
  state = 0;
  //interrupt setting
  attachInterrupt((digitalPinToInterrupt(startCircleButton), processcircle(), RISING); 
  attachInterrupt((digitalPinToInterrupt(startSquareButton), processSquare(), RISING); 
  attachInterrupt((digitalPinToInterrupt(emergencyButton), processEmergency(), RISING); 
}

void forward()
{
  //直線前進
}

void backward()
{
  //直線後退
}

void turnLeft()
{
  //原地左轉
}

void turnRight()
{
  //原地右轉
}

void processcircle()
{
  //走圓形路徑
}

void processSquare()
{
  //走方形路徑
}

void processEmergency()
{
  //緊急停機
  int leftFrontPWM= 0;
  int rightFrontPWM= 0;
  int leftRearPWM= 0;
  int rightRearPWM= 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
