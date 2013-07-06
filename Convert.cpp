/*//////////////////////////////////////////////////////////////////
  Convert.cpp - Library for converting String values to real ones.
  //////////////////////////////////////////////////////////////////
  Created by Mario Filipoviæ, 6. June. 2013 , ver.01
  // github.com/maxsonja // burn.excess@gmail.com //  
  Released into the public domain.  
  //////////////////////////////////////////////////////////////////
  value function converts one character to byte variable;
  toHex function converts one HEX byte written in String, in format of 0xNN, NN or nn and returns byte value;
  toFloat function converts float value writen in String to real float value, only numbers(and '-' sign) are supported, (3.4028E+38 is invalid);
  toInt function converts number inside of String to real number;
  //////////////////////////////////////////////////////////////////
*/

#include "Arduino.h"
#include "Convert.h"

Convert::Convert() {}

//converts one char to real value
byte Convert::value(char input)
{
  if(input >47 && input<58) return input-48;
  else if(input > 64 && input<71) return input-65+10;
  else return 0;
}

byte Convert::toHex(String input)
{
  input.toUpperCase();
  byte result = 0x00;
  //input checking
  if(input.length()==4) input = input.substring(2);
  else if(input.length()==3||input.length()>4) return 0x00;
  //
  result=this->value(input.charAt(0)); //first hex
  result=result<<4; //bitshift 4 places to the left
  result+=this->value(input.charAt(1)); //second hex
  return result;
}
	

float Convert::toFloat(String var)
{
  long dot = var.indexOf(".");
  boolean negative = false;
  float fpoint = 1;
  float result;
  
  if (dot == -1)
  {
    dot = var.length();
  }
  
  //if number negative
  if (var.charAt(0) == 45)
  {
    negative = true;
    var = var.substring(1);
    dot--;
  }
  //convert  value
  result = toInt(var.substring(0,dot));
  for(int i = dot+1; i< var.length(); i++)
  {
    fpoint *= 0.1;
    result = result + (this->value(var.charAt(i))*fpoint);
  }
  
  //fix negative number
  if(negative)
  {
    result *=-1;
  }
  
  return result;
  
}

long Convert::toInt(String input)
{
  boolean negative = false;
  long result = 0;
  //if number negative
  if(input.charAt(0) == 45)
  {
    input = input.substring(1);
    negative = true;
  }
  
  for (int i=0; i<input.length(); i++)
  {
    result = (result*10) + this->value(input.charAt(i));
  }
  if(negative) result*=-1;
  return result;
}
