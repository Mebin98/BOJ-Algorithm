#include <iostream>
#include <map>
#include <functional>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<std::string, bool,std::greater<>> company;

	for (int i = 0; i < n; i++) {
		string name, action;
		cin >> name >> action;

		if (action == "enter") {
			company[name] = true;
		}
		else if (action == "leave") {
			company[name] = false;
		}
	}

	for (const auto& pair : company) {
		if (pair.second) {
			cout << pair.first << "\n";
		}
	}

	return 0;
}
