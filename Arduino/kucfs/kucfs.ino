#include <avr/wdt.h> // watch dog timer
#include <Servo.h>   // servo PWM generation

int a=0,b=0,c=0,d=0;
/*Input */
const int chA=22;  //pwm input PIC/CIC  - above threshold is autopilot
const int chB=24;  //pwm input ENGINE KILL SIGNAL - above threshold is do kill
const int throttleINT=0;//pwm input THROTTLE - 
const int throttle= 2;
const int elevatorINT=1;  //pwm input ELEVATOR - 
const int elevator= 3;
const int aileronINT=2;  //pwm input AILERON -
const int aileron=21;
const int rudderINT=3;  //pwm input RUDDER - 
const int rudder = 20;

//const int chG=34;
//const int chH=36;

//analog input pins
const int chI=A0;  //analog input AIRSPEED SENSOR

const int throttleOUT=10;
const int elevatorOUT=11;
const int aileronOUT=12;
const int rudderOUT=13;
/*change from rob's code*/
Servo servo_throttle;
Servo servo_elevator;
Servo servo_aileron;
Servo servo_rudder;
const int pwm_min = 950;
const int pwm_max = 2150;
const int pwm_midscale = 1500;
const int throttle_default = pwm_min;
const int elevator_default = pwm_midscale;
const int aileron_default  = pwm_midscale;
const int rudder_default   = pwm_midscale;
const int auto_default     = pwm_max;
const int kill_default     = pwm_max;
/*
 *  PWM output values
 */
int throttlePWM; // values for pwm pulse width in uS
int elevatorPWM;
int aileronPWM;
int rudderPWM;
int autoPWM;
int killPWM;

/*
 * measured PW values
 */
volatile int throttleEST;
volatile int throttleESTL;
volatile unsigned long prev_throttle;
volatile unsigned long next_throttle;
boolean new_throttleEST;

volatile int elevatorEST;
volatile int elevatorESTL;
volatile unsigned long prev_elevator;
volatile unsigned long next_elevator;
boolean new_elevatorEST;

volatile int aileronEST;
volatile int aileronESTL;
volatile unsigned long prev_aileron;
volatile unsigned long next_aileron;
boolean new_aileronEST;

volatile int rudderEST;
volatile int rudderESTL;
volatile unsigned long prev_rudder;
volatile unsigned long next_rudder;
boolean new_rudderEST;

unsigned long lasttime; // for timing main loop
const unsigned long looptime = 50; // ms timing for main loop rate
boolean boolcmd = false; // command available



//serial communication (I/O) pins - default is USB so don't set for now
//const int chJ=1;  //serial input FROM TK1
//const int chK=0;  //serial output TO TK1
/*angie's code*/
// Varibles to store values of each channel
// with Arduino's PWM frequency at about 500Hz, the peiod would measure 2 milliseconds 
// Time high of max period
// RANGE OF VALUES: microseconds
unsigned long ch1_high=0;  // pic/cic pin value
unsigned long ch2_high=0;  // kill pin value
unsigned long ch3_high=0;  // throttle pin value
unsigned long ch4_high=0;  // elevator pin value
unsigned long ch5_high=0;  // aileron pin value
unsigned long ch6_high=0;  // rudder pin value
//unsigned long ch7_high;  
//unsigned long ch8_high;

// Time low of max period
// RANGE OF VALUES: microseconds
unsigned long ch1_low=0;  // pic/cic pin value
unsigned long ch2_low=0;  // kill pin value
unsigned long ch3_low=0;  // throttle pin value
unsigned long ch4_low=0;  // elevator pin value
unsigned long ch5_low=0;  // aileron pin value
unsigned long ch6_low=0;  // rudder pin value
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
int rudderCommand;
// 

