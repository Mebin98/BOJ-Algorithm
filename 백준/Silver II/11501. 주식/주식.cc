#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;
	vector<int> answer;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector<int> stock(n, 0);
		vector<int> compare(n, 0);
		for (int j = 0; j < n; j++) {
			int s;
			cin >> s;
			stock[j] = s;
			compare[j] = stock[j];
		}

		int max = 0;
		long long ans = 0;
		for (int k = stock.size()-1; k >= 0; k--) {
			if (stock[k] > max) {
				max = stock[k];
			}
			compare[k] = max;
		}

		for (int z = 0; z < stock.size() - 1; z++) {
			ans += compare[z] - stock[z];
		}

		stock.clear();
		compare.clear();
		cout << ans << "\n";
	}

	return 0;
}