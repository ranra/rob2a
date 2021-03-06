#pragma config(Sensor, in1,    rightLineFollower, sensorLineFollower)
#pragma config(Sensor, in2,    centerLineFollower, sensorLineFollower)
#pragma config(Sensor, in3,    leftLineFollower, sensorLineFollower)
#pragma config(Sensor, in4,    armEncoder,     sensorPotentiometer)
#pragma config(Sensor, in6,    lightSensor,    sensorReflection)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  clawSensor,     sensorNone)
#pragma config(Sensor, dgtl6,  buttonSensor,   sensorNone)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorNone)
#pragma config(Sensor, dgtl11, sonarFront,     sensorSONAR_cm)
#pragma config(Motor,  port2,           rightMotor,    tmotorVex393, openLoop)
#pragma config(Motor,  port3,           leftMotor,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           armMotor,      tmotorVex393, openLoop)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "functions.c"
#include "values.h";
#include "verkefni2.c"
#include "verkefni3.c"
#include "verkefni4.c"
#include "verkefni5.c"
//#include "verkefni6.c"


task main()
	{

		while(True){

			StartTask(remote_controller);//verkefni3

			if( vexRT[Btn7U] == 1){
				StartTask(drive_distance);//verkefni2
			}
			if( vexRT[Btn7L] == 1){
					StartTask(drive_and_turn);//verkefni2
			}
			if( vexRT[Btn7D] == 1){
					StartTask(drive_around);//verkefni4
			}
			if( vexRT[Btn7R] == 1){
					StartTask(follow_line);//verkefni5
			}
		//if( vexRT[Btn7R] == 1){
			//		StartTask(find_ball);//verkefni6
			//}
			if( vexRT[Btn8D] == 1){
				StopAllTasks();
			}
		}

	}
