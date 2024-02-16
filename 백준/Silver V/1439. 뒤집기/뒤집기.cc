#include <iostream>
#include <vector>

using namespace std;

int main() {
	string input;
	cin >> input;

	vector<char>reverse;
	char prev = input[0];
	reverse.push_back(prev);
	for (int i = 1; i < input.size(); i++) {
		if (prev != input[i]) {
			reverse.push_back(input[i]);
			prev = input[i];
		}
	}

	int zero = 0;
	int one = 0;
	for (int i = 0; i < reverse.size(); i++) {
		if (reverse[i] == '0') {
			zero += 1;
		}
		else {
			one += 1;
		}
	}

	if (zero < one) {
		cout << zero << "\n";
	}
	else {
		cout << one << "\n";
	}


	return 0;
}