#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMegaPi.h>

//Mblock����
//Encoder Motor
MeEncoderOnBoard Encoder_1(SLOT1);
MeEncoderOnBoard Encoder_2(SLOT2);
MeEncoderOnBoard Encoder_3(SLOT3);
MeEncoderOnBoard Encoder_4(SLOT4);

void isr_process_encoder1(void)
{
      if(digitalRead(Encoder_1.getPortB()) == 0){
            Encoder_1.pulsePosMinus();
      }else{
            Encoder_1.pulsePosPlus();
      }
}

void isr_process_encoder2(void)
{
      if(digitalRead(Encoder_2.getPortB()) == 0){
            Encoder_2.pulsePosMinus();
      }else{
            Encoder_2.pulsePosPlus();
      }
}

void isr_process_encoder3(void)
{
      if(digitalRead(Encoder_3.getPortB()) == 0){
            Encoder_3.pulsePosMinus();
      }else{
            Encoder_3.pulsePosPlus();
      }
}

void isr_process_encoder4(void)
{
      if(digitalRead(Encoder_4.getPortB()) == 0){
            Encoder_4.pulsePosMinus();
      }else{
            Encoder_4.pulsePosPlus();
      }
}

void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
            leftSpeed = -speed;
            rightSpeed = speed;
      }else if(direction == 2){
            leftSpeed = speed;
            rightSpeed = -speed;
      }else if(direction == 3){
            leftSpeed = speed;
            rightSpeed = speed;
      }else if(direction == 4){
            leftSpeed = -speed;
            rightSpeed = -speed;
      }
      Encoder_1.setTarPWM(rightSpeed);
      Encoder_2.setTarPWM(leftSpeed);
}
void moveDegrees(int direction,long degrees, int speed_temp)
{
      speed_temp = abs(speed_temp);
      if(direction == 1)
      {
            Encoder_1.move(degrees,(float)speed_temp);
            Encoder_2.move(-degrees,(float)speed_temp);
      }
      else if(direction == 2)
      {
            Encoder_1.move(-degrees,(float)speed_temp);
            Encoder_2.move(degrees,(float)speed_temp);
      }
      else if(direction == 3)
      {
            Encoder_1.move(degrees,(float)speed_temp);
            Encoder_2.move(degrees,(float)speed_temp);
      }
      else if(direction == 4)
      {
            Encoder_1.move(-degrees,(float)speed_temp);
            Encoder_2.move(-degrees,(float)speed_temp);
      }
    
}

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double t;
double currentTime = 0;
double lastTime = 0;
MeUltrasonicSensor ultrasonic_7(7);
double getLastTime(){
    	return currentTime = millis()/1000.0 - lastTime;
}



void setup(){
    //Set Pwm 8KHz
    TCCR1A = _BV(WGM10);
    TCCR1B = _BV(CS11) | _BV(WGM12);
    TCCR2A = _BV(WGM21) | _BV(WGM20);
    TCCR2B = _BV(CS21);
    
    attachInterrupt(Encoder_1.getIntNum(), isr_process_encoder1, RISING);
    Encoder_1.setPulse(8);
    Encoder_1.setRatio(46.67);
    Encoder_1.setPosPid(1.8,0,1.2);
    Encoder_1.setSpeedPid(0.18,0,0);
    attachInterrupt(Encoder_2.getIntNum(), isr_process_encoder2, RISING);
    Encoder_2.setPulse(8);
    Encoder_2.setRatio(46.67);
    Encoder_2.setPosPid(1.8,0,1.2);
    Encoder_2.setSpeedPid(0.18,0,0);
    //�˹���д
    //��ת
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(0);
    _delay(2.5);
    t = 0;
    //��ʱ������
    lastTime = millis()/1000.0;
    //������̽��ѭ��
    while(!((ultrasonic_7.distanceCm()) < 3))
    {
        _loop();
        Encoder_1.runSpeed(180);
        Encoder_2.runSpeed(70);
    }
    //����t = ��ʱ��
    t = getLastTime();
    Encoder_1.runSpeed(0);
    Encoder_2.runSpeed(0);
    //��ͷ
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(0);
    _delay(5);
    //ǰ��t�루���أ�
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(70);
    _delay(t);
    Encoder_1.runSpeed(0);
    Encoder_2.runSpeed(0);
    //��ת
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(0);
    _delay(2.5);
    //ǰ��3��
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(70);
    _delay(3);
    //��ͷ
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(0);
    _delay(5);
    //ǰ�����루���أ�
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(70);
    _delay(3);
    //��ͷ
    Encoder_1.runSpeed(180);
    Encoder_2.runSpeed(0);
    _delay(5);
    //ֹͣ���
    Encoder_1.runSpeed(0);
    Encoder_2.runSpeed(0);
    //�˹���д������Mblock����
    
}

void loop(){
    
    
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    Encoder_1.loop();
    
    Encoder_2.loop();
    
    
}