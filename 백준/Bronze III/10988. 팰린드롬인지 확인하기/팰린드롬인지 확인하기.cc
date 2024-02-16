#include <iostream>

using namespace std;

int main() {
	string input;
	cin >> input;

	bool pelindrome = true;
	if (input.size() % 2 != 0) { // 길이 홀수
		for (int i = 0; i < (input.size() -1) / 2; i++) {
			if (input[i] != input[input.size() - 1 - i]) {
				pelindrome = false;
			}
		}
	}
	else { // 길이 짝수
		for (int i = 0; i < input.size() / 2; i++) {
			if (input[i] != input[input.size() - 1 - i]) {
				pelindrome = false;
			}
		}
	}

	if (pelindrome) {
		cout << 1;
	}
	else {
		cout << 0;
	}

	return 0;
}