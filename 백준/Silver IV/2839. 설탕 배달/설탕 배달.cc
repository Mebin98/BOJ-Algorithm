#include <iostream>

using namespace std;

int main() {

	int n;
	cin >> n;

	int sumIndex = 0;
	while (sumIndex <= n) {
		int x = sumIndex;
		int y = 0;

		while (y <= sumIndex && x >= 0) {
			int check = (3 * x) + (5 * y);
			if (check == n) {
				cout << sumIndex << "\n";
				return 0;
			}
			x--;
			y++;
		}
		sumIndex++;
	}
	cout << -1 << "\n";

	
	return 0;
}