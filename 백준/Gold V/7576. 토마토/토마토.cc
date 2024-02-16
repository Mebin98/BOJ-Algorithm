#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int tomato[1005][1005];
vector<pair<int, int>> visit;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct TomatoTree {
	pair<int,int> index;
	int day;

	TomatoTree(int x, int y, int day) : index(x, y), day(day) {}
};

int main() {
	queue<TomatoTree>myQueue;
	int n, m;
	int completed = 0; // Goal -> completed = n*m; -> 이걸로 하면 안됨
	int uncompleted = 0;
	int day;

	cin >> m >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				visit.push_back({ i,j });
				completed += 1;
				myQueue.push(TomatoTree(i, j, 0));
			}
			else if (tomato[i][j] == 0) {
				uncompleted += 1;
			}
		}
	}

	if (visit.empty()) {
		cout << -1 << "\n";
		return 0;
	}

	if (completed == n * m)
	{
		cout << 0 << "\n";
		return 0;
	}
	
	while (true)
	{
		auto node = myQueue.front();
		myQueue.pop();
		int x = node.index.first; int y = node.index.second;
		day = node.day;

		for (int i = 0; i < 4; i++) 
		{
			int newX = x + dx[i]; int newY = y + dy[i];
			int newDay = day + 1;
			if ((newX >= 0 && newX < n) && (newY >= 0 && newY < m)) 
			{
				if (tomato[newX][newY] == 0)
				{
					tomato[newX][newY] = 1;
					completed += 1;
					uncompleted -= 1;
					myQueue.push(TomatoTree(newX, newY, newDay));
				}
			}
		}

		if (myQueue.empty())
		{
			break;
		}

	}
	// 예제입력 2 케이스를 어케 처리할가?
	if (uncompleted == 0) {
		cout << day << "\n";
	}
	else {
		cout << -1 << "\n";
	}

	return 0;
}