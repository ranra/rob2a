#include"values.h"

void reset_sensors (){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder]  = 0;
}

void reset_motors(){
	motor[leftMotor] = 0;
  motor[rightMotor] = 0;
}



void drive_straight (int direction, int distance){
	reset_sensors();
	while(abs(SensorValue[rightEncoder]) != distance ){
		if(abs(SensorValue[rightEncoder]) == SensorValue[leftEncoder]){
			motor[rightMotor] = 80 * direction;
			motor[leftMotor]  = 70 * direction;
		}
		else if(abs(SensorValue[rightEncoder]) > SensorValue[leftEncoder]){
			motor[rightMotor] = 80 * direction;
			motor[leftMotor]  = 75 * direction;
		}
		else{
			motor[rightMotor] = 80 * direction;
			motor[leftMotor]  = 70 * direction;
		}
	}
}


void auto_turn(int turn_degrees, int turn_direction = 1){
	string what_encoder;
	if (turn_direction == 1){
		what_encoder = rightEncoder;
	}
	else{
		what_encoder = leftEncoder;
	}
	reset_sensors();
	while(abs(SensorValue[what_encoder]) != turn_degrees ){
		motor[leftMotor] = 70 * -turn_direction;
		motor[rightMotor] = 80 * turn_direction ;
	}
	reset_motors();
}
