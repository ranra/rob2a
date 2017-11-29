
#include"functions.c"
#include"values.h"

int claw_open = False
task find_ball{


	if(SensorValue(sonarFront) > proximity || SensorValue(sonarFront) == -1){
			line_follow();
	}else{
			if(claw_open == False){
					//open claw
					open_close_claw(1);
					proximity = 20;
			}else{
					open_close_claw(0);
					auto_turn(380, 1);
		   }
   }
}
