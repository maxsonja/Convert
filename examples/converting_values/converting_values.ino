#include <Convert.h>

Convert convert;

void setup()
{
  Serial.begin(9600);
  delay(1500);

  int tempInt;
  float tempFloat;
  byte tempByte;
  
  Serial.println("----------------------------");
  
  tempInt=convert.toInt("42");
  Serial.print("positive Int: ");
  Serial.println(tempInt);
  
  tempInt=convert.toInt("-1234");
  Serial.print("negative Int: ");
  Serial.println(tempInt);
  
  Serial.println("----------------------------");
  
  tempFloat=convert.toFloat("987.65");
  Serial.print("positive float: ");
  Serial.println(tempFloat);
  
  tempFloat=convert.toFloat("-333.21");
  Serial.print("negative float: ");
  Serial.println(tempFloat);
  
  Serial.println("----------------------------");
  
  tempByte=convert.toHex("0xA1");  
  Serial.print("0xA1 converted: ");
  Serial.print(tempByte, HEX);
  Serial.print(" : ");
  Serial.println(tempByte);
  
  tempByte=convert.toHex("0xb4");
  Serial.print("0xb4 converted: ");
  Serial.print(tempByte, HEX);
  Serial.print(" : ");
  Serial.println(tempByte);
  
  tempByte=convert.toHex("FF");
  Serial.print("FF converted: ");
  Serial.print(tempByte, HEX);
  Serial.print(" : ");
  Serial.println(tempByte);
  
  tempByte=convert.toHex("0d");
  Serial.print("0d converted: ");
  Serial.print(tempByte, HEX);
  Serial.print(" : ");
  Serial.println(tempByte);
  
  
  Serial.println("----------------------------");
  
}

void loop()
{
  delay(1000);
  
}
