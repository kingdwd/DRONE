int throttle = 11;
int elevator= 10;
int aileron = 06;
int rudder = 05;
int i;
void setup()
{
  pinMode(throttle,OUTPUT);
  pinMode(elevator,OUTPUT);
  pinMode(aileron,OUTPUT);
  pinMode(rudder,OUTPUT);
   Serial.begin(115200);
   Serial.setTimeout(1500);
}
void loop()

{   

  Serial.println("enter your choice");
  Serial.println("1- throttle : 2 -elevator  : 3 - rudder  :  4 - aileron");
  delay(200);
  while(Serial.available()==0){}

  int command =  Serial.parseInt();
  Serial.flush();
  Serial.println("enter the value : 0-1024");
  //delay(200);
  while(Serial.available()==0){}
  int val =  Serial.parseInt();
  Serial.flush();
  val = map(val, 0, 1024, 0, 255);
  Serial.println(val);
  switch(command)
  {
  case 1:  while(Serial.available()==0)
           analogWrite(throttle,val);
           i=Serial.parseInt();
           break;
  case 2:  while(Serial.available()==0)
           analogWrite(elevator,val);
           i=Serial.parseInt();
           break;
  case 3:  while(Serial.available()==0)
           analogWrite(aileron,127);
           i=Serial.parseInt();
           break;
  case 4:  while(Serial.available()==0)
           analogWrite(rudder,127);
           i=Serial.parseInt();
           break;
  default:
           Serial.println("command mismatch");
  }
}
