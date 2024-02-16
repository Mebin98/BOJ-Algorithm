#include <iostream>

using namespace std;

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		cout << 1 << "\n";
		return 0;
	}
	
	int temp = 1;
	int end;
	int start = 1;
	int ans = 1;
	while (1) {
		ans++;
		end = start + 6 * temp;
		if (n > start && n <= end) {
			break;
		}
		temp += 1;
		start = end;
	}

	cout << ans << "\n";
	return 0;
}