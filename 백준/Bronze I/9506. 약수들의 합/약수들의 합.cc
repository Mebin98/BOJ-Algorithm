#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;

	while (cin >> n) {
		if (n == -1) break;

		int sum = 0;
		vector<int> factor;
		for (int i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
				factor.push_back(i);
			}
		}

		if (sum == n) {
			cout << n << " = ";
			for (int i = 0; i < factor.size(); i++) {
				cout << factor[i];
				if (i == factor.size() - 1) break;
				cout << " + ";
			}
			cout << "\n";
		}
		else {
			cout << n;
			cout << " is NOT perfect.\n";
		}
		factor.clear();
	}

	return 0;
}