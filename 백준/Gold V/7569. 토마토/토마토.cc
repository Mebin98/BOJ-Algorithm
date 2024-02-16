#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//int tomato[h][n][m]

int tomato[105][105][105];
int m, n, h;
int dx[6] = {0,0,0,0,1,-1};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {1,-1,0,0,0,0};

struct Tree {
	int x; int y; int z;
	int time;
	
	Tree(int x, int y, int z, int time) : x(x), y(y), z(z), time(time) {};
};

int main() {
	cin >> m >> n >> h;

	bool exist = false;
	queue<Tree> myQueue;
	int completed = 0;
	int uncompleted = 0;
	int none = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1){
					exist = true;
					completed += 1;
					myQueue.push(Tree(k, j, i, 0));
				}
				else if(tomato[i][j][k] == 0){
					uncompleted += 1;
				}
				else {
					none += 1;
				}
			}
		}
	}

	int goal = n * m * h - none;
	
	if (!exist) {
		cout << -1 << "\n";
		return 0;
	}

	if (completed == goal) {
		cout << 0 << "\n";
		return 0;
	}

	int time = 0;

	while (true) {
		auto node = myQueue.front();
		myQueue.pop();
		int x = node.x; int y = node.y; int z = node.z;
		time = node.time;

		for (int i = 0; i < 6; i++) {
			int newX = x + dx[i]; int newY = y + dy[i]; int newZ = z + dz[i];
			int newTime = time + 1;
			if ((newX >= 0 && newX < m) && (newY >= 0 && newY < n) && (newZ >= 0 && newZ < h)) {
				if (tomato[newZ][newY][newX] == 0) {
					tomato[newZ][newY][newX] = 1;
					completed += 1;
					uncompleted -= 1;
					myQueue.push(Tree(newX, newY, newZ, newTime));
				}
			}
		}

		if (myQueue.empty()) {
			break;
		}
	}

	if (uncompleted == 0) {
		cout << time << '\n';
	}
	else {
		cout << -1 << '\n';
	}
	return 0;
}