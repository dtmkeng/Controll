//relay 1 เปิดน้ำรด
//ralay 2 check humi if>sethumi 
//relay 3 check temp if>settemp relay 2 on relay on
String timeSet[20];
char inchar =-1;
byte index=0;
String SetMode;
const long interval = 10000; //delay ....ms
unsigned long previousMillis = 0;
byte fRelayState00(){
  relay_4_on();
  if(humi>68){
    schoHumi = false;
    m_relay.h_state = 1;
    }
  }
byte fRelayState01(){
  relay_4_off();
  if(humi<68){
    schoHumi = false;
    m_relay.h_state = 0;
    }
  }
byte fRelayState0(){
  //relay of
   relay_2_on();
   relay_3_on();
   if(temp<34){
    schoTemp = false;
    m_relay.t_state = 1;
    }
}
byte fRelayState1(){
  relay_2_off();
  relay_3_off();
  getTemp();
  if(temp>34){
  m_relay.t_state = 0;
  schoTemp = false;
   }
}
byte fRelayState100(){
  //relay on
 unsigned long currentMillis = millis();
   relay_1_on(); //relay 1 on
   if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
     m_relay.cnt =0;
     m_relay.state =101;
  }
}
byte fRelayState101(){
    relay_1_off(); //relay 1 off
}
void setTimeDelay(byte t){
  
}
String setRelayWork(String h,String m,String s){
  ////00.00.00
      return h+'.'+m+'.'+s;
}
void getString(){
  while(Serial.available()>0){
    delay(5);
    inchar =Serial.read();
    timeSet[index]=inchar;
    index++;
    timeSet[index]= ' \0';
    }
  }
void Settime(){  
}
byte entery1(){
  if(schoZone){
    //----
      }else{
          switch(m_relay.state){
            case 100 : fRelayState100();break;
            case 101 : fRelayState101();break;
            default : break;
         }
    

         }
    return 0;
  }
byte entery2(){
    if(schoTemp){
      
      }else{
        switch(m_relay.t_state){
        case 1   : fRelayState1();break;
        case 0   : fRelayState0();break;
           }
        }
        return 0; 
    }
byte entery3(){
  if(schoHumi){
      
      }else{
        switch(m_relay.h_state){
        case 1   : fRelayState01();break;
        case 0   : fRelayState00();break;
           }
        }
        return 0; 
    }
  
byte checkTime(){
  getsec();
  if(check=="11"||check=="22"||check=="44"){
    schoZone =false;
    m_relay.state=100;
    }
  }
byte setMode(){
  m_relay.state=101;
  m_relay.t_state=1;
  m_relay.h_state=0;
  m_relay.cntOn=TimeOn;
  m_relay.cnt = 0;
 }
byte runMode(){
  entery1();
   entery2();
   entery3();
  getTemp();
  checkTime();
  //Serial.println(m_Delay.state);
 }
// mode relay 
void relay_1_off(){
  StatusR1 = false;
  digitalWrite(RELAY1_PIN,HIGH);
}
void relay_1_on(){
  StatusR1 = true;
  digitalWrite(RELAY1_PIN,LOW);
}
void relay_2_off(){
  StatusR2 = false;
  digitalWrite(RELAY2_PIN,HIGH);
}
void relay_2_on(){
  StatusR2 = true;
  digitalWrite(RELAY2_PIN,LOW);
}
void relay_3_off(){
  StatusR3 = false;
  digitalWrite(RELAY3_PIN,HIGH);
}
void relay_3_on(){
  StatusR3 = true;
  digitalWrite(RELAY3_PIN,LOW);
}
void relay_4_off(){
  StatusR4 = false;
  digitalWrite(RELAY4_PIN,HIGH);
}
void relay_4_on(){
  StatusR1 = true;
  digitalWrite(RELAY4_PIN,LOW);
}
