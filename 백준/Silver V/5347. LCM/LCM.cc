#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	long long temp;
	while (true) {
		temp = a % b;
		if (temp == 0) {
			return b;
		}
		a = b;
		b = temp;
	}
}

long long lcm(long long a, long long b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int n;
	long long a, b, big, small;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		if (a > b) {
			big = a;
			small = b;
		}
		else {
			big = b;
			small = a;
		}
		cout << lcm(big, small) << "\n";
	}
	return 0;
}