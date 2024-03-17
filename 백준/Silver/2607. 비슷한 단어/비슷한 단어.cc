#include <iostream>
#include <algorithm>

using namespace std;

bool checkComposition(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a == b) return true;
	else return false;
}

bool checkCompositionTwo(string a, string b) {
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a.size() > b.size()) {
		for (int i = 0; i < a.size(); i++) {
			string subStr = "";
			for (int j = 0; j < a.size(); j++) {
				if (i != j) {
					subStr += a[j];
				}
			}
			if (subStr == b) {
				return true;
			}
		}
	}
	else if (a.size() == b.size()) {
		int aArr[26] = { 0 }; int bArr[26] = { 0 };
		for (int i = 0; i < a.size(); i++) {
			aArr[a[i] - 65]++;
			bArr[b[i] - 65]++;
		}
		int diff = 0;
		for (int i = 0; i < 26; i++) {
			diff += abs(aArr[i] - bArr[i]);
		}
		if (diff <= 2) {
			return true;
		}
		return false;
	}
	else if(a.size() < b.size()) {
		for (int i = 0; i < b.size(); i++) {
			string subStr = "";
			for (int j = 0; j < b.size(); j++) {
				if (i != j) {
					subStr += b[j];
				}
			}
			if (subStr == a) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	string input;
	string firstInput;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cin >> firstInput;
		}
		else {
			cin >> input;
			if (checkComposition(firstInput, input)) {
				ans += 1;
			}
			else {
				if (checkCompositionTwo(firstInput, input)) {
					ans += 1;
				}
			}
		}
	}
	cout << ans << "\n";
	return 0;
}