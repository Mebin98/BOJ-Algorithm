#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

bool reg[105][105] = {false};
bool visited[105][105] = { false };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector<int> ans;
queue<pair<int, int>> myQueue;

void init(int x1, int y1, int x2, int y2) { // 0 2 4 4 Input
	// 좌표 하나를 정사각형이라고 가정 -> 인덱스 헷갈려 ㅠ
	// Commit
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			reg[i][j] = true;
			//cout << "Debug : " << i << " " << j << "\n";
		}
	}

	
}

int main() {
	int m, n, k;
	cin >> m >> n >> k;

	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		init(x1, y1, x2, y2);
	}

	int num = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!reg[i][j] && !visited[i][j]) {
				int area = 0;
				visited[i][j] = true;
				myQueue.push({ i,j });
				
				while (true) {
					auto node = myQueue.front();
					myQueue.pop();
					area++;

					int x = node.first; int y = node.second;
					for (int k = 0; k < 4; k++) {
						int newX = x + dx[k]; int newY = y + dy[k];
						if ((newX >= 0 && newX < m) && (newY >= 0 && newY < n)) {
							if (!reg[newX][newY] && !visited[newX][newY]) {
								reg[newX][newY] = true;
								myQueue.push({ newX,newY });
							}
						}
					}

					if (myQueue.empty()) {
						break;
					}
				}
				ans.push_back(area);
				num++;
			}
		}
	}

	
	cout << num << "\n";

	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	

	return 0;
}