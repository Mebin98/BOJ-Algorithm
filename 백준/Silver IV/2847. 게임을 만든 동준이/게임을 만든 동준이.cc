#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;

	int temp;
	int level[100];
	int size;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		level[i] = temp;
		size = i;
	}

	int ans = 0;
	for (int i = size; i > 0; i--) {
		int high = level[i];
		int low = level[i - 1];

		if (low >= high) {
			level[i-1] = high - 1;
			ans += low - level[i-1];
		}
	}

	cout << ans << "\n";

	return 0;
}