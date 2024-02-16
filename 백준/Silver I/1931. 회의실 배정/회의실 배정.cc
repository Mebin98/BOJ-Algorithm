#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<pair<int, int>>conf;
	int start, end;

	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		conf.push_back({ start,end });
	}

	sort(conf.begin(), conf.end(), [](const pair<int, int>&a,
		const pair<int, int>& b) 
		{
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second < b.second; 
		});

	int ans = 1;
	int crt = conf[0].second;

	for (size_t i = 1; i < conf.size(); i++) {
		if (crt <= conf[i].first) {
			crt = conf[i].second;
			ans += 1;
		}
	}

	cout << ans << "\n";

	return 0;
}