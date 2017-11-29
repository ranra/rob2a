#include "functions.c"
#include "values.h"
task lokaverk{

		move_arm(3900);
		Sleep(500);

		open_close_claw(1);

		drive_straight(-1,400);
		//turn

		//close claw
		open_close_claw(0);
		Sleep(500);

		//swing arm
		move_arm(500);
		sleep(500);
		move_arm(2000,1);
		//open_claw
		//open_close_claw(1);
		Sleep(500);

		//turn back
		auto_turn(150, -1);
		Sleep(500);

}
