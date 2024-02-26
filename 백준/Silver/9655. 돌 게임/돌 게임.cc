#include <iostream>

using namespace std;


int n;
void game(int res, int time) {
	if (res - 3 >= 0) {
		game(res - 3, time + 1);
	}
	else if (res - 1 >= 0) {
		game(res - 1, time + 1);
	}
	if (res == 0) {
		if (time % 2 == 0) {
			cout << "SK\n";
			return;
		}
		else {
			cout << "CY\n";
			return;
		}
	}
}

int main() {
	cin >> n;
	game(n, 1);
	return 0;
}