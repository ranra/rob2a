#pragma config(Sensor, in6,    xAccel,              sensorAccelerometer)
#pragma config(Sensor, dgt12,  touchSensor,         sensorTouch)
#pragma config(Motor,  port2,           right,    tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           left,     tmotorNormal, openLoop)
#pragma config(Motor,  port6,           arm,     tmotorNormal, openLoop)
#pragma config(Motor,  port5,           claw,     tmotorNormal, openLoop)

#include "drivebasetime.h"
//*!!Code automatically generated by 'R4OBOTC' configuration wizard               !!*

/*----------------------------------------------------------------------------------------------------*\
|*                                          - Point Turns -                                           *|
|*                                      ROBOTC on VEX 2.0 CORTEX                                      *|
|*                                                                                                    *|
|*  This program instructs your robot to make a point turn right for 0.75 seconds and then make a     *|
|*  point turn left for 0.75 seconds.  There is a two second pause at the beginning of the program.   *|
|*                                                                                                    *|
|*                                        ROBOT CONFIGURATION                                         *|
|*    NOTES:                                                                                          *|
|*    1)  Reversing 'rightMotor' (port 2) in the "Motors and Sensors Setup" is needed with the        *|
|*        "Squarebot" mode, but may not be needed for all robot configurations.                       *|
|*    2)  Power levels that can be assigned to a motor port range from -127 (full reverse) to         *|
|*        127 (full forward).                                                                         *|
|*    3)  Point Turns, or turns in place, are achieved by having the motors spin in opposite          *|
|*        directions.                                                                                 *|
|*                                                                                                    *|
|*    MOTORS & SENSORS:                                                                               *|
|*    [I/O Port]          [Name]              [Type]                [Description]                     *|
|*    Motor Port 2        rightMotor          VEX 3-wire module     Right side motor                  *|
|*    Motor Port 3        leftMotor           VEX 3-wire module     Left side motor                   *|
\*-----------------------------------------------------------------------------------------------4246-*/


//+++++++++++++++++++++++++++++++++++++++++++++| MAIN |+++++++++++++++++++++++++++++++++++++++++++++++//

void Accel(){

}



void touch_sensor()
{
	if(SensorValue(touchSensor) == 1)
		{
 		motor[arm] = 0;
 		}

}






void Drive ()
{
		motor[left] = vexRT[Ch3]/-1;
		motor[right] = vexRT[Ch3]/-1;


}

void Turn()
{
		if(vexRT[Ch1] >= 15)
	{
		while(vexRT[Ch1]>=15)
			{
		motor[left] = (vexRT[Ch1]/-1)/0.5;
		motor[right] = vexRT[Ch1] /0.5;
			}
	}

	///turn right
	if(vexRT[Ch1] <= -15)
	{
		while(vexRT[Ch1]<= -15)
			{
		motor[left] = (vexRT[Ch1]/-1)/0.5;
		motor[right] = vexRT[Ch1]/0.5;
	    }
  }
}

void Claw(){
if(vexRT[Btn6U] == 1)
 {
 motor[claw] = 40;
 }
 else if(vexRT[Btn6D] == 1)
 {
 motor[claw] = -40;
 }
 else
 {
 motor[claw] = 0;
 }
 }


 void Arm(){
if(vexRT[Btn5D] == 1)
 {
 motor[arm] = 10;
 }
 else if(vexRT[Btn5U] == 1)
 {
 motor[arm] = -40;
 }
 else
 {
 motor[arm] = 0;
 }
 }

task main()
{

	while(1==1){

	 Drive();
	 Turn();
	 Claw();
	 Arm();

}
}
