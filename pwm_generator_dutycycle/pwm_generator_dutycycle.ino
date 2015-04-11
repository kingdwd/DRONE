int throttle = 11;
int elevator= 10;
int aileron = 06;
int rudder = 05;
int i;
  int q;

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
  while(Serial.available()==0){}
  int command =  Serial.parseInt();
  Serial.print("The selected command is  ");
  Serial.println(command);
  Serial.println("enter the value : 0-255");
  while(Serial.available()==0){}
  int val =  Serial.parseInt();
  Serial.print("the given value is :  ");
  Serial.println(val);
  //val = map(val, 0, 1024, 0, 255);
  //Serial.println(val);
  switch(command)
  {
  case 1:  while(Serial.available()==0)
           analogWrite(throttle,val);
           i=Serial.parseInt();
           val=0;
           analogWrite(throttle,val);
           Serial.println("Throttle set to 0");
           break;
  case 2:  while(Serial.available()==0)
           analogWrite(elevator,val);
           i=Serial.parseInt();
           val=0;
           analogWrite(elevator,val);
           Serial.print("Elevator set to ");
           Serial.println(val);
           break;
  case 3:  while(Serial.available()==0)
           analogWrite(aileron,val);
           i=Serial.parseInt();
           val=0;
           analogWrite(aileron,val);
           Serial.println( "Aileron set to 0");
           break;
  case 4:  while(Serial.available()==0)
           analogWrite(rudder,val);
           i=Serial.parseInt();
           val=0;
           analogWrite(rudder,val);
           Serial.println("Rudder set to 0");
           break;
  default:
           Serial.println("command mismatch");
  }
}
