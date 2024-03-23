#include <iostream>

using namespace std;

int main() {
	int t, n;
	cin >> t;

	int idx = 0;
	for (int i = 0; i < t; i++) {
		cin >> n;
		idx = 0;
		if (n <= 0) {
			cout << "This case is not allowed\n";
			return -1;
		}

		int q, r;
		while (true) {
			q = n / 2;
			r = n % 2;
			if (r == 1) cout << idx << " ";
			n = q;
			if (n == 0) {
				break;
			}
			idx++;
		}
	}

	return 0;
}