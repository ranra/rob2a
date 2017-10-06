#include "functions.c"
#include "meter.h";





task drive_distance()

{

		int direction ;
		int distance = halfmeter;

    for( int i = 0; i < 6; i++){
    	reset_motors();
    	wait1Msec(1000);

    if(i % 2 != 0 ){direction = -1;}
		else{
			direction = 1;
			if (i != 0){distance += halfmeter	+100;}
		}

		drive_straight(direction,distance);


	}


	}


task drive_and_turn()
{int direction = 1;
	int distance = halfmeter;
	for(int i = 0; i < 4; i++)
		{	reset_motors();
    	wait1Msec(2000);

			drive_straight(direction,distance);


			if (i == 0)
				{
					auto_turn(380, 1)
					}else if( i < 3)
						{auto_turn(390, -1)
							}

			}
	}
