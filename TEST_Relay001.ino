#include <DS1302.h>
#include "DHT.h"
#include <TimerOne.h>
//--set pin DS1302
// CE/RST
// I/O or data
// CLK/SCLK
uint8_t CE_PIN = 24;
uint8_t IO_PIN = 23;
uint8_t SCLK_PIN = 22;
//set pin relay 
#define RELAY1_PIN 30
#define RELAY2_PIN 31
#define RELAY3_PIN 32
#define RELAY4_PIN 33
//--DHT PIN 
#define DHTPIN 27
#define DHTTYPE DHT22 
//#define DHTTYPE DHT11
Time getT;
String getTimer,str,check;
boolean StatusR1,StatusR2,StatusR3,StatusR4;
boolean schoZone,schoTemp,schoHumi;
//--strate control 
typedef struct {
  byte   state;
  byte   t_state;
  byte   h_state;
  byte   cntOn;
  byte   cnt;
} tRelay;
tRelay m_relay;
byte  TimeOn;
DS1302  rtc(CE_PIN,IO_PIN,SCLK_PIN);
void setup() {
  setMode();
  pinMode(DHTPIN,INPUT);
  pinMode(RELAY1_PIN,OUTPUT);
  pinMode(RELAY2_PIN,OUTPUT);
  pinMode(RELAY3_PIN,OUTPUT);
  pinMode(RELAY4_PIN,OUTPUT);
  //--set mode time 
  rtc.halt(false);
  rtc.writeProtect(false);
  //--serial set
  Serial.begin(9600);
  Serial.println("Time statr..");
  Timer1.initialize(1000000);//1s
  Timer1.attachInterrupt(fTimerIsr);
  //--relay set 
  relay_1_off();
  relay_2_off();
  relay_3_off();
  relay_4_off();
}
void loop() {
  runMode();
  //getTemp();
  
}
