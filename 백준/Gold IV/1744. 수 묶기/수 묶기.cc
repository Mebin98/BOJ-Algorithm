#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> pos;
	vector<int> neg;
	bool zero = false;
	bool pos_exist = false;
	bool neg_exist = false;
	int num;

	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num == 0) zero = true;
		else if (num > 0) {
			pos.push_back(num);
			pos_exist = true;
		}
		else if (num < 0) {
			neg.push_back(num);
			neg_exist = true;
		}
	}

	sort(pos.begin(), pos.end(), [](int x, int y) {
		return x > y;
	});

	sort(neg.begin(), neg.end(), [](int x, int y) {
		return x < y;
	});

	int ans = 0;
	int pi = 0;
	while (pos_exist) {
		if (pi == pos.size() - 1) {
			ans += pos[pi];
			pos_exist = false;
			break;
		}
		else if(pi >= pos.size()) {
			pos_exist = false;
			break;
		}

		int mul = pos[pi] * pos[pi + 1];
		if (mul > pos[pi]) {
			ans += mul;
			pi += 2;
			continue;
		}
		ans += pos[pi];
		pi += 1;
		continue;
	}

	int ni = 0;
	while (neg_exist) {
		if (ni == neg.size() - 1) {
			if (!zero) {
				ans += neg[ni];
			}
			neg_exist = false;
			break;
		}
		else if (ni >= neg.size()) {
			neg_exist = false;
			break;
		}
		int mul = neg[ni] * neg[ni + 1];
		ans += mul;
		ni += 2;
	}
		
	cout << ans << "\n";

	return 0;
}