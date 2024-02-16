#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	int y = 0, k = 0;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int yonsei = 0, korea = 0;
		for (int j = 0; j < 9; j++) {
			cin >> y >> k;
			yonsei += y;
			korea += k;
		}

		if (yonsei > korea) {
			cout << "Yonsei\n";
		}
		else if (korea > yonsei) {
			cout << "Korea\n";
		}
		else {
			cout << "Draw\n";
		}
	}

	return 0;
}