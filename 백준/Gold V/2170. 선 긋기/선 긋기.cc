#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> line;
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		line.push_back({ x,y });
	}

	// 첫번째 요소를 기준으로 오름차순 정렬
	sort(line.begin(), line.end());

	int head = line[0].first;
	int tail = line[0].second;
	int ans = 0;
	for (int i = 1; i < line.size(); i++) {
		int first = line[i].first;
		int second = line[i].second;

		if (first <= tail) {
			if (second > tail) {
				tail = second;
			}
		}
		else {
			ans += tail - head;
			head = line[i].first;
			tail = line[i].second;
		}
	}
	ans += tail - head;
	
	cout << ans << "\n";

	return 0;
}