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
	while(abs(SensorValue[rightEncoder]) < distance ){
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
	}motor[rightMotor] = 0;
			motor[leftMotor]  = 0;
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
		motor[leftMotor] = 70 * turn_direction;
		motor[rightMotor] = 80 * -turn_direction ;
	}
	reset_motors();
}


void open_close_claw(int state){

//open
	if (state == 1)
		{
	 	motor[clawMotor] = 90;
	 	wait1Msec(500);
	}

		else if (state == 2)
		{
	 	motor[clawMotor] = 150;
	 	wait1Msec(500);
	}
 //close
	else
		{
	 	motor[clawMotor] = -70;
	 	wait1Msec(100);
	}
}

void move_arm(int placement, int throw = 0){
	if (throw == 0){
		//move arm
		while (SensorValue(armEncoder) < placement){
				motor[armMotor] = 100;
		}
		while (SensorValue(armEncoder) > placement){
				motor[armMotor] = -100;
		}
	}	motor[armMotor] = 5;
	if(throw != 0){
		//throw
		while (SensorValue(armEncoder) < placement){
				motor[armMotor] = 150;
		}open_close_claw(2);
		motor[armMotor] = 1;

		while (SensorValue(armEncoder) > placement){
				motor[armMotor] = -150;
		}
		//open claw
		open_close_claw(2);
		motor[armMotor] = 1;
	}

	if (SensorValue(armEncoder) == placement){
				motor[armMotor] = 0;
				}

}





void line_follow()
{
  if(SensorValue(centerLineFollower) > threshold)
    {
      motor[leftMotor]  = -63;
      motor[rightMotor] = -63;
   }

   else if(SensorValue(rightLineFollower) > threshold)
    {
      motor[leftMotor]  = 40;
      motor[rightMotor] = -80;
    }

   else if(SensorValue(leftLineFollower) >threshold)
    {
      motor[leftMotor]  = -80;
      motor[rightMotor] = 40;
    }

}

void Turn(){
			while(vexRT[Ch1] >= 15){
				motor[leftMotor] = vexRT[Ch1]/0.5;
				motor[rightMotor] = (vexRT[Ch1]/-1) /0.5;
			}
			while(vexRT[Ch1]<= -15){
				motor[leftMotor] = (vexRT[Ch1])/0.5;
				motor[rightMotor] = (vexRT[Ch1]/-1)/0.5;
		  }
	}

	void Drive (){
		motor[leftMotor] = vexRT[Ch3];
		motor[rightMotor] = vexRT[Ch3];
	}

	void Claw(){
		if(vexRT[Btn5U] == 1){
		 	motor[clawMotor] = 90;
		 	wait1Msec(500);
		}
		else if(vexRT[Btn5D] == 1){
		 	motor[clawMotor] = -70;
		 	wait1Msec(100);
		}
		else{
		 motor[clawMotor] = 0;
		}
	}

	void Arm(){
		if(vexRT[Btn6U] == 1){
		 motor[armMotor] = 10;
		}
		else if(vexRT[Btn6D] == 1){
		 motor[armMotor] = -40;
		}
		else{
		 motor[armMotor] = 0;
		}
	}
