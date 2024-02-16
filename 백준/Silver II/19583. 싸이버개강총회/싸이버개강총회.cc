#include <iostream>
#include <string>
#include <map>

using namespace std;

int timeToInteger(string s) {
	string hour = s.substr(0, 2);
	string min = s.substr(3, 2);
	return stoi(hour) * 60 + stoi(min);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string start, end, stream;
	map<string, int>record;

	cin >> start >> end >> stream;
	int s = timeToInteger(start);
	int e = timeToInteger(end);
	int m = timeToInteger(stream);

	string time, student;
	int ans = 0;
	while (cin >> time >> student) {
		if (time.size() != 5) break;
		int t = timeToInteger(time);

		if (t <= s) {
			record[student] = 1;
		}
		else if (t >= e && t <= m) {
			if (record[student] == 1)
			{
				ans += 1;
				record.erase(student);

			}
		}
	}

	cout << ans << "\n";

	return 0;
}