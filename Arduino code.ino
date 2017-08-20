//#include <Stepper.h>
#include <Servo.h>

Servo ar;
 long positions[2];
int byteRead=0;
int d=0,p=0;
int s1=0,s2=0,a1=0,b1=0,m1=0,m2=0;
int q=0,e[250],r[250],t[250];
//const int stepsPerRevolution = 200;
#include <AccelStepper.h>
#include <MultiStepper.h>
AccelStepper stepper1(AccelStepper::FULL4WIRE, 2, 3, 4, 5);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 8, 10, 11, 12);
MultiStepper steppers;
//Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);
void setup() 
{
  Serial.begin(9600);
  pinMode(13,OUTPUT);
   pinMode(12,OUTPUT);
   ar.attach(9);
   // myStepper.setSpeed(30);
 stepper1.setMaxSpeed(90);
 stepper2.setMaxSpeed(90);
  
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  
}
int i=0,j=0,a=0,b=0,c=0;
void loop() 
{
  ar.write(30);
  while((Serial.available()>0)&&i==0)
  {
  byteRead=Serial.read();
  }
  while((Serial.available()>0)&&i==1)
  {
    if(j==0)
    { 
    a=Serial.read();
    e[q]=a;
  
    }
     if(j==1)
     {
     b=Serial.read();
      r[q]=b;
     }   
    if(j==2)
    {
    c=Serial.read();
    t[q]=c;
    }
    
    j++;
    if(j==3)
    {
    i=0;
    j=0;
    q++;
    }
  }
  if(byteRead==69)
  {
    Serial.println("A");
    i=1;
  }
  
  if(q==236&&p==0)
  {
    for(int g=0;g<236;g++)
    {
  a1=e[g];
  b1=r[g];
 if(t[g]==1)
 {
  ar.write(30);
   digitalWrite(13,HIGH);
 }
  else
  {
   ar.write(0);
    digitalWrite(13,LOW);
  }
  positions[0] =a1*2;
  positions[1] = b1*2;
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
 // delay(100);
    }
    p=1;
  }
 /* if(p==1)
  {
    m1=e[0];
    m2=r[0];
 for(int i=0;i<d;i++)
  {
    m1=m1+(e[i+1]-e[i]);
    m2=m2+(r[i+1]-r[i]);
  }
 
   positions[0] =-m1 ;
  positions[1] = -m2;
  //Serial.println("K");
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();
  }*/
 /* if(e[3]==21&&r[3]==-99&&t[3]==0)
  digitalWrite(13,HIGH);
 else
  digitalWrite(13,LOW);
  if(a==-21&&b==51&&c==51)
  digitalWrite(12,HIGH);
  else
  digitalWrite(12,LOW);
  if(a==51&&b==81&&c==39)
  digitalWrite(13,HIGH);
  else
  digitalWrite(13,LOW);
  if(a==21&&b==75&&c==0)
  digitalWrite(12,HIGH);
  else
  digitalWrite(12,LOW);*/
}
