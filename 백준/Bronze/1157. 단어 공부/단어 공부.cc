#include <iostream>
#include <vector>

using namespace std;

int main() {
	int dict[150] = {0};

	string input;
	cin >> input;
	// 대소문자 구분 x

	int ascii;
	for (int i = 0; i < input.size(); i++) {
		ascii = input[i];
		if (ascii >= 65 && ascii <= 90) {
			dict[ascii]++;
		}
		else {
			dict[ascii-32]++;
		}
	}

	int max = -1;
	vector<int> maxArr;
	for (int i = 0; i < 150; i++) {
		if (dict[i] > max) {
			if (!maxArr.empty()) {
				maxArr.clear();
			}
			max = dict[i];
			maxArr.push_back(i);
		}
		else if (dict[i] == max) {
			maxArr.push_back(i);
		}
	}

	if (maxArr.size() > 1) {
		cout << "?" << "\n";
	}
	if (maxArr.size() == 1) {
		char temp = maxArr[0];
		cout << temp << "\n";
	}


	return 0;
}