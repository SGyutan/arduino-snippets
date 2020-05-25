//シリアルでDigitaloutを制御するプログラミング
//PCからシリアル通信→Arduino→Digital outのHIGH/LOW制御
//TTL制御ボードの代わりにArduinoを用いる
//参考：ゆうがたの「特にコレと言って」【prog】Arduino・シリアルで文字列受信するには
//https://ch.nicovideo.jp/yugata/blomaga/ar1177727
//
//【Arduino】シリアル通信の方法
//https://shizenkarasuzon.hatenablog.com/entry/2018/09/10/150209



// 変数の定義
#define LED_PIN 13


void setup(){
  // シリアルポートを9600 bps[ビット/秒]で初期化
  Serial.begin(9600);
  // 開始メッセージ
  Serial.write("START");
  Serial.write("\n");
  Serial.write("LED ON -> on; LED OFF -> off;");
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  if (Serial.available()>0){
    String str = Serial.readStringUntil(';');
    Serial.println(str);
    if (str.equals("on")){
          Serial.println(str);
        digitalWrite(LED_PIN, HIGH);
        Serial.print("LED ON\n");
    }
    else if(str.equals("off")){
          Serial.println(str);
        digitalWrite(LED_PIN, LOW);
        Serial.print("LED OFF\n");
        }
//    else {
////      Serial.print(str);
//      Serial.print("Not operation command");
//}
  }
  }

    
  
