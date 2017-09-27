
#pragma config(Sensor, in1,    leftLineFollower, sensorNone)
#pragma config(Sensor, in2,    centerLineFollower, sensorNone)
#pragma config(Sensor, in3,    rightLineFollower, sensorNone)
#pragma config(Sensor, in6,    gyro,           sensorNone)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  clawSensor,     sensorNone)
#pragma config(Sensor, dgtl6,  buttonSensor,   sensorNone)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorNone)
#pragma config(Sensor, dgtl10, armEncoder,     sensorNone)
#pragma config(Sensor, dgtl11, sonarFront,     sensorNone)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
#include "functions.h"



task main()
{
	drive_turn();
	//go_distance();
	//manual_stop();
	/*while(1==1){

	 Drive();
	 Turn();
	 Claw();
	 Arm();
	 man_stop();
	 }*/



}
