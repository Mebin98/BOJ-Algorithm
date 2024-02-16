#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int cute = 0;
	int unCute = 0;
	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		if (input == 1) {
			cute += 1;
		}
		else {
			unCute += 1;
		}
	}

	if (cute > unCute) {
		cout << "Junhee is cute!";
	}
	else {
		cout << "Junhee is not cute!";
	}

	return 0;
}