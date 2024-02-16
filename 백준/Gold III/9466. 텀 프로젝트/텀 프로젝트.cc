#include <iostream>
#include <vector>
#define MAX 100001

using namespace std;

int test, num;
int member[MAX];
bool visited[MAX];
vector<int> team;
int ans = 0;

int dfs(int index, vector<int>& team) {
	int nextValue = member[index];
	if (!visited[nextValue]) {
		visited[nextValue] = true; team.push_back(nextValue);
		return dfs(nextValue, team);
	}
	else {
		int returnValue = 0;
		for (int i = 0; i < team.size(); i++) {
			if (team[i] == nextValue) {
				returnValue = i;
				return returnValue;
			}
		}
		returnValue = team.size();
		return returnValue;
	}
}

void input() {
	cin >> num;
	for (int i = 1; i <= num; i++) {
		cin >> member[i];
		visited[i] = false;
	}
}

void simulation() {
	cin >> test;
	for (int i = 0; i < test; i++) {
		input();
		ans = 0;
		for (int j = 1; j <= num; j++) {
			if (!visited[j]) {
				if (!team.empty()) {
					team.clear();
				}
				visited[j] = true; team.push_back(j);
				ans += dfs(j, team);
			}
		}
		cout << ans << "\n";
	}
}

int main() {
	simulation();
}