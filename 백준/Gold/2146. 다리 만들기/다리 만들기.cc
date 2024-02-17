#include <iostream>
#include <queue>

using namespace std;

struct Tree {
	pair<int, int> index;
	int block;
	Tree(int x, int y, int block) : index(x, y), block(block) {};
};

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int world[100][100];
bool visited[100][100];
int number;
int area;
int ans = 10000;
int checkArea = -1;
queue<Tree> myQueue;

void input() {
	cin >> number;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cin >> world[i][j];
			visited[i][j] = false;
		}
	}
}

void dfsFirst(int x, int y, int area) { // 섬마다 번호를 붙여주기 위한 dfs
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i]; int newY = y + dy[i];
		if ((newX >= 0 && newX < number) && (newY >= 0 && newY < number)) {
			if (!visited[newX][newY] && (world[newX][newY] != 0)) {
				visited[newX][newY] = true;
				world[newX][newY] = area;
				dfsFirst(newX, newY, area);
			}
		}
	}
}

void init() {
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			visited[i][j] = false;
		}
	}

	if (!myQueue.empty()) {
		while (!myQueue.empty()) {
			myQueue.pop();
		}
	}
}

bool checkNearIsland(int x, int y) {
	bool check = false;
	for (int i = 0; i < 4; i++) {
		int newX = x + dx[i]; int newY = y + dy[i];
		if ((newX >= 0 && newX < number) && (newY >= 0 && newY < number)) {
			if (world[newX][newY] != 0) {
				check = true;
				checkArea = world[newX][newY];
			}
		}
	}
	return check;
}

int bfsSecond(int area) {
	while (true) {
		auto node = myQueue.front(); myQueue.pop();
		int x = node.index.first; int y = node.index.second; 
		int block = node.block; int crtArea = area;
		//cout << x << ", " << y << " [" << block << "]\n";

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i]; int newY = y + dy[i]; 
			int newBlock = block + 1;
			if ((newX >= 0 && newX < number) && (newY >= 0 && newY < number)) {
				if (!visited[newX][newY] && (world[newX][newY] == 0)) {
					visited[newX][newY] = true;
					myQueue.push(Tree(newX, newY, newBlock));
				}
				else if (!visited[newX][newY] && (world[newX][newY] != 0) 
					&& (world[newX][newY] != crtArea)) {
					return block;
				}
			}
		}

		if (myQueue.empty()) {
			break;
		}
	}
	return 10000;
}

void checkLake(int x, int y) {
	int newX = x + dx[0]; int newY = y + dy[0];
	int same = -1;
	if ((newX >= 0 && newX < number) && (newY >= 0 && newY < number)) {
		if (world[newX][newY] == 0) {
			return;
		}
		else {
			same = world[newX][newY];
		}
	}


	for (int i = 1; i < 4; i++) {
		int newX = x + dx[i]; int newY = y + dy[i];
		if ((newX >= 0 && newX < number) && (newY >= 0 && newY < number)) {
			if (world[newX][newY] != same) {
				return;
			}
		}
	}
	
	world[x][y] = same;
	return;
}

int main() {
	input();
	area = 1;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (!visited[i][j] && (world[i][j] != 0)) {
				visited[i][j] = true;
				world[i][j] = area;
				dfsFirst(i, j, area);
				area++;
			}
		}
	}

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (world[i][j] == 0) {
				checkLake(i, j);
			}
		}
	}


	/*
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << world[i][j];
		}
		cout << "\n";
	}
	*/

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			if (world[i][j] == 0) {
				if (checkNearIsland(i, j)) {
					init();
					visited[i][j] = true;
					myQueue.push(Tree(i, j, 1));
					int temp = bfsSecond(checkArea);
					if (temp < ans) {
						ans = temp;
					}
				}
			}
			
		}
	}

	cout << ans << "\n";

	return 0;
}