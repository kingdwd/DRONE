const int chA=22;  //pwm input PIC/CIC  - above threshold is autopilot
const int chB=24;  //pwm input ENGINE KILL SIGNAL - above threshold is do kill
const int chC=26;  //pwm input THROTTLE - 
const int chD=28;  //pwm input ELEVATOR - 
const int chE=30;  //pwm input AILERON - 
const int chF=32;  //pwm input RUDDER - 
//const int chG=34;
//const int chH=36;

//analog input pins
const int chI=A0;  //analog input AIRSPEED SENSOR

const int tpinOUT=10;
const int epinOUT=11;
const int apinOUT=12;
const int rpinOUT=13;

//serial communication (I/O) pins - default is USB so don't set for now
//const int chJ=1;  //serial input FROM TK1
//const int chK=0;  //serial output TO TK1

// Varibles to store values of each channel
// with Arduino's PWM frequency at about 500Hz, the peiod would measure 2 milliseconds 
// Time high of max period
// RANGE OF VALUES: microseconds
unsigned long ch1_high;  // pic/cic pin value
unsigned long ch2_high;  // kill pin value
unsigned long ch3_high;  // throttle pin value
unsigned long ch4_high;  // elevator pin value
unsigned long ch5_high;  // aileron pin value
unsigned long ch6_high;  // rudder pin value
//unsigned long ch7_high;  
//unsigned long ch8_high;

// Time low of max period
// RANGE OF VALUES: microseconds
unsigned long ch1_low;  // pic/cic pin value
unsigned long ch2_low;  // kill pin value
unsigned long ch3_low;  // throttle pin value
unsigned long ch4_low;  // elevator pin value
unsigned long ch5_low;  // aileron pin value
unsigned long ch6_low;  // rudder pin value
//unsigned long ch7_low;  
//unsigned long ch8_low;

// Total Period
// RANGE OF VALUES: microseconds
unsigned long ch1_period;  // pic/cic pin value
unsigned long ch2_period;  // kill pin value
unsigned long ch3_period;  // throttle pin value
unsigned long ch4_period;  // elevator pin value
unsigned long ch5_period;  // aileron pin value
unsigned long ch6_period;  // rudder pin value
//unsigned long ch7_period;  
//unsigned long ch8_period;

// RANGE OF VALUES: %duty cycle at a range of 0-255
int ch1_duty_cycle;
int ch2_duty_cycle;
int ch3_duty_cycle;
int ch4_duty_cycle;
int ch5_duty_cycle;
int ch6_duty_cycle;
//int ch7_duty_cycle;
//int ch8_duty_cycle;
//int ch9_duty_cycle;


//Values of analog input
// RANGE: 0 to 1024
int ch9;  // pitot tube pin value

//Values of TK1 input
// RANGE: 0 to 255
int throttleIN;
int elevatorIN;
int aileronIN;
int rudderIN;

//Values of OUTPUT TO SERVO
// RANGE: - to 255
int ThrottleCommand;
int ElevatorCommand;
int AileronCommand;
int RudderCommand;

// 


// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  Serial.setTimeout(10);

  // Set input pins for reading the rc receiver
  pinMode(chA, INPUT);  // PIC/CIC
  pinMode(chB,INPUT);   // KILL
  pinMode(chC,INPUT);   // Throttle
  pinMode(chD,INPUT);   // Elevators
  pinMode(chE,INPUT);   // Ailerons
  pinMode(chF,INPUT);   // Rudder
  // pinMode(chG,INPUT);
  // pinMode(chH,INPUT);
  
  // Set pwm output pins
  pinMode(tpinOUT, OUTPUT);
  pinMode(epinOUT, OUTPUT);
  pinMode(apinOUT, OUTPUT);
  pinMode(rpinOUT, OUTPUT);
 
}

//Main Program
void loop() {unsigned long start=micros();

  if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    if (str == "INIT") {
      Serial.println("DONE");
    } else if (str == "GETRC") {
      getSensorInput();
    } else if (str == "OUTPUT") {
      getAutopilotControlCommand();
    }
  }  
  // SAFETY CHECK for a kill signal even if autopilot is in control!!
  if(doKill() == 0)
  {
  
    // is autopilot in command?
    // returns 1 if true, 0 if false and -1 if there is a problem
    //Serial.println ("Checking Who is in Control:");
    int auto_value = checkAuto();
    
    if (auto_value < 1)
    {
      //use RC signals for command output
      //Serial.println ("Using RC Commands");
      commandSurfacesRC();
    }
    else
    {
      //use Autopilot signals from TK1 for command output
      //Serial.println ("Using Autopilot Commands");
      commmandSurfacesAutopilot();
    }
  }
  //output pwm control
  outputPWMcommands();
//  unsigned long fin=micros();
//  unsigned long delta=fin - start;
//  Serial.println("time");
//  Serial.println(delta); 
}

