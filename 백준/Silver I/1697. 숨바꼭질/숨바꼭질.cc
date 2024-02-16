#include <iostream>
#include <queue>
bool visited[100005] = { false };

using namespace std;

int main() {
	int subin, bro;
	cin >> subin >> bro;

	queue<pair<int, int>> myQueue;

	myQueue.push({ subin, 0 }); // 수빈이의 현재 위치, time = 0
	visited[subin] = true;

	while (true) {
		auto node = myQueue.front();
		myQueue.pop();

		int crtLoc = node.first;
		int time = node.second;

		int newLoc = 0;
		int newTime = time + 1;

		if (crtLoc < 0 && crtLoc >100000) continue;

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				newLoc = crtLoc + 1;
				if (newLoc >= 0 && newLoc <= 100000) {
					if (!visited[newLoc]) {
						myQueue.push({ newLoc,newTime });
						visited[newLoc] = true;
					}
				}
			}
			else if (i == 1) {
				newLoc = crtLoc - 1;
				if (newLoc >= 0 && newLoc <= 100000) {
					if (!visited[newLoc]) {
						myQueue.push({ newLoc,newTime });
						visited[newLoc] = true;
					}
				}
				
			}
			else if (i == 2){
				newLoc = crtLoc * 2;
				if (newLoc >= 0 && newLoc <= 100000) {
					if (!visited[newLoc]) {
						myQueue.push({ newLoc,newTime });
						visited[newLoc] = true;
					}
				}
				
			}
		}

		// cout << crtLoc << " " << time << "\n";

		if (crtLoc == bro) {
			cout << time << "\n";
			break;
		}
	}

	return 0;
}