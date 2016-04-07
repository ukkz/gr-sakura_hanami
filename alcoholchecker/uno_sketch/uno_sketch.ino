/* お花見アルコールチェッカ Arduino UNO 版 */

int level = 0;

// アルコールチェック
void alcohol()
{
  // アルコールセンサの値を取得
  // 0~1023の範囲
  // 個々人の差が大きいと思うので適宜調整してみてください。
  level = 1023 - analogRead(A0);

  // 0~400 : 全LED消灯
  if (level < 400) {
    digitalWrite(15, 0);
    digitalWrite(16, 0);
    digitalWrite(17, 0);
    digitalWrite(18, 0);
    digitalWrite(19, 0);
  }
  // 400~500 : 緑色点灯
  if (level >= 400 and level < 500) {
    digitalWrite(15, 0);
    digitalWrite(16, 0);
    digitalWrite(17, 0);
    digitalWrite(18, 0);
    digitalWrite(19, 1);
  }
  // 500~600 : 黄色点灯
  if (level >= 500 and level < 600) {
    digitalWrite(15, 0);
    digitalWrite(16, 0);
    digitalWrite(17, 0);
    digitalWrite(18, 1);
    digitalWrite(19, 0);
  }
  // 600~700 : さくら色点灯(1つ)
  if (level >= 600 and level < 700) {
    digitalWrite(15, 0);
    digitalWrite(16, 0);
    digitalWrite(17, 1);
    digitalWrite(18, 0);
    digitalWrite(19, 0);
  }
  // 700~800 : さくら色点灯(2つ)
  if (level >= 700 and level < 800) {
    digitalWrite(15, 0);
    digitalWrite(16, 1);
    digitalWrite(17, 1);
    digitalWrite(18, 0);
    digitalWrite(19, 0);
  }
  // 800~1023 : 赤色点灯…泥酔？
  if (level >= 800) {
    digitalWrite(15, 1);
    digitalWrite(16, 0);
    digitalWrite(17, 0);
    digitalWrite(18, 0);
    digitalWrite(19, 0);
  }
}

void setup()
{
  // LEDの色はお好みで！
  pinMode(15, OUTPUT); // A1ピン・赤色
  pinMode(16, OUTPUT); // A2ピン・さくら色
  pinMode(17, OUTPUT); // A3ピン・さくら色
  pinMode(18, OUTPUT); // A4ピン・黄色
  pinMode(19, OUTPUT); // A5ピン・緑色
  // はじめはぜんぶ消灯
  digitalWrite(15, 0);
  digitalWrite(16, 0);
  digitalWrite(17, 0);
  digitalWrite(18, 0);
  digitalWrite(19, 0);
}

void loop()
{
  // 100ミリ秒おきにアルコールセンサの値をチェックしてLEDに反映させます。
  alcohol();
  delay(100);
}

