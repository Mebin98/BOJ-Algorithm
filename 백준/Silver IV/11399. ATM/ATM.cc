#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int>atm;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		atm.push_back(temp);
	}

	sort(atm.begin(), atm.end(), [](int x, int y) {
		return x < y;
	});

	int sum = 0;
	for (int i = 0; i < atm.size(); i++) {
		sum += atm[i] * (atm.size() - i);
	}

	cout << sum << "\n";

	return 0;
}