void getSensorInput()
{
  char buf[128];
  // read the input channels
  ch1_high = pulseIn (chA,HIGH, 50);  //Read and store channel 1
  if (ch1_high == 0)
  {
     ch1_duty_cycle = 0;
  }
  else
  {
    ch1_low = pulseIn (chA,LOW, 50);  //Read and store channel 1
    ch1_period = ch1_high + ch1_low;
    if (ch1_period >= ch1_high)
    {
      ch1_duty_cycle = percent(100 * ch1_high/ch1_period);
    }
    else
    {
        ch1_duty_cycle = 127; //default to 50% 
    }
  }
 
  ch2_high = pulseIn (chB,HIGH, 50);
  if (ch2_high == 0)
  {
     ch2_duty_cycle = 0;
  }
  else
  {
    ch2_low = pulseIn (chB,LOW, 50);  //Read and store channel 2
    ch2_period = ch2_high + ch2_low;
    if (ch2_period >= ch2_high)
    {
      ch2_duty_cycle = percent(100 * ch2_high/ch2_period);
    }
    else
    {
        ch2_duty_cycle = 127; //default to 50% 
    }
  }

  ch3_high = pulseIn (chC,HIGH, 50);
  if (ch3_high == 0)
  {
     ch3_duty_cycle = 0;
  }
  else
  {
    ch3_low = pulseIn (chC,LOW, 50);  //Read and store channel 3
    ch3_period = ch3_high + ch3_low;
    if (ch3_period >= ch3_high)
    {
      ch3_duty_cycle = percent(100 * ch3_high/ch3_period);
    }
    else
    {
        ch3_duty_cycle = 127; //default to 50% 
    }
  }

  ch4_high = pulseIn (chD,HIGH, 50);
  if (ch4_high == 0)
  {
     ch4_duty_cycle = 0;
  }
  else
  {
    ch4_low = pulseIn (chD,LOW, 50);  //Read and store channel 4
    ch4_period = ch4_high + ch4_low;
    if (ch4_period >= ch4_high)
    {
      ch4_duty_cycle = percent(100 * ch4_high/ch4_period);
    }
    else
    {
        ch4_duty_cycle = 127; //default to 50% 
    }
  }

  ch5_high = pulseIn (chE,HIGH, 50);
  if (ch5_high == 0)
  {
     ch5_duty_cycle = 0;
  }
  else
  {
    ch5_low = pulseIn (chE,LOW, 50);  //Read and store channel 5
    ch5_period = ch5_high + ch5_low;
    if (ch5_period >= ch5_high)
    {
      ch5_duty_cycle = percent(100 * ch5_high/ch5_period);
    }
    else
    {
        ch5_duty_cycle = 127; //default to 50% 
    }
  }
  
  ch6_high = pulseIn (chF,HIGH, 50);
  if (ch6_high == 0)
  {
     ch6_duty_cycle = 0;
  }
  else
  {
    ch6_low = pulseIn (chF,LOW, 50);  //Read and store channel 6
    ch6_period = ch6_high + ch6_low;
    if (ch6_period >= ch6_high)
    {
      ch6_duty_cycle = percent(100 * ch6_high/ch6_period);
    }
    else
    {
        ch6_duty_cycle = 127; //default to 50% 
    }
  }
  ch9 = analogRead(chI);
  
  /* TBD: use actual data */
  sprintf(buf, "10 20 30 40 50 60 70");
  Serial.println(buf);
}

int percent(int in)
{
  int ret_val;
  ret_val = (in*255)/100;
  return ret_val;
}

void getAutopilotControlCommand()
{
  throttleIN = Serial.parseInt();
  elevatorIN = Serial.parseInt();
  aileronIN = Serial.parseInt();
  rudderIN = Serial.parseInt();
  if (Serial.read() == '\n') {
    /* correctly received data */
  }
}

int doKill()
{
  // NOTE change 0 to kill signal threshold pulse width
  if (ch2_duty_cycle > 0)
  {
     // set Throttle Command to 0 -- default other surfaces to RC
    ThrottleCommand = 0;
    ElevatorCommand = ch4_duty_cycle;
    AileronCommand = ch5_duty_cycle;
    RudderCommand = ch6_duty_cycle;
    //Serial.println ("KILL is HIGH!");  //Display text string on Serial Monitor to distinguish variables
    return 1;  
  }
  else
  {
    //do nothing
     //Serial.println ("KILL is ZERO");
     return 0;
  }
}

int checkAuto()
{
  //if channel 1 is above 0 then autopilot is on
  if (ch1_duty_cycle > 0)
  {
     return 1; 
  }
  else
  {
    return 0;
  }
}

void commandSurfacesRC()
{
  ThrottleCommand = ch3_duty_cycle;
  ElevatorCommand = ch4_duty_cycle;
  AileronCommand = ch5_duty_cycle;
  RudderCommand = ch6_duty_cycle;
}

void commmandSurfacesAutopilot()
{
  ThrottleCommand = throttleIN;
  ElevatorCommand = elevatorIN;
  AileronCommand = aileronIN;
  RudderCommand = rudderIN;
}

void outputPWMcommands()
{
  //255 is 100%
  //127 is 50%
  analogWrite(tpinOUT, 127);
  //Serial.print ("tpinOUT: ");
  //Serial.print (ThrottleCommand);
  //Serial.print ("|");
  analogWrite(epinOUT, 127);
  //Serial.print ("epinOUT: ");
  //Serial.print (ElevatorCommand);
  //Serial.print ("|");
  analogWrite(apinOUT, 127);
  //Serial.print ("apinOUT: ");
  //Serial.print (AileronCommand);
  //Serial.print ("|");
  analogWrite(rpinOUT, 127);
  //Serial.print ("rpinOUT: ");
  //Serial.print (RudderCommand);
  //Serial.print ("|");
  
  //analogWrite(tpinOUT, ThrottleCommand);
  //analogWrite(epinOUT, ElevatorCommand);
  //analogWrite(apinOUT, AileronCommand);
  //analogWrite(rpinOUT, RudderCommand);
}


