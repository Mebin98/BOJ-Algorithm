#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	string input;
	for (int i = 0; i < t; i++) {
		cin >> input;
		int score = 0;
		int point = 1;
		for (int j = 0; j < input.size(); j++) {
			if (input[j] == 'O') {
				score += point;
				point += 1;
			}
			else {
				point = 1;
			}
		}
		cout << score << "\n";
	}

	return 0;
}