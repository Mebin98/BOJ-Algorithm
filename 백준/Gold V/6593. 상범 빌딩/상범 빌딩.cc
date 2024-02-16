#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Tree {
	int l; int r; int c;
	int time;
	Tree(int l, int r, int c, int time) : l(l),r(r),c(c),time(time) {};
};

int l, r, c;
int building[30][30][30];
int startL=-1, startR=-1, startC=-1;
int endL=-1, endR=-1, endC=-1;
queue<Tree>myQueue;
int dl[6] = {1,-1,0,0,0,0};
int dr[6] = {0,0,1,-1,0,0};
int dc[6] = {0,0,0,0,1,-1};
bool visited[30][30][30];
vector<int> ans;

void input(int l, int r, int c) {

	string cInput;
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < r; j++) {
			cin >> cInput;
			for (int k = 0; k < cInput.size(); k++) {
				if (cInput[k] == '.') {
					building[i][j][k] = 0;
					visited[i][j][k] = false;
				}
				else if (cInput[k] == 'S') {
					building[i][j][k] = 0;
					startL = i; startR = j; startC = k;
					myQueue.push(Tree(startL, startR, startC, 0));
					visited[startL][startR][startC] = true;
				}
				else if (cInput[k] == 'E') {
					building[i][j][k] = 0;
					endL = i; endR = j; endC = k;
					visited[i][j][k] = false;
				}
				else {
					building[i][j][k] = -1;
					visited[i][j][k] = false;
				}
			}
		}
		// cout << "\n";
	}
}

int main() {
	while (cin >> l >> r >> c) {
		if (l == 0 && r == 0 && c == 0) {
			break;
		}
		input(l, r, c);
		if (((startL == -1) && (startR == -1) && (startC == -1)) || ((endL == -1) && (endR == -1) && (endC == -1))) {
			ans.push_back(-1);
			//cout << "Trapped!\n";
			while (!myQueue.empty()) {
				myQueue.pop();
			}
			continue;
		}

		while (true) {
			auto node = myQueue.front();
			myQueue.pop();
			int L = node.l; int R = node.r; int C = node.c;
			int time = node.time;
			if ((L == endL) && (R == endR) && (C == endC)) {
				ans.push_back(time);
				//cout << "Escaped in " << time << " minute(s). \n";
				break;
			}
			for (int i = 0; i < 6; i++) {
				int newL = L + dl[i]; int newR = R + dr[i]; int newC = C + dc[i];
				int newTime = time + 1;
				if ((newL >= 0 && newL < l) && (newR >= 0 && newR < r) && (newC >= 0 && newC < c)) {
					if (!visited[newL][newR][newC] && (building[newL][newR][newC] == 0)) {
						visited[newL][newR][newC] = true;
						myQueue.push(Tree(newL, newR, newC, newTime));
					}
				}
			}
			if (myQueue.empty()) {
				ans.push_back(-1);
				//cout << "Trapped!\n";
				break;
			}
		}

		while (!myQueue.empty()) {
			myQueue.pop();
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		if (ans[i] == -1) {
			cout << "Trapped!\n";
		}
		else {
			cout << "Escaped in " << ans[i] << " minute(s).\n";
		}
	}

	return 0;
}