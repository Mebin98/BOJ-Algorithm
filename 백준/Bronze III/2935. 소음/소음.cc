#include <iostream>

using namespace std;

int main() {
	string a, b;
	char op;
	cin >> a;
	cin >> op;
	cin >> b;

	// bool change = false;
	if (op == '*') {
		int size = a.size() + b.size() - 2;
		cout << 1;
		for (int i = 0; i < size; i++) {
			cout << 0;
		}
		cout << "\n";
	}
	else {
		if (a.size() == b.size()) {
			cout << 2;
			for (int i = 0; i < a.size() - 1; i++) {
				cout << 0;
			}
		}
		else if (a.size() > b.size()) {
			for (int i = 0; i < a.size(); i++) {
				if (i < a.size() - b.size()) {
					cout << a[i];
				}
				else {
					cout << b[i - a.size() + b.size()];
				}
			}
		}
		else {
			for (int i = 0; i < b.size(); i++) {
				if (i < b.size() - a.size()) {
					cout << b[i];
				}
				else {
					cout << a[i - b.size() + a.size()];
				}
			}
		}
	}
}