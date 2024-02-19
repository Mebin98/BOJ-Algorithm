#include <iostream>
#include <deque>

using namespace std;

struct Tree {
	int loc;
	int time;
	Tree(int loc, int time) :loc(loc), time(time) {};
};

deque<Tree> myDeque;
int visited[100001] = { false };
int s, e;

int bfs() {
	int ans = -1;
	while (!myDeque.empty()) {
		auto crt = myDeque.front(); myDeque.pop_front();
		int loc = crt.loc; int time = crt.time;

		if (loc == e) {
			ans = time;
		}
		
		if ((loc < 0 || loc > 100000)) continue;

		int mLoc = loc - 1; int mTime = time + 1;
		int pLoc = loc + 1; int pTime = time + 1;
		int tele = loc * 2; int teleTime = time;

		if ((tele >= 0) && (tele <= 100000)) {
			if (!visited[tele]) {
				visited[tele] = true;
				myDeque.push_front(Tree(tele, teleTime));
			}
		}

		if ((mLoc >= 0) && (mLoc <= 100000)) {
			if (!visited[mLoc]) {
				visited[mLoc] = true;
				myDeque.push_back(Tree(mLoc, mTime));
			}
		}

		if ((pLoc >= 0) && (pLoc <= 100000)) {
			if (!visited[pLoc]) {
				visited[pLoc] = true;
				myDeque.push_back(Tree(pLoc, pTime));
			}
		}

		if (myDeque.empty()) {
			break;
		}
	}
	return ans;
}

int main() {
	cin >> s >> e; // input;
	myDeque.push_front(Tree(s, 0)); visited[s] = true;
	int ans = bfs();
	cout << ans << "\n";
	return 0;
}