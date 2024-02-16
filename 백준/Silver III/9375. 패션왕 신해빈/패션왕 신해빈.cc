#include <iostream>
#include <map>

using namespace std;

int main() {
	int tc, n;
	cin >> tc;
	int answer[101];

	string clothe, name;
	for (int i = 0; i < tc; i++) {
		cin >> n;
		map<string, int> table;
		for (int j = 0; j < n; j++) {
			cin >> clothe >> name;
			table[name] += 1;
		}

		int mul = 1;
		for (const auto& pair : table) {
			mul = mul * (pair.second + 1);
		}
		mul -= 1;
		answer[i] = mul;
	}

	for (int i = 0; i < tc; i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}