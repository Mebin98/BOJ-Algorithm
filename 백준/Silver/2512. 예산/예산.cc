#include <iostream>
#include <algorithm>

using namespace std;

struct Budget {
	int num;
	long long list[100000];
	long long total;
	long long min;
	long long max;
};
Budget budget;

void input() {
	cin >> budget.num;
	for (int i = 0; i < budget.num; i++) {
		cin >> budget.list[i];
	}
	cin >> budget.total;
	budget.min = 0;
}

void findMax() {
	budget.max = budget.list[0];
	for (int i = 1; i < budget.num; i++) {
		if (budget.list[i] > budget.max) {
			budget.max = budget.list[i];
		}
	}
}

long long search() {
	long long mid;
	long long ans = 0;
	while (budget.min <= budget.max) {
		mid = (budget.min + budget.max) / 2;
		long long allocate = 0;

		for (int i = 0; i < budget.num; i++) {
			allocate += min(mid, budget.list[i]);
		}

		if (allocate > budget.total) { // 범위가 하향
			budget.max = mid - 1;
		}
		else { // 범위가 상승
			ans = mid;
			budget.min = mid + 1;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	input();
	findMax();
	long long ans = search();
	cout << ans << "\n";
	return 0;
}