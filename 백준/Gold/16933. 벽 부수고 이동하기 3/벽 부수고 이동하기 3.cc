#include <iostream>
#include <queue>

using namespace std;

struct Tree {
	pair<int, int> index;
	int time;
	int chance;
	bool morning;
	Tree(int x, int y, int time, int chance, bool morning) :
		index(x, y), time(time), chance(chance), morning(morning) {};
};

queue<Tree> myQueue;
bool visited[2][11][1000][1000] = { false }; // [morning][chance][x][y]
int map[1000][1000];
int dx[5] = {0,0,1,-1,0}; int dy[5] = { 1,-1,0,0,0};
int n, m, k;

void input() {
	cin >> n >> m >> k;
	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int j = 0; j < m; j++) {
			map[i][j] = input[j] - '0';
		}
	}
	myQueue.push(Tree(0,0,1,k,true));
	visited[0][k][0][0] = true;
}

int bfs() {
	int ans = -1;
	while (!myQueue.empty()) {
		auto node = myQueue.front(); myQueue.pop();
		int x = node.index.first; int y = node.index.second; int time = node.time;
		int chance = node.chance; bool morning = node.morning;
		
		if ((x == n - 1) && (y == m - 1)) {
			ans = time;
			break;
		}

		// 벽은 낮에만 부술수 있음
		int newTime = time + 1;
		if (morning) {
			for (int i = 0; i < 5; i++) {
				int newX = x + dx[i]; int newY = y + dy[i]; int newChance = chance - 1;
				if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m)) {
					if (!visited[1][chance][newX][newY] && (map[newX][newY] == 0)) {
						visited[1][chance][newX][newY] = true;
						myQueue.push(Tree(newX, newY, newTime, chance, false));
					}
					if (newChance >= 0) {
						if (!visited[1][newChance][newX][newY] && (map[newX][newY] == 1)) {
							visited[1][newChance][newX][newY] = true;
							myQueue.push(Tree(newX, newY, newTime, newChance, false));
						}
					}
				}
			}
		}
		else { // 이때는 벽을 부술순 없음
			for (int i = 0; i < 5; i++) {
				int newX = x + dx[i]; int newY = y + dy[i];
				if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m)) {
					if (!visited[0][chance][newX][newY] && (map[newX][newY] == 0)) {
						visited[0][chance][newX][newY] = true;
						myQueue.push(Tree(newX, newY, newTime, chance, true));
					} // -> map값이 1일때 기다리는 경우를 고려해야 함 
					if (!visited[0][chance][newX][newY] && (map[newX][newY] == 1) &&
						(i == 4)) {
						visited[0][chance][newX][newY] = true;
						myQueue.push(Tree(newX, newY, newTime, chance, true));
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