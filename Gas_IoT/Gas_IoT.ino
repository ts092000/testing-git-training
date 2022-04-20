#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
  /*BlynkTimer cho phép bạn gửi dữ liệu định kỳ với khoảng thời gian nhất định mà không ảnh hưởng đến quy trình*/
BlynkTimer timer;
  /* kết nối auth token, name wifi, password*/
char auth[] = "QVJukjVKzxx0WRB-IFjva9SeNpp6nq-f";
char ssid[] = "huy";
char pass[] = "quanghuy123";

int n;

void setup()
{
     /* khai báo serial tốc độ là 9600 mỗi giây*/
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
    /*thiết lập đầu ra của Led*/
  pinMode(16,OUTPUT);
  pinMode(5,OUTPUT);
    /*Xác định thời gian gửi dữ liệu lên server Blynk, 1s gửi dữ liệu 1 lần*/
  timer.setInterval(1000L, sendUptime);
}


void sendUptime()
{
  /*gửi giá trị đến Blynk với Pin là V1 và n là giá trị*/
  Blynk.virtualWrite(V1, n);
}

void loop()
{
  Blynk.run();
  timer.run();

  /*n đọc giá trị của chân 34*/
  n=analogRead(34);
  Serial.println(n);

  /*Nếu lớn hơn 3500 thì tắt led ở chân 16*/
  if(n>3500)
  {
     digitalWrite(16,LOW);
    /*digitalWrite(5,HIGH);   */
  }
  /*Nếu nhỏ hơn 3500 thì sáng led ở chân 16*/
  if(n<3500)
  {
      digitalWrite(16,HIGH);
      /*digitalWrite(5,LOW);*/
  }

}
