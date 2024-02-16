#include <iostream>
#include <map>
#include <vector>

using namespace std;
vector<string> hell;
map<string, int> hashTable;
int n, m, k;

void dfs(int x, int y, int depth, string s) {
	int dx[8] = { 0,0,-1,1,1,1,-1,-1 };
	int dy[8] = { 1,-1,0,0,1,-1,1,-1 };
	int X, Y;
	int new_depth = depth + 1;
	hashTable[s] += 1;

	if (s.size() == 5) {
		return;
	}

	for (int i = 0; i < 8; i++) {
		X = (x + dx[i] + n) % n;
		Y = (y + dy[i] + m) % m;

		string new_string = s + hell[X][Y];
		dfs(X, Y, new_depth, new_string);
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		string s1;
		cin >> s1;
		hell.push_back(s1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			string depart = "";
			dfs(i, j, 0, depart + hell[i][j]);
		}
	}

	for (int i = 0; i < k; i++) {
		string ans;
		cin >> ans;
		cout << hashTable[ans] << "\n";
	}

	return 0;
}