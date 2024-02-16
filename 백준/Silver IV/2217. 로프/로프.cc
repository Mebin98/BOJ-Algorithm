#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> lope;
	int element;
	for (int i = 0; i < n; i++) {
		cin >> element;
		lope.push_back(element);
	}

	sort(lope.begin(), lope.end(), [](int x, int y) {
		return x > y;
		});

	int max_value = lope[0];
	for (int i = 1; i < lope.size(); i++) {
		if (lope[i] * (i + 1) > max_value) {
			max_value = lope[i] * (i + 1);
		}
	}

	cout << max_value << "\n";

	return 0;
}