#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		input = (input + 1) / 2;
		cout << input * input << "\n";
	}

	return 0;
}