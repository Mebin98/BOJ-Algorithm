#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tree {
	int loc;
	int time;
	Tree(int loc, int time) :loc(loc), time(time) {};
};

queue<Tree> myQueue;
int s, e;
int visited[100001] = { false };
int parent[100001];
int timeAns = -1;
vector<int> ans;

void input() {
	cin >> s >> e;
	visited[s] = true;
	parent[s] = -1;
	myQueue.push(Tree(s, 0));
}

void bfs() {
	while (true) {
		auto node = myQueue.front(); myQueue.pop();
		int loc = node.loc; int time = node.time;
		int newTime = time + 1;

		if (loc == e) {
			timeAns = time;
		}

		int pLoc = loc + 1; int mLoc = loc - 1; int teleLoc = loc * 2;
		if ((pLoc >= 0 && pLoc <= 100000)) {
			if (!visited[pLoc]) {
				visited[pLoc] = true;
				parent[pLoc] = loc;
				myQueue.push(Tree(pLoc, newTime));
			}
		}

		if ((mLoc >= 0 && mLoc <= 100000)) {
			if (!visited[mLoc]) {
				visited[mLoc] = true;
				parent[mLoc] = loc;
				myQueue.push(Tree(mLoc, newTime));
			}
		}

		if ((teleLoc >= 0 && teleLoc <= 100000)) {
			if (!visited[teleLoc]) {
				visited[teleLoc] = true;
				parent[teleLoc] = loc;
				myQueue.push(Tree(teleLoc, newTime));
			}
		}

		if (myQueue.empty()) {
			break;
		}
	}
}

void traceChild() {
	int temp = parent[e];
	ans.push_back(e);
	while (true) {
		int newTemp = parent[temp];
		ans.push_back(temp);
		if (newTemp == -1) {
			break;
		}
		temp = newTemp;
	}
}

void startLongerException() {
	int time = 0;
	vector<int> his;
	for (int i = s; i >= e; i--) {
		his.push_back(i);
		time++;
	}
	cout << time-1 << "\n";
	for (int i = 0; i < his.size(); i++) {
		cout << his[i] << " ";
	}
}

void output() {
	reverse(ans.begin(), ans.end());
	cout << timeAns << "\n";
	for (int i : ans) {
		cout << i << " ";
	}
}

void sameException() {
	cout << 0 << "\n";
	cout << s;
}

int main() {
	input();
	if (s > e) {
		startLongerException();
		return 0;
	}
	if (s == e) {
		sameException();
		return 0;
	}
	bfs();
	traceChild();
	output();

	return 0;
}