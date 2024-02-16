#include <iostream>

using namespace std;

int main() {
	long long m, n;
	cin >> n >> m;

	long long ans = m - n;
	if (ans < 0) {
		cout << -ans << "\n";
	}
	else {
		cout << ans << "\n";
	}
}