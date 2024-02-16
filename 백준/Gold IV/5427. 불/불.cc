#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tree {
	pair<int, int> index;
	int time;

	Tree(int x, int y, int time) : index(x, y), time(time) {};
};

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int building[1005][1005];
bool visited[1005][1005];
queue<Tree>myQueue; // 테스트 케이스마타 큐 비워줘야 함

void init(int w, int h) {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			building[i][j] = -1;
			visited[i][j] = false;
		}
	}

	while (!myQueue.empty()) { // 큐 비워주기 
		myQueue.pop();
	}
}

int main() {
	int test;
	cin >> test;

	int w, h;
	bool sanguen = false;
	for (int i = 0; i < test; i++) {
		cin >> w >> h; // building[h][w]
		string input;
		pair<int, int> start;

		init(w, h);
	
		// -7 -> 불이 안난곳,
		bool fireExist = false;
		for (int j = 0; j < h; j++) {
			cin >> input;
			for (int k = 0; k < input.size(); k++) {
				if (input[k] == '.') {
					building[j][k] = -7;
				}
				else if (input[k] == '@') {
					building[j][k] = -7;
					start.first = j; start.second = k;
					sanguen = true;
				}
				else if (input[k] == '*') {
					building[j][k] = 0;
					myQueue.push(Tree(j, k, 0));
					fireExist = true;
				}
			}
		}

		if (fireExist) {
			while (!myQueue.empty()) {
				auto node = myQueue.front();
				myQueue.pop();

				int x = node.index.first; int y = node.index.second;
				int time = node.time;

				for (int a = 0; a < 4; a++) {
					int newX = x + dx[a]; int newY = y + dy[a];
					int newTime = time + 1;

					if ((newX >= 0 && newX < h) && (newY >= 0 && newY < w)) {
						if (building[newX][newY] == -7) {
							building[newX][newY] = newTime;
							myQueue.push(Tree(newX, newY, newTime));
						}
					}
				}
			}

			while (!myQueue.empty()) { // 큐 비워주기 
				myQueue.pop();
			}

		}



		myQueue.push(Tree(start.first, start.second, 0));
		visited[start.first][start.second] = true;

		if (fireExist) {
			bool possible = false;
			while (!possible) {
				auto node = myQueue.front();
				myQueue.pop();
				int x = node.index.first; int y = node.index.second;
				int time = node.time;

				for (int b = 0; b < 4; b++) {
					int newX = x + dx[b]; int newY = y + dy[b];
					int newTime = time + 1;

					if ((newX >= 0 && newX < h) && (newY >= 0 && newY < w)) {
						if ((time + 1 < building[newX][newY] && !visited[newX][newY]) 
							|| (building[newX][newY] == -7 && !visited[newX][newY])) {
							visited[newX][newY] = true;
							myQueue.push(Tree(newX, newY, newTime));
						}
					}
					else {
						cout << newTime << "\n";
						possible = true;
						break;
					}
				}
				if (myQueue.empty()) {
					break;
				}
			}
			if (!possible) {
				cout << "IMPOSSIBLE\n";
			}
		}

		if (!fireExist) {
			bool ansNoneFire = true;
			int ans = 0;
			while (ansNoneFire) {
				auto node = myQueue.front();
				myQueue.pop();
				int x = node.index.first; int y = node.index.second;
				int time = node.time;

				for (int c = 0; c < 4; c++) {
					int newX = x + dx[c]; int newY = y + dy[c]; int newTime = time + 1;
					if ((newX >= 0 && newX < h) && (newY >= 0 && newY < w)) {
						if (!visited[newX][newY] && building[newX][newY] == -7) {
							visited[newX][newY] = true;
							myQueue.push(Tree(newX, newY, newTime));
						}
					}
					else {
						ans = newTime;
						ansNoneFire = false;
						break;
					}
				}

				// cout << "Debug\n";
				if (myQueue.empty()) {
					break;
				}
			}
			if (!ansNoneFire) {
				cout << ans << "\n";
			}
			else {
				cout << "IMPOSSIBLE\n";
			}
		}
	}
	return 0;
}