#include <iostream>

using namespace std;

int main() {
	int X[1001] = { 0 };
	int Y[1001] = { 0 };
	int x, y;
	for(int i = 0; i < 3; i++){
		cin >> x >> y;
		X[x] += 1;
		Y[y] += 1;
	}

	int ansX, ansY;
	for (int i = 0; i < 1000; i++) {
		if (X[i] == 1) {
			ansX = i;
		}
		if (Y[i] == 1) {
			ansY = i;
		}
	}

	cout << ansX << " " << ansY;

	return 0;
}