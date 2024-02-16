#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	int temp;
	vector<int> value;
	
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		value.push_back(temp);
	}
	
	int amount = k;
	int ans = 0;

	for (int i = value.size() - 1; i >= 0; i--) {
		if (value[i] <= amount) {
			int quo = amount / value[i];
			ans += quo;
			amount = amount - quo * value[i];
		}

		if (amount == 0) break;
	}

	cout << ans << "\n";

	return 0;
}