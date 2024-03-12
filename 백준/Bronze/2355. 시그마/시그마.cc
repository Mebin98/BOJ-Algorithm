#include <iostream>

using namespace std;

int main() {
	long long a, b;
	cin >> a >> b;

	if (b == a) {
		cout << a << "\n";
		return 0;
	}

	long long ans;
	long long da = a + b;
	long long check = b - a;
	if (check < 0) {
		check = -check;
	}
	if ((check) % 2 == 0) { // 가운데 하나 따로
		long long mul = (check) / 2;
		ans = da * mul + da / 2;
	}
	else { // 좌우 대칭 맞음
		long long mul = ((check) / 2) + 1;
		ans = da * mul;
	}
	cout << ans << "\n";
	return 0;
}