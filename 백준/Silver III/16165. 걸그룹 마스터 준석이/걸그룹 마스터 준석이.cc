#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main() {
	int n, m; // n -> 걸그룹의 수, m -> 문제의 수
	cin >> n >> m;

	map<string, vector<string>>table;

	string name; // 걸그룹 이름
	int num; // 명수
	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> num;
		string idol;
		for (int j = 0; j < num; j++) {
			cin >> idol;
			table[name].push_back(idol);
		}
	}

	string who;
	int signal;
	for (int i = 0; i < m; i++) {
		cin >> who;
		cin >> signal;
		if (signal == 1) {
			for (const auto& group : table) {
				if (find(group.second.begin(), group.second.end(), who) != group.second.end()) {
					cout << group.first << "\n"; // 걸그룹 이름 출력
					break; // 멤버를 찾은 후 반복문 종료
				}
			}
			
		}
		else if (signal == 0) {
			sort(table[who].begin(), table[who].end());
			for (int j = 0; j < table[who].size(); j++) {
				cout << table[who][j] << "\n";
			}
		}
	}


	return 0;
}