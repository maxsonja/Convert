/*//////////////////////////////////////////////////////////////////
  Convert.h - Library for converting String values to real ones.
  //////////////////////////////////////////////////////////////////
  Created by Mario Filipoviæ, 6. June. 2013 , ver.01
  // github.com/maxsonja // burn.excess@gmail.com //  
  Released into the public domain.  
  //////////////////////////////////////////////////////////////////
  value function converts one character to byte variable;
  toHex function converts one HEX byte writen in String, in format of 0xNN, NN or nn and returns byte value;
  toFloat function converts float value writen in String to real float value, only numbers(and '-' sign) are supported, (3.4028E+38 is invalid);
  toInt function converts number inside of String to real number;
  //////////////////////////////////////////////////////////////////
*/

#ifndef Convert_h
#define Convert_h
#include "Arduino.h"

class Convert
{
	public:
		Convert();
		byte value(char);
		byte toHex(String);
		float toFloat(String);
		long toInt(String);
};
#endif