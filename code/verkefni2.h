#include "meter.h";


void go_turn(int turn_degrees, int turn_direction = 1)
{ string wheel ;
	if (turn_direction == 1)
		{wheel = rightEncoder;
			}else {wheel = leftEncoder;}
	SensorValue[rightEncoder] = 0;	  // Set the encoder so that it starts counting at 0
	SensorValue[leftEncoder]  = 0;

	while(abs(SensorValue[wheel]) != turn_degrees )
{


		motor[leftMotor] = 70 * -turn_direction;
		motor[rightMotor] = 80 * turn_direction ;
	}
		motor[leftMotor] = 0;
		motor[rightMotor] = 0;


	}


void manual_stop (){
	if (vexRT[Btn8D]	== 1)
		{	motor[leftMotor] = 0;
			motor[rightMotor] = 0;
			motor[clawMotor] = 0;
			motor[armMotor] = 0;
			}
			}



void drive_straight (int direction, int distance)
{
	SensorValue[rightEncoder] = 0;	  // Set the encoder so that it starts counting at 0
	SensorValue[leftEncoder]  = 0;	  // Set the encoder so that it starts counting at 0

	while(abs(SensorValue[rightEncoder]) != distance )		// Creates an infinite loop, since "true" always evaluates to true
		{
		if(abs(SensorValue[rightEncoder]) == SensorValue[leftEncoder]) // If rightEncoder has counted the same amount as leftEncoder:
		{
			// Move Forward
			motor[rightMotor] = 80 * direction;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 70 * direction;		    // Left Motor is run at power level 80
		}
		else if(abs(SensorValue[rightEncoder]) > SensorValue[leftEncoder])	// If rightEncoder has counted more encoder counts
		{
			// Turn slightly right
			motor[rightMotor] = 80 * direction;		    // Right Motor is run at power level 60
			motor[leftMotor]  = 75 * direction;		    // Left Motor is run at power level 87
		}
		else	// Only runs if leftEncoder has counted more encoder counts
		{
			// Turn slightly le
			motor[rightMotor] = 80 * direction;		    // Right Motor is run at power level 80
			motor[leftMotor]  = 70 * direction;		    // Left Motor is run at power level 60
		}

	}

	}

void go_distance()

{
			  // Set the encoder so that it starts counting at 0
		int direction ;
		int distance = halfmeter;
		//null set motors
    for( int i = 0; i < 6; i++){
    	motor[leftMotor] = 0;
    	motor[rightMotor] = 0;
    	wait1Msec(1000);

    if(i % 2 != 0 ){direction = -1;}
		else{
			direction = 1;
			if (i != 0){distance += halfmeter	+100;}
		}

			SensorValue[rightEncoder] = 0;	  // Set the encoder so that it starts counting at 0
			SensorValue[leftEncoder]  = 0;

		drive_straight(direction,distance);


	}


	}


void drive_turn()
{int direction = 1;
	int distance = halfmeter;
	for(int i = 0; i < 4; i++)
		{	motor[leftMotor] = 0;
    	motor[rightMotor] = 0;
    	wait1Msec(2000);

			drive_straight(direction,distance);


			if (i == 0)
				{
					go_turn(380, 1)
					}else if( i < 3)
						{go_turn(390, -1)
							}

			}
	}
