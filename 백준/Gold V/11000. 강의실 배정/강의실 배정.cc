#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
vector<pair<int, int>> lec;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	int n;
	cin >> n;

	int s, t;
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		lec.push_back({ s,t });
	}

	sort(lec.begin(), lec.end());
	pq.push(lec[0].second);
	int room = 0;

	for (int i = 1; i < lec.size(); i++) {
		int endTime = pq.top();
		if (lec[i].first >= endTime) { // 겹치지 x -> 강의실 계속
			pq.pop();
			pq.push(lec[i].second);
		}
		else { // 겹침, -> 강의실 새로 파야함
			pq.push(lec[i].second);
		}
	}

	cout << pq.size() << "\n";


	return 0;
}