#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {

	int n;
	cin >> n;
	
	bool check = true;
	while (true) {
		check = true;
		string palindrome = to_string(n);
		int p_size = palindrome.size();

		if (p_size % 2 != 0) { // 자릿수가 홀수일 때,
			for (int i = 0; i < (p_size + 1) / 2; i++) {
				if (palindrome[i] != palindrome[p_size - 1 - i]) {
					check = false;
					break;
				}
			}
		}
		else { // 자릿수가 짝수일 때,
			for (int i = 0; i < (p_size / 2); i++) {
				if (palindrome[i] != palindrome[p_size - 1 - i]) {
					check = false;
					break;
				}
			}
		}

		if (!check) {
			n++;
			continue;
		}

		if (n == 1) {
			n++;
			continue;
		}
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) {
				check = false;
				break;
			}
		}
		if (!check) {
			n++;
			continue;
		}
		else {
			cout << n << "\n";
			break;
		}
	}
	return 0;
}