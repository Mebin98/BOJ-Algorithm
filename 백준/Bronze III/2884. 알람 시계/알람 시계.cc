#include <iostream>

using namespace std;

int main() {
	int hour, min;
	cin >> hour >> min;

	int tot = hour * 60 + min;
	int ans = tot - 45;

	if (ans < 0) {
		ans = ans + 1440;
	}
	else if (ans >= 1440) {
		ans = ans % 1440;
	}

	int ansHour = ans / 60;
	int ansMin = ans % 60;

	cout << ansHour << " " << ansMin;

	return 0;
}