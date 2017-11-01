#include"functions.c";
#include"verkefni3.c"

task drive_around{
	while(True){
			while(SensorValue(lightSensor) < 200){
					while(SensorValue(sonarFront) > 80 || SensorValue(sonarFront) == -1){
						motor[rightMotor] = 63;
						motor[leftMotor]  = 63;
					}
						auto_turn(300);
			}
	}
}
