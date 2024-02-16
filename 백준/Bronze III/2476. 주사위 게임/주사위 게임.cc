#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	int a, b, c;
	int ans = 0;
	int temp;

	for (int i = 0; i < t; i++) {
		int dice[7] = { 0 };
		int max = 0;
		int max_idx = -1;

		cin >> a >> b >> c;
		dice[a]++;
		dice[b]++;
		dice[c]++;

		for (int i = 1; i <= 6; i++) {
			if (dice[i] >= max) {
				max = dice[i];
				max_idx = i;
			}
		}

		if (max == 1) {
			temp = max_idx * 100;
		}
		else if (max == 2) {
			temp = 1000 + max_idx * 100;
		}
		else {
			temp = 10000 + max_idx * 1000;
		}


		if (temp > ans) {
			ans = temp;
		}
	}

	cout << ans << "\n";

	return 0;
}