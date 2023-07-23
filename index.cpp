#include <Servo.h>
Servo myservo;
int val1=HIGH;
int val2=HIGH;
int val3=HIGH;
int val4=HIGH;
int val5=HIGH;
int pos=0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(2);
  pinMode(13,INPUT);//FLAME
  pinMode(12,INPUT);//*
  pinMode(11,INPUT);//*
  pinMode(10,INPUT);//*
  pinMode(9,INPUT);//*
  pinMode(2,OUTPUT); //SERVPO
  pinMode(7,OUTPUT);// MD1
  pinMode(6,OUTPUT);//MD1
  pinMode(5,OUTPUT);//MD1
  pinMode(4,OUTPUT); //MD1
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  val1=digitalRead(9);
  val2=digitalRead(10);
  val3=digitalRead(11);
  val4=digitalRead(12);
  val5=digitalRead(13);
  
  if (val1==1 || val2==1 || val3==1 || val4==1 || val5==1){
    while (val1==1 || val2==1 || val3==1 || val4==1 || val5==1){
    Serial.println("Fire!!!");
    digitalWrite(7,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(2,HIGH);
    
    for (pos=0; pos<=180; pos+=1){
      myservo.write(pos);
      delay(15);
    }
  }
  }
  else{
    Serial.println("No Fire.");
    digitalWrite(7,LOW);
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    digitalWrite(3,LOW);
    
  }
}
