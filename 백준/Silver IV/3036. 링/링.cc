#include <iostream>

using namespace std;

int gcd(int x, int y) {
	int tmp;
	while (y > 0) {
		tmp = x % y;
		x = y;
		y = tmp;
	}
	return x;
}


int main() {
	int n;
	cin >> n;

	int radius[100];
	for (int i = 0; i < n; i++) {
		cin >> radius[i];
	}

	int first = radius[0];
	int div;
	for (int i = 1; i < n; i++) {
		if (first >= radius[i]) {
			div = gcd(first, radius[i]);
		}
		else {
			div = gcd(radius[i], first);
		}
		int a = first / div;
		int b = radius[i] / div;

		cout << a << "/" << b << "\n";
	}
	return 0;
}