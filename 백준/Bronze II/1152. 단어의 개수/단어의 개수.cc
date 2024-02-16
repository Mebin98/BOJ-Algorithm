#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	getline(cin, input);

	if (input[0] == ' ' && input.size() == 1) {
		cout << 0;
		return 0;
	}

	int start;
	int end;
	if (input[0] == ' ' && input[input.size()-1] == ' ') {
		start = 1;
		end = input.size() - 2;
	}
	else if(input[0] == ' ' && input[input.size() - 1] != ' ') {
		start = 1;
		end = input.size() - 1;
	}
	else if (input[0] != ' ' && input[input.size() - 1] == ' ') {
		start = 0;
		end = input.size() - 2;
	}
	else {
		start = 0;
		end = input.size() - 1;
	}

	int ans = 1;
	for (int i = start; i <= end; i++) {
		if (input[i] == ' ') {
			ans += 1;
		}
	}

	cout << ans << "\n";


	return 0;
}