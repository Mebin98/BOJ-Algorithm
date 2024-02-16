#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maze[105][105];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

struct MiroTree {
	pair<int, int> index;
	int generation;
	
	MiroTree(int x, int y, int gen) : index(x,y), generation(gen){}
};

int main() {

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < m; j++)
		{
			maze[i][j] = input[j] - '0';
		}
	}

	queue<MiroTree> myQueue;
	myQueue.push(MiroTree(0, 0, 1));
	maze[0][0] = 0;
	int ans = 0;

	while (true)
	{
		MiroTree node = myQueue.front();
		myQueue.pop();
		int x = node.index.first;
		int y = node.index.second;
		int gen = node.generation;


		if ((x == n - 1) && (y == m - 1))
		{
			ans = gen;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			int newX = x + dx[i];
			int newY = y + dy[i];
			int newGen = gen + 1;

			if ((newX >= 0 && newX < n) && (newY >= 0) && (newY < m))
			{
				if (maze[newX][newY] == 1)
				{
					maze[newX][newY] = 0;
					myQueue.push(MiroTree(newX, newY, newGen));
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}