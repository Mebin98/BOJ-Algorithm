#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, int> check;

	string str; 

	cin >> str;

	for (int i = 0; i <= str.size(); i++) {
		for (int len = 1; i + len <= str.size(); len++) {
			check[str.substr(i, len)] = 1;
		}
	}

	cout << check.size() << "\n";


	return 0;
}