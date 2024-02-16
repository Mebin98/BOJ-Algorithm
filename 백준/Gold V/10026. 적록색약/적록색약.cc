#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<string>rg;
char real_rg[100][100];
int n;


void dfs(int x, int y, char color) {
	int dx[] = {0,0,1,-1};
	int dy[] = {1,-1,0,0};

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if ((X >= 0 && X < n) && (Y >= 0) && (Y < n)) {
			if (rg[X][Y] != '0' && rg[X][Y] == color) {
				char new_color = rg[X][Y];
				rg[X][Y] = '0';
				dfs(X, Y, new_color);
			}
		}
	}

}

void rg_dfs(int x, int y, char color) {
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };

	for (int i = 0; i < 4; i++) {
		int X = x + dx[i];
		int Y = y + dy[i];
		if ((X >= 0 && X < n) && (Y >= 0) && (Y < n)) {
			if (real_rg[X][Y] != '0' && real_rg[X][Y] == color) {
				char new_color = real_rg[X][Y];
				real_rg[X][Y] = '0';
				rg_dfs(X, Y, new_color);
			}
		}
	}

}

int main() {
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		rg.push_back(input);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			real_rg[i][j] = rg[i][j];
			if (real_rg[i][j] == 'R') {
				real_rg[i][j] = 'G';
			}
		}
	}

	char color;
	char rg_color;
	int ans = 0;
	int rg_ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			color = rg[i][j];
			rg_color = real_rg[i][j];
			if (rg[i][j] != '0') {
				rg[i][j] = '0';
				dfs(i, j, color);
				ans += 1;
			}
			if (real_rg[i][j] != '0') {
				real_rg[i][j] = '0';
				rg_dfs(i, j, rg_color);
				rg_ans += 1;
			}
		}
	}

	cout << ans << " " << rg_ans <<  "\n";

	return 0;
}