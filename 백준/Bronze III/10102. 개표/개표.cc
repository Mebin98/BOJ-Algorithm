#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 0, b = 0;

	string input;
	cin >> input;

	for (int i = 0; i < n; i++) {
		if (input[i] == 'A') {
			a += 1;
		}
		else {
			b += 1;
		}
	}

	if (a > b) {
		cout << "A";
	}
	else if (a < b) {
		cout << "B";
	}
	else {
		cout << "Tie";
	}

	return 0;
}