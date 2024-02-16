#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	int a = 100, b = 100;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (x > y) {
			b -= x;
		}
		else if (y > x) {
			a -= y;
		}
	}

	cout << a << "\n";
	cout << b;

	return 0;
}