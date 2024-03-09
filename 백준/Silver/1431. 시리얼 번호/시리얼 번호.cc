#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> serial;

void input() {
	cin >> n;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		serial.push_back(input);
	}
}

void sortByCond() {
	sort(serial.begin(), serial.end(), [](const string& a, const string& b) {
		if (a.size() != b.size()) {
			return a.size() < b.size();
		}
	int aSum = 0; int bSum = 0;
	int aTemp, bTemp;
	for (int i = 0; i < a.size(); i++) {
		aTemp = a[i]; bTemp = b[i];
		if (!(aTemp >= 65 && aTemp <= 90)) {
			aSum += a[i] - '0';
		}
		if (!(bTemp >= 65 && bTemp <= 90)) {
			bSum += b[i] - '0';
		}
	}
	if (aSum != bSum) {
		return aSum < bSum;
	}
	return a < b;
	});
}

void printList() {
	for (int i = 0; i < serial.size(); i++) {
		cout << serial[i] << "\n";
	}
}

int main() {
	input();
	sortByCond();
	printList();
	return 0;
}