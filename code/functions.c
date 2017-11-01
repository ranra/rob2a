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


void open_close_claw(int state){

//open
	if (state == 1)
		{
	 	motor[clawMotor] = 90;
	 	wait1Msec(500)
	}
 //close
	else
		{
	 	motor[clawMotor] = -70;
	 	wait1Msec(100)
	}
}


void line_follow()
{
   if(SensorValue(rightLineFollower) > threshold)
    {

      motor[leftMotor]  = 80;
      motor[rightMotor] = 30;
    }

    if(SensorValue(centerLineFollower) > threshold)
    {

      motor[leftMotor]  = 63;
      motor[rightMotor] = 63;
    }

    if(SensorValue(leftLineFollower) > threshold)
    {

      motor[leftMotor]  = 30;
      motor[rightMotor] = 80;
    }

}
