#include <iostream>
#include <queue>

using namespace std;
int dx[8] = {-1,1,-2,2,-2,2,-1,1};
int dy[8] = {2,2,1,1,-1,-1,-2,-2};

struct Tree {
	pair<int, int> index;
	int time;

	Tree(int x, int y, int time) : index(x, y), time(time) {};
};

queue<Tree>myQueue;

int main() {
	int t;
	cin >> t;
	pair<int, int> before;
	pair<int, int> after;

	for (int i = 0; i < t; i++) {
		bool visited[305][305] = { false };
		int block; cin >> block;
		cin >> before.first >> before.second;
		cin >> after.first >> after.second;
		int ans = 0;

		myQueue.push(Tree(before.first, before.second, 0));
		visited[before.first][before.second] = true;

		while (true) {
			auto node = myQueue.front();
			myQueue.pop();

			int x = node.index.first; int y = node.index.second;
			int time = node.time;

			if (x == after.first && y == after.second) {
				ans = time;
				break;
			}

			for (int i = 0; i < 8; i++) {
				int newX = x + dx[i]; int newY = y + dy[i];
				int newTime = time + 1;

				if ((newX >= 0 && newX < block) && (newY >= 0 && newY < block)) {
					if (!visited[newX][newY]) {
						myQueue.push(Tree(newX, newY, newTime));
						visited[newX][newY] = true;
					}
				}
			}
		}
		cout << ans << "\n";

		while (!myQueue.empty()) {
			myQueue.pop();
		}
	}
	return 0;
}