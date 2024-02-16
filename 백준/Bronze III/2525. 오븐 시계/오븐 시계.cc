#include <iostream>

using namespace std;

int main() {
	int hour, min;
	cin >> hour >> min;

	int add;
	cin >> add;

	int temp = min + add;

	int h = temp / 60;
	int m = temp % 60;

	hour = hour + h;
	if (hour >= 24) {
		hour = hour - 24;
	}
	min = m;

	cout << hour << " " << min;


	return 0;
}