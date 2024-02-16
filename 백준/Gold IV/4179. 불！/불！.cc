#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int maze[1005][1005];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int row, column;
vector<pair<int, int>> fire;

struct MazeTree {
	pair<int,int> index;
	int time;

	MazeTree(int x, int y, int time) : index(x, y), time(time) {}
};

int main() {
	
	cin >> row >> column;
	int firstX = 0, firstY = 0;

	// -7 -> Unvisited
	queue<MazeTree> myQueue;
	bool Fexist = false;

	for (int i = 0; i < row; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < column; j++) {
			if (input[j] == '#') {
				maze[i][j] = -1;
			}
			else if (input[j] == 'F') {
				myQueue.push(MazeTree(i, j, 0));
				maze[i][j] = 0;
				Fexist = true;
			}
			else if (input[j] == 'J') {
				maze[i][j] = -7;
				firstX = i; firstY = j;
			}
			else {
				maze[i][j] = -7;
			}
		}
	}

	if (!Fexist) {
		myQueue.push(MazeTree(firstX, firstY, 0));

		while (!myQueue.empty()) {
			auto node = myQueue.front();
			int x = node.index.first; int y = node.index.second;
			int time = node.time;

			for (int i = 0; i < 4; i++) {
				int newX = x + dx[i]; int newY = y + dy[i];
				int newTime = time + 1;

				if ((newX >= 0 && newX < row) && (newY >= 0 && newY < column)) {
					if (maze[newX][newY] == -7) {
						maze[newX][newY] = -1;
						myQueue.push(MazeTree(newX, newY, newTime));
					}
				}
				else {
					cout << newTime << "\n";
					return 0;
				}
			}
			myQueue.pop();
		}

		cout << "IMPOSSIBLE" << "\n";
		return 0;
	}

	// 테이블 채우기
	while (!myQueue.empty()) {
		auto node = myQueue.front();
		int x = node.index.first; int y = node.index.second;
		int time = node.time;

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i]; int newY = y + dy[i]; int newTime = time + 1;
			if ((newX >= 0 && newX < row) && (newY >= 0 && newY < column)) {
				if (maze[newX][newY] == -7) {
					maze[newX][newY] = newTime;
					myQueue.push(MazeTree(newX, newY, newTime));
				}
			}
		}

		myQueue.pop();
	}

	if (Fexist) {
		myQueue.push(MazeTree(firstX, firstY, 0));
		maze[firstX][firstY] = -1;
	}

	while (!myQueue.empty()) {
		auto node = myQueue.front();
		int x = node.index.first; int y = node.index.second;
		int time = node.time;

		for (int i = 0; i < 4; i++) {
			int newX = x + dx[i]; int newY = y + dy[i]; int newTime = time + 1;
			if ((newX >= 0 && newX < row) && (newY >= 0 && newY < column)) {
				if (maze[newX][newY] > newTime) {
					maze[newX][newY] = -1;
					myQueue.push(MazeTree(newX, newY, newTime));
				}
			}
			else {
				cout << newTime << "\n";
				return 0;
			}
		}

		myQueue.pop();
	}

	cout << "IMPOSSIBLE" << "\n";
	
	return 0;
}