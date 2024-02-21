#include <iostream>
#include <queue>

using namespace std;

struct Tree {
	pair<int, int> index;
	int time;
	int chance;
	Tree(int x, int y, int time, int chance) : index(x, y), time(time), chance(chance) {};
};

queue<Tree> myQueue;
bool visited[11][1000][1000] = { false };
int map[1000][1000];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m, k;

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	myQueue.push(Tree(0, 0, 1, k));
	visited[k][0][0] = true;
}

int bfs() {
	int ans = -1;
	while (!myQueue.empty()) {
		auto node = myQueue.front(); myQueue.pop();
		int x = node.index.first; int y = node.index.second;
		int time = node.time; int chance = node.chance;
		if ((x == n - 1) && (y == m - 1)) {
			ans = time;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i]; int newY = y + dy[i]; int newTime = time + 1;
			int newChance = chance - 1;
			if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m)) {
				if (!visited[chance][newX][newY] && (map[newX][newY] == 0)) {
					visited[chance][newX][newY] = true;
					myQueue.push(Tree(newX, newY, newTime, chance));
				}
				if (newChance >= 0) {
					if (!visited[newChance][newX][newY] && (map[newX][newY] == 1)) {
						visited[newChance][newX][newY] = true;
						myQueue.push(Tree(newX, newY, newTime, newChance));
					}
				}
			}
		}

	}
	return ans;
}

int main() {
	input();
	int ans = bfs();
	cout << ans << "\n";

	return 0;
}