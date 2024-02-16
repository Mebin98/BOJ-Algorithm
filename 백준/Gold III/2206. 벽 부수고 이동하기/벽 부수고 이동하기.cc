#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Tree {
	pair<int, int> index;
	int time;
	int chance;

	Tree(int x, int y, int time, int chance) : index(x, y), time(time), chance(chance) {};
};

int n, m;
int wall[1000][1000];
bool visited[1000][1000][2]; // [x][y][0] -> chance 쓴 상태
int dx[4] = { 1,-1,0,0 };    // [x][y][1] -> chance 안쓴 상태
int dy[4] = { 0,0,1,-1 };
queue<Tree> myQueue;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			wall[i][j] = input[j] - '0';
			visited[i][j][0] = false; visited[i][j][1] = false;
		}
	}
	myQueue.push(Tree(0,0,1,1));
	visited[0][0][1] = true; // (0,0) 시작은 chance를 안 쓴 상태
}

int bfs() {
	while (true) {
		auto node = myQueue.front();
		myQueue.pop();
		int x = node.index.first; int y = node.index.second;
		int time = node.time; int chance = node.chance;

		if ((x == n - 1) && (y == m - 1)) {
			return time;
		}

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i]; int newY = y + dy[i]; int newTime = time + 1;
			if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m)) {
				if (!visited[newX][newY][chance] && (wall[newX][newY] == 0)) {
					visited[newX][newY][chance] = true;
					myQueue.push(Tree(newX, newY, newTime, chance));
				}
				else if (!visited[newX][newY][chance] && (wall[newX][newY] == 1) && (chance == 1)) {
					visited[newX][newY][chance] = true;
					myQueue.push(Tree(newX, newY, newTime, 0));
				}
			}
		}
		
		if (myQueue.empty()) {
			return -1;
			break;
		}
	}
}

int main() {
	input();
	if ((n == 1) && (m == 1)) {
		cout << 1 << "\n";
		return 0;
	}
	int ans = bfs();
	cout << ans << "\n";
	return 0;
}