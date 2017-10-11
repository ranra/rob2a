#include"functions.c"
#include"meter.h"

task follow_line{
	while(True){
   if(SensorValue(lineFollowerRIGHT) > threshold)
    {

      motor[leftMotor]  = 63;
      motor[rightMotor] = 0;
    }

    if(SensorValue(lineFollowerCENTER) > threshold)
    {

      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }

    if(SensorValue(lineFollowerLEFT) > threshold)
    {

      motor[leftMotor]  = 0;
      motor[rightMotor] = 63;
    }

	}
}
