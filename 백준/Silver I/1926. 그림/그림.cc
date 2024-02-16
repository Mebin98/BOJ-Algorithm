#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int paint[505][505];
vector<pair<int, int>> visit;
queue<pair<int, int>> myQueue;
int n, m;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> paint[i][j];
			visit.push_back({ i,j });
		}
	}

	int visit_size = visit.size();
	int area = 0, maxArea = 0, drawNum = 0;

	for (int i = 0; i < visit_size; i++)
	{
		int x = visit[i].first;
		int y = visit[i].second;
		bool go = false;
		if (paint[x][y] == 1)
		{
			myQueue.push({ x,y });
			paint[x][y] = 0;
			go = true;
		}
		area = 0;
		
		while (go) 
		{
			auto node = myQueue.front();
			int nodeX = node.first;
			int nodeY = node.second;
			myQueue.pop();
			area++;

			for (int j = 0; j < 4; j++)
			{
				int newX = nodeX + dx[j];
				int newY = nodeY + dy[j];
				if ((newX >= 0 && newX < n) && (newY >= 0) && (newY < m))
				{
					if (paint[newX][newY] == 1)
					{
						myQueue.push({ newX, newY });
						paint[newX][newY] = 0;
					}
				}
			}

			if (myQueue.empty()) {
				if (area > maxArea)
				{
					maxArea = area;
				}
				drawNum++;
				break;
			}
		}

	}

	cout << drawNum << "\n";
	cout << maxArea << "\n";


	return 0;
}