#define LED_PIN 2

// 时间参数
const unsigned long shortBlink = 300;
const unsigned long longBlink  = 900;
const unsigned long gap         = 200;
const unsigned long endWait     = 3000;

unsigned long preTime = 0;
// 0短 1长 9结尾停顿
byte sos[] = {0,0,0,1,1,1,0,0,0,9};
int cnt = 0;
bool ledOn = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  unsigned long now = millis();
  unsigned long t = (sos[cnt]==0) ? shortBlink : (sos[cnt]==1) ? longBlink : endWait;

  if(now - preTime >= t){
    preTime = now;
    if(sos[cnt] == 9){
      cnt = 0;
      ledOn = false;
    }else{
      ledOn = !ledOn;
      if(!ledOn) cnt++;
    }
    digitalWrite(LED_PIN, ledOn);
  }
}