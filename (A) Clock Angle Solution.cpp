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
