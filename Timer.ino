String getsec(void){
  getT = rtc.getTime();
  str=rtc.getTimeStr();
  check=getT.sec;
 //check=getT.min;
 //check=getT.hour;
  Serial.println(getT.sec, DEC);
  //erial.println("s");
  return check;
}
void fTimerIsr(){
  schoZone = false;
  }
