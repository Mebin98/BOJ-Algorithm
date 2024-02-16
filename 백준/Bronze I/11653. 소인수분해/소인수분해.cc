#include <iostream>

using namespace std;
int i, n;

void decompose(int num) {
	if (num == 1) {
		return;
	}

	for (i = 2; i <= num; i++) {
		if (num % i == 0) {
			cout << i << "\n";
			num = num / i;
			decompose(num);
			return;
		}
	}
}

int main() {
	cin >> n;
	if (n == 1) {
		return 0;
	}
	
	for (i = 2; i <= n; i++) {
		if (n % i == 0) {
			cout << i << "\n";
			n = n / i;
			decompose(n);
			return 0;
		}
	}
}