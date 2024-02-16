#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int dx[4] = { 0,0,1,-1 }; int dy[4] = { 1,-1,0,0 };
int arr[100][100];
bool visited[100][100];
int minValue = 105, maxValue = -1;
vector<int> ans;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > maxValue) {
				maxValue = arr[i][j];
			}
			if (arr[i][j] < minValue) {
				minValue = arr[i][j];
			}
		}
	}
}

int bfs(int height) {
	queue<pair<int, int>>myQueue;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	int area = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && (arr[i][j] > height)) {
				visited[i][j] = true;
				myQueue.push({ i,j });

				while (!myQueue.empty()) {
					auto node = myQueue.front();
					myQueue.pop();
					int x = node.first; int y = node.second;

					for (int k = 0; k < 4; k++) {
						int newX = x + dx[k]; int newY = y + dy[k];
						if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n)) {
							if (!visited[newX][newY] && (arr[newX][newY] > height)) {
								visited[newX][newY] = true;
								myQueue.push({ newX,newY });
							}
						}
					}
				}
				area++;
			}
		}
	}
	return area;
}

int main() {
	input();
	int region;
	for (int i = minValue-1; i <= maxValue; i++) {
		region = bfs(i);
		ans.push_back(region);
	}

	auto maxIt = max_element(ans.begin(), ans.end());
	cout << *maxIt << "\n";

	return 0;
}