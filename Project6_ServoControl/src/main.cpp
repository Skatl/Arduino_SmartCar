#include <Arduino.h>

int servopin = 9; //定义数字9接口连接伺服电机信号线
int myangle;      //定义角度变量
int pulsewidth;   //定义脉宽变量
int val;          //定义特征量

//脉冲函数
void servopules(int servopin, int myangle)
{
    pulsewidth = (myangle * 11) + 500; //将角度转化为500~2480的脉宽值
    digitalWrite(servopin, HIGH);      //将伺服电机的接口电平调至高
    delayMicroseconds(pulsewidth);     //延时脉宽的微秒值（采样保持）
    digitalWrite(servopin, LOW);       //将伺服电机的接口电平调至低
    delay(20 - pulsewidth / 1000);     //延时
}
//初始化设置
void setup()
{
    pinMode(servopin, OUTPUT); //设定舵机接口为输出接口
    Serial.begin(9600);        //连接到串行接口，波特率9600
    Serial.println("servo = o_seral_simple ready");
}
//将0~9转化为0°~180°，并让LED灯闪烁相应的次数
void loop()
{
    val = Serial.read();
    if (val > '0' & val <= '9')
    {
        val = val - '0'; //将特征量转化为数值变量
        val = val * 20;  //将数字转化为角度
        Serial.print("moving servo to");
        Serial.print(val, DEC);
        Serial.println();
        for (int i = 0; i < 50; i++) //给予伺服电机足够的时间转到指定的角度
        {
            servopules(servopin, val); //引用脉冲函数
        }
    }
}