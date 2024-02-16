#include <iostream>
#include <cstring>

using namespace std;
int bachu[50][50];
int m, n;

void dfs(int bachu[50][50], int x, int y) {
	int dx[4] = {0,0,1,-1};
	int dy[4] = {1,-1,0,0};
	int X, Y;

	for (int i = 0; i < 4; i++) {
		X = x + dx[i];
		Y = y + dy[i];
		if (bachu[X][Y] == 1 && (X>=0 && X < n) && (Y >=0 && Y < m)){
			bachu[X][Y] = 0;
			dfs(bachu, X, Y);
		}
	}
}

int main() {
	int t;
	int k;
	int i,j, ni, mi;
	int x, y;
	int group;

	cin >> t;
	for (i = 0; i < t; i++) {
		cin >> m >> n >> k;
		memset(bachu, 0, sizeof(bachu));
		group = 0;
		for (j = 0; j < k; j++) {
			cin >> x >> y;
			bachu[y][x] = 1;
		}

		for (ni = 0; ni < n; ni++) {
			for (mi = 0; mi < m; mi++) {
				if (bachu[ni][mi] == 1) {
					bachu[ni][mi] = 0;
					dfs(bachu, ni, mi);
					group++;
				}
			}
		}
		cout << group << "\n";
	}
	return 0;
}