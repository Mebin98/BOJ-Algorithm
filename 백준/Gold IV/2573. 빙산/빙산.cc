#include <iostream>

using namespace std;

int ice[300][300];
int bucket[300][300];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
bool visited[300][300];
int n, m; // ice[n][m]
int year = 0;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ice[i][j];
			visited[i][j] = false;
		}
	}
}

void melt() {
	//ice 배열 -> update, bucket 배열 -> 형태 유지
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bucket[i][j] = ice[i][j];
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (bucket[i][j] != 0) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int x = i + dx[k]; int y = j + dy[k];
					if ((x >= 0 && x < n) && (y >= 0 && y < m)) {
						if (bucket[x][y] == 0) {
							cnt += 1;
						}
					}
				}
				ice[i][j] = bucket[i][j] - cnt;
				if (ice[i][j] < 0) {
					ice[i][j] = 0;
				}
			}
			else {
				ice[i][j] = bucket[i][j];
			}
		}
	}
	year += 1;
}

void dfs(int x, int y) { // ice[x][y]
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i]; int newY = y + dy[i];
		if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m)) {
			if ((ice[newX][newY] != 0) && (!visited[newX][newY])) {
				visited[newX][newY] = true;
				dfs(newX, newY);
			}
		}
	}
	return;
}

int main() {
	input();
	while (true) {
		int bundle = 0;
		int checkSum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if ((ice[i][j] != 0) && (!visited[i][j])) {
					visited[i][j] = true;
					dfs(i, j);
					bundle += 1;
					checkSum += ice[i][j];
				}
			}
		}

		if (bundle >= 2) {
			cout << year << "\n";
			return 0;
		}
		if (checkSum == 0) {
			cout << 0 << "\n";
			return 0;
		}
		
		melt();
	}

	return 0;
}