#include <iostream>

using namespace std;

int teamProb[101][101] = { 0 };
int freq[101] = { 0 };
int lastTime[101] = { 0 };

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			teamProb[i][j] = 0;
		}
		freq[i] = 0;
		lastTime[i] = 0;
	}
}

int sortByCond(int teamNum, int probNum, int yourId) {
	int myScore = 0;
	int myRank = 1;
	for (int i = 1; i <= probNum; i++) {
		myScore += teamProb[yourId][i];
	}

	for (int i = 1; i <= teamNum; i++) {
		if (i != yourId) {
			int yourScore = 0;
			for (int j = 1; j <= probNum; j++) {
				yourScore += teamProb[i][j];
			}
			if (yourScore > myScore) {
				myRank++;
			}
			else if (yourScore == myScore) {
				if (freq[yourId] > freq[i]) {
					myRank++;
				}
				else if (freq[yourId] == freq[i]) {
					if (lastTime[yourId] > lastTime[i]) {
						myRank++;
					}
				}
			}
		}
	}

	return myRank;
}

void input() {
	int t; // number of test case
	cin >> t;
	int teamNum, probNum, yourId, log;
	int id, prob, score;
	for (int i = 0; i < t; i++) {
		init();
		cin >> teamNum >> probNum >> yourId >> log;
		for (int j = 0; j < log; j++) {
			cin >> id >> prob >> score;
			if(score > teamProb[id][prob]) teamProb[id][prob] = score;
			freq[id]++;
			lastTime[id] = j;
		}
		int ans = sortByCond(teamNum, probNum, yourId);
		cout << ans << "\n";
	}
}

int main() {
	input();
	return 0;
}