// 完全按照你的参考代码风格改写
// 用 millis() 实现 1Hz 闪烁，无 delay()

#define LED_PIN 2        // 和你代码一致的引脚
unsigned long lastMillis = 0;
const long interval = 1000;  // 1秒间隔
bool ledState = LOW;

void setup() {
  Serial.begin(115200);    // 串口初始化
  pinMode(LED_PIN, OUTPUT); // LED初始化
}

void loop() {
  // 保持你原有的串口输出
  Serial.println("Hello ESP32!");

  // millis() 非阻塞延时（核心）
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastMillis >= interval) {
    lastMillis = currentMillis;
    
    ledState = !ledState;               // 翻转状态
    digitalWrite(LED_PIN, ledState);   // 控制LED
  }
}