#include <iostream>
#include <string>

using namespace std;

int main() {
	string input;
	cin >> input;

	bool gwalHo = false;
	int subSum = 0;
	int ans = 0;
	int num = 0;
	string subStr = "";

	for (int i = 0; i < input.size(); i++) {
		if (input[i] != '-' && input[i] != '+')  // 숫자 차례
		{ 
			subStr += input[i];
		}
		if(input[i] == '-' || input[i] == '+' || i == input.size()-1) // 연산자 차례
		{
			num = stoi(subStr);
			subStr = "";
			if (gwalHo) {
				subSum += num;
				if (input[i] == '-' || i == input.size() - 1) {
					ans += -(subSum);
					subSum = 0;
				}
			}
			else {
				ans += num;
				if (input[i] == '-' || i == input.size() - 1) {
					gwalHo = true;
					subSum = 0;
				}
			}
		}
	}

	cout << ans << "\n";

	return 0;
}