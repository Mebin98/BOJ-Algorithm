#include <iostream>

using namespace std;

int n, k; // n -> 국가의 수, 등수를 알고 싶은 국가
int country[1001][3];

void input() {
	cin >> n >> k;
	int id, gold, silver, bronze;
	for (int i = 0; i < n; i++) {
		cin >> id >> gold >> silver >> bronze;
		country[id][0] = gold;
		country[id][1] = silver;
		country[id][2] = bronze;
	}
}

int computeRank(int id) {
	int rank = 1;
	for (int i = 1; i <= n; i++) {
		if (i == id) continue;
		if (country[id][0] > country[i][0]) continue;
		else if (country[id][0] < country[i][0]) {
			rank++;
		}
		else {
			if (country[id][1] > country[i][1]) continue;
			else if (country[id][1] < country[i][1]) {
				rank++;
			}
			else {
				if (country[id][2] > country[i][2]) continue;
				else if (country[id][2] < country[i][2]) {
					rank++;
				}
				else { // same case
					continue;
				}
			}
		}
	}
	return rank;
}

int main() {
	input();
	int ans = computeRank(k);
	cout << ans << "\n";
	return 0;
}