// the setup routine runs once when you press reset:
void setup() {
  /* Rob's code*/
   char buf[32];
  
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  Serial.setTimeout(5);
   /*
    * For Mega2560 boards with a bootloader prior to version 1.0.4
    * could have a problem with the WDT timing out during subsiquent
    * execution of the bootloader as the bootloader did not disable
    * the watchdog timer itself.
    */
   wdt_enable(WDTO_500MS); // 1/2 second watchdog timer timout
    /*
    * The default values should be carefully chosen.
    * If the WDT causes a reset, the UAV could be thrown into
    * chaos.  A more elegant soltion where previous values are
    * saved or possibly requested from the TK1 will be required.
    */
   throttlePWM = throttle_default;
   elevatorPWM = elevator_default;
   aileronPWM  = aileron_default;
   rudderPWM   = rudder_default;
    //autoPWM     = auto_default; // auto pilot off
   //killPWM     = kill_default; // signal present
    /*
    * attach the servo outputs and set defaults
    */
   //servo_auto.attach(autoOUT);
   //servo_auto.writeMicroseconds(autoPWM);
   //servo_kill.attach(killOUT);
   //servo_kill.writeMicroseconds(killPWM);
   servo_throttle.attach(throttleOUT);
   servo_throttle.writeMicroseconds(throttlePWM);
   servo_elevator.attach(elevatorOUT);
   servo_elevator.writeMicroseconds(elevatorPWM);
   servo_aileron.attach(aileronOUT);
   servo_aileron.writeMicroseconds(aileronPWM);
   servo_rudder.attach(rudderOUT);
   servo_rudder.writeMicroseconds(rudderPWM);
  // Set input pins for reading the rc receiver
  //pinMode(chA, INPUT);  // PIC/CIC
  //pinMode(chB,INPUT);   // KILL
  //pinMode(chC,INPUT);   // Throttle
  //pinMode(chD,INPUT);   // Elevators
  //pinMode(chE,INPUT);   // Ailerons
 // pinMode(chF,INPUT);   // Rudder
   pinMode(throttle, INPUT);
   pinMode(elevator, INPUT);
   pinMode(aileron, INPUT);
   pinMode(rudder, INPUT);
   attachInterrupt(throttleINT, ISRthrottlerising, RISING);
   attachInterrupt(elevatorINT, ISRelevatorrising, RISING);
   attachInterrupt(aileronINT,  ISRaileronrising,  RISING);
   attachInterrupt(rudderINT,   ISRrudderrising,   RISING);
  // Set pwm output pins
  //pinMode(throttleOUT, OUTPUT);
  //pinMode(elevatorOUT, OUTPUT);
  //pinMode(aileronOUT, OUTPUT);
  //pinMode(rudderOUT, OUTPUT); 
}
//Main Program
void loop() {  
   if (Serial.available() > 0) {
    String str = Serial.readStringUntil('\n');
    if (str == "INIT") {
      Serial.println("DONE");
    } else if (str == "GETRC") {
      getSensorInput();
    } else if (str == "OUTPUT") {
      getAutopilotControlCommand();
    } else if (str == "VERIFY") {
      verify();
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
   unsigned long nowtime = millis();
   if(nowtime >= (lasttime + looptime))
      {
         wdt_reset(); // kick the dog          
         UpdateServos(); // update  
         lasttime = nowtime;  
      }
}


void UpdateServos()
{
   // these two do not need limit testing
   // they are either pwm_min or pwm_max
  // servo_kill.writeMicroseconds(killPWM);
  // servo_auto.writeMicroseconds(autoPWM);

   // trust no one, do limit test
   if(throttlePWM < pwm_min)
      throttlePWM = pwm_min;
   else if(throttlePWM > pwm_max)
      throttlePWM = pwm_max;

   if(elevatorPWM < pwm_min)
      elevatorPWM = pwm_min;
   else if(elevatorPWM > pwm_max)
      elevatorPWM = pwm_max;

   if(aileronPWM < pwm_min)
      aileronPWM = pwm_min;
   else if(aileronPWM > pwm_max)
      aileronPWM = pwm_max;

   if(rudderPWM < pwm_min)
      rudderPWM = pwm_min;
   else if(rudderPWM > pwm_max)
      rudderPWM = pwm_max;
   servo_throttle.writeMicroseconds(throttlePWM);
   servo_elevator.writeMicroseconds(elevatorPWM);
   servo_aileron.writeMicroseconds(aileronPWM);
   servo_rudder.writeMicroseconds(rudderPWM);
}

void getSensorInput()
{
  char buf[128]; 
 if (ch1_high == 0)
  {
     ch1_duty_cycle = 0;
  }
  else
  {  
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
   
  if (ch2_high == 0)
  {
     ch2_duty_cycle = 0;
  }
  else
  {
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
  
  if (ch3_high == 0)
  {
     ch3_duty_cycle = 0;
  }
  else
  {
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
  if (ch4_high == 0)
  {
     ch4_duty_cycle = 0;
  }
  else
  {
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
   if (ch5_high == 0)
  {
     ch5_duty_cycle = 0;
  }
  else
  {
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
  if (ch6_high == 0)
  {
     ch6_duty_cycle = 0;
  }
  else
  {
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
    sprintf(buf, "%d %d %d %d %d %d %d", ch1_duty_cycle, ch2_duty_cycle, ch3_duty_cycle, 
        ch4_duty_cycle, ch5_duty_cycle, ch6_duty_cycle, ch9);
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
}
void verify()
{
    char buf1[128];
    sprintf(buf1,"%d %d %d %d",throttleIN,elevatorIN,aileronIN,rudderIN);
    Serial.println(buf1);    
}
int doKill()
{
  // NOTE change 0 to kill signal threshold pulse width
  if (ch2_duty_cycle > 0)
  {
     // set Throttle Command to 0 -- default other surfaces to RC
    throttlePWM = 0;
    elevatorPWM = ch4_duty_cycle;
    aileronPWM = ch5_duty_cycle;
    rudderPWM = ch6_duty_cycle;
    //Serial.println ("KILL is HIGH!");  //Display text string on Serial Monitor to distinguish variables
    return 1;  
  }
  else
  {
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
    throttlePWM = ch3_duty_cycle;
    elevatorPWM = ch4_duty_cycle;
    aileronPWM = ch5_duty_cycle;
    rudderPWM = ch6_duty_cycle;
}
void commmandSurfacesAutopilot()
{
    throttlePWM = throttleIN;
    elevatorPWM = elevatorIN;
    aileronPWM = aileronIN;
    rudderPWM = rudderIN;
}
void ISRthrottlerising()
{
   prev_throttle = micros();
   if(a)
    {
      throttleESTL=prev_throttle-next_throttle;
      ch3_low=throttleESTL;
    }
   a=1;   
   attachInterrupt(throttleINT, ISRthrottlefalling, FALLING);
}

void ISRthrottlefalling()
{
   next_throttle = micros() ;
   throttleEST=next_throttle - prev_throttle;
   ch3_high=throttleEST;
   attachInterrupt(throttleINT, ISRthrottlerising, RISING);
   new_throttleEST = true;
}

void ISRelevatorrising()
{
    prev_elevator = micros();
   if(b)
     {
       elevatorESTL=prev_elevator-next_elevator;
       ch4_low=elevatorESTL;
     }     
     b=1;
   attachInterrupt(elevatorINT, ISRelevatorfalling, FALLING);
}

void ISRelevatorfalling()
{
   next_elevator = micros() ;
   elevatorEST=next_elevator - prev_elevator;
   ch4_high=elevatorEST;
   attachInterrupt(elevatorINT, ISRelevatorrising, RISING);
   new_elevatorEST = true;
}

void ISRaileronrising()
{
   prev_aileron = micros();
   if(c)
     {
      aileronESTL=prev_aileron-next_aileron;
      ch5_low=aileronESTL;
     }
     c=1;
   attachInterrupt(aileronINT, ISRaileronfalling, FALLING);
}


void ISRaileronfalling()
{
   next_aileron = micros() ;
   aileronEST=next_aileron - prev_aileron;
   ch5_high=aileronEST;
   attachInterrupt(aileronINT, ISRaileronrising, RISING);
   new_aileronEST = true;
}

void ISRrudderrising()
{
   prev_rudder = micros();
   if(d)
     {
       rudderESTL=prev_rudder-next_rudder;
       ch6_low=rudderESTL;
     }
   d=1;
   attachInterrupt(rudderINT, ISRrudderfalling, FALLING);
}
void ISRrudderfalling()
{
   next_rudder = micros() ;
   rudderEST=next_rudder - prev_rudder;
   ch6_high=rudderEST;
   attachInterrupt(rudderINT, ISRrudderrising, RISING);
   new_rudderEST = true;
}



