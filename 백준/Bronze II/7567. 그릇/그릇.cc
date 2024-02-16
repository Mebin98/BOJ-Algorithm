#include <iostream>

using namespace std;

int main() {
	string input;
	cin >> input;

	// 포개어 지는거 고려
	int h = 10;
	char prev = input[0];
	bool s = true;
	for (int i = 1; i < input.size(); i++) {
		if (prev == input[i]) {
			h += 5;
		}
		else {
			h += 10;
		}
		prev = input[i];
	}
	cout << h << "\n";

	return 0;
}