#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;
	if (a == b) {
		cout << 0 << "\n";
		return 0;
	}

	if (b < a) {
		long long temp = b;
		b = a;
		a = temp;
	}

	cout << b - a - 1 << "\n";

	for (long long n = a + 1; n < b; n++) {
		cout << n << " ";
	}

	return 0;
}