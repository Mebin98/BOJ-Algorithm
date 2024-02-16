#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int temp;
	while (true) {
		temp = a % b;
		if (temp == 0) {
			break;
		}
		a = b;
		b = temp;
	}
	return b;
}

// 최소공배수 알고리즘
int main() {
	int t;
	cin >> t;

	int a, b;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout << (a * b) / gcd(a, b) << "\n";
	}
	return 0;
}