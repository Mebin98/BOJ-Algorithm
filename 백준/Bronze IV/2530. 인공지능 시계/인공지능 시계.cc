#include <iostream>

using namespace std;

int main() {
	int crtHour, crtMin, crtSec;
	cin >> crtHour >> crtMin >> crtSec;

	int crtTotal = crtHour * 3600 + crtMin * 60 + crtSec;

	// 1 Day = 24hour = 1440min = 86400sec
	// 1 hour = 60min = 3600sec
	// 1 min = 60sec
	// 1sec = 1sec

	int time;
	cin >> time;

	int tot = time + crtTotal;

	tot = tot % 86400; // 일 넘어가는 경우

	int hour = tot / 3600;
	int min = (tot - (hour * 3600)) / 60;
	int sec = tot - (hour * 3600) - (min * 60);

	cout << hour << " " << min << " " << sec;

	
	
	
	return 0;
}