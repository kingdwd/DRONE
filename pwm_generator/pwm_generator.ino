int throttle = 11;
int elevator= 10;
int aileron = 06;
int rudder = 05;
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
  if(Serial.available()>0)
  Serial.println("enter your choice");
  Serial.println("1- throttle : 2 -elevator  : 3 - rudder  :  4 - aileron");
  delay(200);
  
  int command =  Serial.parseInt();
  Serial.println("enter the value : 0-1024");
  delay(200);
   
  int val =  Serial.parseInt();
  val = map(val, 0, 1024, 0, 255);
  switch(command)
  {
  case 1:
           analogWrite(throttle,val);
           break;
  case 2:
           analogWrite(elevator,val);
           break;
  case 3:
           analogWrite(aileron,127);
           break;
  case 4:
           analogWrite(rudder,127);
           break;
  default:
           Serial.println("command mismatch");
  }
}
