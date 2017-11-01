#include"functions.c"
#include"values.h"

task find_ball{

	while(SensorValue(sonarFront) > proximity || SensorValue(sonarFront) == -1)
		{
			line_follow();
	}
		open_close_claw(1);
		proximity = 20;
		open_close_claw(0);
		auto_turn(380, 1);

}
