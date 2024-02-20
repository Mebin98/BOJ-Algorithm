#include <iostream>
#include <queue>

using namespace std;

struct Tree {
	pair<int, int> index;
	int time;
	int chance;
	Tree(int x, int y, int time, int chance) :index(x, y), time(time), chance(chance) {};
};

int world[200][200];
bool visited[31][200][200] = { false };
int chance;
int w, h; // world[h][w]
int chessX[8] = {-2,-2,-1,-1,1,1,2,2};
int chessY[8] = {1,-1,2,-2,2,-2,1,-1};
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue<Tree> myQueue;

void input() {
	cin >> chance;
	cin >> w >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> world[i][j];
		} // 0-> 평지, 1-> 장애물
	}
	myQueue.push(Tree(0, 0, 0, chance));
	visited[chance][0][0] = true;
}

int bfs() {
	int ans = -1;
	while (!myQueue.empty()) {
		auto node = myQueue.front(); myQueue.pop();
		int x = node.index.first; int y = node.index.second;
		int time = node.time; int chance = node.chance;

		if ((x == h-1) && (y == w-1)) {
			ans = time;
			break;
		}

		if (chance > 0) {
			for (int i = 0; i < 8; i++) {
				int newX = x + chessX[i]; int newY = y + chessY[i];
				int newTime = time + 1; int newChance = chance - 1;
				if ((newX >= 0 && newX < h) && (newY >= 0 && newY < w)) {
					if (!visited[newChance][newX][newY] && (world[newX][newY] == 0)) {
						visited[newChance][newX][newY] = true;
						myQueue.push(Tree(newX, newY, newTime, newChance));
					}
				}
			}
		}
		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i]; int newY = y + dy[i];
			int newTime = time + 1; int newChance = chance;
			if ((newX >= 0 && newX < h) && (newY >= 0 && newY < w)) {
				if (!visited[newChance][newX][newY] && (world[newX][newY] == 0)) {
					visited[newChance][newX][newY] = true;
					myQueue.push(Tree(newX, newY, newTime, newChance));
				}
			}
		}

		if (myQueue.empty()) {
			break;
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