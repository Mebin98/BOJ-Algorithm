#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;

	int num = 1;
	int ptr = 0;

	while (true) {
		string numToStr = to_string(num);
		for (int i = 0; i < numToStr.size(); i++) {
			if (str[ptr] == numToStr[i]) {
				ptr++;
			}
			if (ptr == str.size()) {
				cout << num << "\n";
				return 0;
			}
		}
		num++;
	}
	return 0;
}