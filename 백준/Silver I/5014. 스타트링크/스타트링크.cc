#include <iostream>
#include <queue>

using namespace std;

struct Tree {
	int loc;
	int time;
	Tree(int loc, int time) :loc(loc), time(time) {};
};

queue<Tree> myQueue;
bool visited[1000005];

int main() {
	int all, start, goal, up, down;
	cin >> all >> start >> goal >> up >> down;

	for (int i = 1; i <= all; i++) {
		visited[i] = false;
	}

	myQueue.push(Tree(start, 0));
	visited[start] = true;
	int ans = 0;

	while (true) {
		auto node = myQueue.front();
		myQueue.pop();

		int loc = node.loc; int time = node.time;
		if (loc == goal) {
			ans = time;
			cout << ans << "\n";
			break;
		}
		
		int newLocUp = loc + up;
		int newLocDown = loc - down;
		int newTime = time + 1;
		if (newLocUp >= 1 && newLocUp <= all) {
			if (!visited[newLocUp]) {
				myQueue.push(Tree(newLocUp, newTime));
				visited[newLocUp] = true;
			}
		}
		if (newLocDown >= 1 && newLocDown <= all) {
			if (!visited[newLocDown]) {
				myQueue.push(Tree(newLocDown, newTime));
				visited[newLocDown] = true;
			}
		}

		if (myQueue.empty()) {
			cout << "use the stairs\n";
			break;
		}
	}

	return 0;
}