#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <string>
#include <cstdlib>

using namespace std;

int main() {

	int n, m;
	// n -> 포켓몬의 개수, m-> 문제의 개수
	cin >> n >> m;

	map<std::string, int> dogam;
	map<int, std::string> dogamNum;
	dogamNum[0] = -1;

	for (int i = 0; i < n; i++) {
		string pocketMon;
		cin >> pocketMon;

		dogam[pocketMon] = i + 1;
		dogamNum[i] = pocketMon;
	}

	char input[25];
	for (int j = 0; j < m; j++) {
		scanf("%s", &input);
		if (input[0] >= '0' && input[0] <= '9') { // 입력이 숫자일 때
			int index = atoi(input);
			cout << dogamNum[index - 1] << "\n";
		}
		else { // 입력이 문자열일 때
			cout << dogam[input] << "\n";
		}


	}

	return 0;
}