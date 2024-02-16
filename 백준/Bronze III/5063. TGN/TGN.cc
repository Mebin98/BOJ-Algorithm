#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;

	int nonAd, b, c;
	for (int i = 0; i < t; i++) {
		cin >> nonAd >> b >> c;
		int ad = b - c;
		if (nonAd == ad) {
			cout << "does not matter\n";
		}
		else if (nonAd < ad) {
			cout << "advertise\n";
		}
		else {
			cout << "do not advertise\n";
		}
	}

	return 0;
}