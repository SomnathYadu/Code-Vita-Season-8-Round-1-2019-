//This file contains two solution
//-----1st solution------
#include <iostream>
#include <cstdlib>
#include <iomanip>

inline double _abs(double x) {
	return (x > 0) ? x : (0 - x);
}

int main() {
	int hours;
	double longitude;

	std::cin >> hours;
	std::cin >> longitude;

	while (longitude >= 360)
		longitude -= 360;

	const int time = ((hours * 60) / 360) * longitude;
	const int hour = (time / 60) % 12;
	const int minute = time % 60;

	// Angel for 1 unit
	const int hour_angle = (360 / 12);
	const int minute_angle = (360 / 60);

	// Actual hour angle = Angle of 1 hour * hour + Additional angle caused by minute
	double angle_hour = (hour_angle * hour) + ((double)minute * hour_angle / 60);
	// Actual minute angle = Angle of 1 minute * minute
	double angle_minute = minute_angle * minute;

	// We only want value not sign value
	double result = _abs(angle_hour - angle_minute);

	// Since maximum angle would be 180 and we want minimum angle 
	// so if angle is greater than 180 we will substract it with 
	// 360 degree
	if (result > 180) {
		result = 360.0 - result;
	}

	std::cout << std::fixed;
	//To print value of float to 2 decimal points
	std::cout << std::setprecision(2);
	std::cout << result;

	return 0;
}

//---------2nd solution------
/*
#include <iostream>
#include <math.h>
#include <iomanip>

float _round(float number) {

	float value = (int)(number * 100 + 0.5);
	return (float)value / 100;
}

int main() {
	float period, longitude;

	std::cin >> period;
	std::cin >> longitude;

	//To get the actual time
	float time = _round((period / 360) * longitude);
	
	int n = round(time);
	//To get minute in form of 0-100 (instead of 0-60)
	int minute = abs(time - n) * 100;
	//This will get the hours
	int hours = time - (float)(minute / 100);

	//To get angle minute hand will form
	float minute_angle = 3.6 * minute;
	//To get angle hour hand will form
	float hour_angle = (30 * hours) + ((double) 30 * minute / 100);
	
	//if hour hand form angle more than 360 then round it
	//For example hour is 15 (450 degree)then we will 
	//change it to 3 (90 degree)
	if (hour_angle <= 360)
		hour_angle -= 360;

	//To get minimum angle in positive
	float minimum_angle = abs(hour_angle - minute_angle);

	//Since we wnat minimum angle formed by minute and hour
	//hand so max angle would be 180 on clock if minimum_angle
	//more than 180, then we will subtract minimum_angle by 360 degree
	if (minimum_angle > 180)
		minimum_angle = 360 - minimum_angle;
	std::cout << std::setprecision(2);
	std::cout << minimum_angle;

	return 0;
}
*/
