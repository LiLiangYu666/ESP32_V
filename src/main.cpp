#include "Arduino.h"

float analog_value = 0;                                     // 用于存储电位器值的变量
const int ANALOG_PIN = 34;
int a[10];

void write(){
  int analog_value = 0;
  int acc = 0;
  for (int j = 0; ; j++) {
    for (int i = 0; i < 10; i++) {                      
      acc = acc - a[i] ;
      a[i] = analogRead(ANALOG_PIN);
      acc = acc + a[i] ;
      analog_value = acc / 10 ;  //* 0.807/ 4095 * 4027
      Serial.println(analog_value);
      delay(300);
    }
    if (j == 100){
      j = 0;
    }

  }
}

void setup() {
  Serial.begin(115200);
  analogSetPinAttenuation(ANALOG_PIN, ADC_11db);
  Serial.println("Calibrating... Ensure that no current flows through the sensor at this moment");
  Serial.println("Done!");
}


void loop() {
  // analog_value = analogRead(ANALOG_PIN);
  // Serial.println(analog_value);
  write();
  delay(300);
}








//analog_value = ((float)acc / 8.0 / 4095 * 4.027 ) * 0.186;
// analogSetPinAttenuation(ANALOG_PIN, ADC_0db);
// analogSetClockDiv(1);


// unsigned char GetMedianNum(int * bArray, int iFilterLen)
// {
//   int i,j;                                   // 循环变量
//   unsigned char bTemp;                       // 用冒泡法对数组进行排序
//   for (j = 0; j < iFilterLen - 1; j ++)
//   {
//     for (i = 0; i < iFilterLen - j - 1; i ++)
//     {
//       if (bArray[i] > bArray[i + 1])                     // 互换
//       {
//         bTemp = bArray[i];
//         bArray[i] = bArray[i + 1];
//         bArray[i + 1] = bTemp;
//       }
//     }
//   }
//   // 计算中值
//     if ((iFilterLen & 1) > 0)
//     {
//       // 数组有奇数个元素，返回中间一个元素
//       bTemp = bArray[(iFilterLen + 1) / 2];
//     }
//     else
//     {
//       // 数组有偶数个元素，返回中间两个元素平均值
//       bTemp = (bArray[iFilterLen / 2] + bArray[iFilterLen / 2 + 1]) / 2;
//     }
//   return bTemp;
// }