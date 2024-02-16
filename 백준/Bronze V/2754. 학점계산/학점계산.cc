#include <iostream>

using namespace std;

int main() {
	string grade;
	cin >> grade;

	if (grade == "A+") {
		cout << 4.3;
	}
	else if (grade == "A0") {
		printf("%.1f", 4.0);
	}
	else if (grade == "A-") {
		cout << 3.7;
	}
	else if (grade == "B+") {
		cout << 3.3;
	}
	else if (grade == "B0") {
		printf("%.1f", 3.0);
	}
	else if (grade == "B-") {
		cout << 2.7;
	}
	else if (grade == "C+") {
		cout << 2.3;
	}
	else if (grade == "C0") {
		printf("%.1f", 2.0);
	}
	else if (grade == "C-") {
		cout << 1.7;
	}
	else if (grade == "D+") {
		cout << 1.3;
	}
	else if (grade == "D0") {
		printf("%.1f", 1.0);
	}
	else if (grade == "D-") {
		cout << 0.7;
	}
	else {
		printf("%.1f", 0.0);
	}


	return 0;
}