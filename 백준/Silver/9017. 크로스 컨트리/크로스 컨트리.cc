#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
1. 결승점을 통과한 순서대로 점수를 받는다.
2. 점수를 더해서 가장 낮은 점수를 얻는 팀이 우승.
3. 주자가 여섯명 아니면 점수 계산에서 제외
4. 동점의 경우에는 다섯번째 주자가 가장빨리 들어온 팀이 우승
5. 팀 점수는 네 명의 주자의 점수를 합하여 계산
*/

int compareScore(vector<int> score, vector<int> five) {
	int min = 1000001;
	int minTeam = -1;
	
	for (int i = 1; i < score.size(); i++) {
		if (score[i] > 0) {
			if (score[i] < min) {
				min = score[i];
				minTeam = i;
			}
			else if (score[i] == min) {
				if (five[i] < five[minTeam]) {
					minTeam = i;
				}
			}
		}
	}
	return minTeam;
}

int computeScore(vector<int> team, vector<int> howMany) {
	for (int i = 0; i < team.size(); i++) {
		howMany[team[i]]++;
	}

	vector<int> score(201, 0);
	vector<int> chance(201, 1);
	vector<int> five(201, 0);

	for (int i = 1; i < howMany.size(); i++) {
		if (howMany[i] != 6) {
			for (int j = 0; j < team.size(); j++) {
				if (team[j] == i) {
					team[j] = -1;
				}
			}
		}
	}
	auto newEnd = std::remove(team.begin(), team.end(), -1);
	team.erase(newEnd, team.end());
	
	for (int i = 1; i < howMany.size(); i++) {
		if (howMany[i] == 6) {
			for (int j = 0; j < team.size(); j++) {
				if (team[j] == i && (chance[i] < 5)) {
					score[i] += (j + 1); 
					chance[i] += 1;
				}
				else if (team[j] == i && (chance[i] == 5)) {
					five[i] += (j + 1); 
					chance[i] += 1;
				}
			}
		}
	}

	int which = compareScore(score, five);
	return which;
}

void input() {
	int t;
	cin >> t;

	int n, player;
	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> team;
		vector<int> howMany(201, 0);
		for (int j = 0; j < n; j++) {
			cin >> player;
			team.push_back(player);
		}

		int ans = computeScore(team, howMany);
		cout << ans << "\n";
		team.clear();
		howMany.clear();
	}
}

int main() {
	input();
	return 0;
}