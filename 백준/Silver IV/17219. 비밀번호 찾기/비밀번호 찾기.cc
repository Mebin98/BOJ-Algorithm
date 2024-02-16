#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int n, m;
	map<string, string> program;
	vector<string> answer;

	cin >> n >> m;

	string addr, pw;
	for (int i = 0; i < n; i++) {
		cin >> addr >> pw;
		program[addr] = pw;
	}

	
	for (int i = 0; i < m; i++) {
		cin >> addr;
		answer.push_back(program[addr]);
	}

	for (const string& ans : answer) {
		cout << ans << "\n";
	}

	return 0;
}