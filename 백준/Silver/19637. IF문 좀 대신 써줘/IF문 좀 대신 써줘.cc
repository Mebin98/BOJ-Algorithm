#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<pair<string, long long>>game;
string state; long long quant;
vector <long long> player;

string binarySearch(long long playerValue) {
	long long start = 0; long long end = game.size() - 1;
	while (true) {
		long long mid = (start + end) / 2;
		if (playerValue <= game[mid].second) {
			end = mid;
		}
		else {
			start = mid + 1;
		}
		if (start == end) {
			return game[start].first;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> state >> quant;
		game.push_back({ state, quant});
	}

	long long input;
	for (int i = 0; i < m; i++) {
		cin >> input;
		player.push_back(input);
	}

	for (int i = 0; i < m; i++) {
		string ans = binarySearch(player[i]);
		cout << ans << "\n";
	}

	return 0;
}