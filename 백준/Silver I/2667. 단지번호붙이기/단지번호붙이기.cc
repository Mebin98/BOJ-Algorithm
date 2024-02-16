#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
string table[10000];
int n;

int dfs(int x, int y, int sum) {
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	int X, Y;

	for (int i = 0; i < 4; i++) {
		X = x + dx[i];
		Y = y + dy[i];
		if ((X >= 0 && X < n) && (Y >= 0 && Y < n)) {
			if (table[X][Y] == '1') {
				sum += 1;
				table[X][Y] = '0';
				sum = dfs(X, Y, sum);
			}
		}
	}
	return sum;
}

int main() {
	int i,j;
	int sum;
	int complex = 0;
	vector<int> answer;
	cin >> n;

	for (i = 0; i < n; i++) {
		cin >> table[i];
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			sum = 0;
			if (table[i][j] == '1') {
				sum += 1;
				table[i][j] = '0';
				sum = dfs(i, j, sum);
				answer.push_back(sum);
				complex += 1;
			}
		}
	}

	cout << complex << "\n";
	sort(answer.begin(), answer.end());
	for (i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}

	return 0;
}