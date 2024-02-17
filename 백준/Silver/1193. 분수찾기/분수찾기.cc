#include <iostream>

using namespace std;

int main() {
	int num;
	cin >> num;

	int k = 1;
	int sSum = 0, eSum = 0;
	while (true) {
		sSum = k * (k - 1) / 2;
		eSum = k * (k + 1) / 2;
		if ((num > sSum) && (num <= eSum)) {
			break;
		}
		k++;
	}

	int order = 1;
	if (k % 2 != 0) { // k가 홀수일 경우 -> 분자k로 시작
		for (int i = sSum+1; i <= eSum; i++) {
			if (i == num) {
				cout << k + 1 - order << "/" << order << "\n";
			}
			order++;
		}
	}
	else { // k가 짝수일 경우 -> 분모k로 시작
		for (int i = sSum + 1; i <= eSum; i++) {
			if (i == num) {
				cout << order << "/" << k+1-order << "\n";
			}
			order++;
		}
	}

	return 0;
}