#include <iostream>
#include <vector>

using namespace std;

int main() {
	// a -> 300, b -> 60, c-> 10
	
	int a = 0, b = 0, c = 0;

	int input;
	cin >> input;

	// a단계

	while (true) {
		if (300 * (a + 1) > input) {
			break;
		}
		a += 1;
	}
	
	input = input - a * 300;

	// b단계
	while (true) {
		if (60 * (b + 1) > input) {
			break;
		}
		b += 1;
	}
	input = input - b * 60;

	// c단계
	while (true) {
		if (10 * (c + 1) > input) {
			break;
		}
		c += 1;
	}

	input = input - c * 10;
	
	if (input != 0) {
		cout << -1;
	}
	else {
		cout << a << " " << b << " " << c;
	}

	return 0;
}