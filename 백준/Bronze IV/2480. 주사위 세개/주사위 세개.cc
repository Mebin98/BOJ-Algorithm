#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	int dice[7] = { 0 };
	cin >> a >> b >> c;

	dice[a] += 1;
	dice[b] += 1;
	dice[c] += 1;

	int max = 0;
	int max_index = -1;
	for (int i = 1; i <= 6; i++) {
		if (dice[i] >= max) {
			max = dice[i];
			max_index = i;
		}
	}

	if (max == 1) {
		cout << max_index * 100;
	}
	else if (max == 2) {
		cout << 1000 + max_index * 100;
	}
	else {
		cout << 10000 + max_index * 1000;
	}

	return 0;
}