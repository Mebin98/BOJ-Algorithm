#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<string> room;

	int n;
	cin >> n;

	string input;
	for (int i = 0; i < n; i++) {
		cin >> input;
		room.push_back(input);
	}

    // 가로
	int garo = 0;
	for (int i = 0; i < n; i++) {
		int bed = 0;
		for (int j = 0; j < n; j++) {
			if (room[i][j] == '.')
			{
				bed += 1;
			}
			else {
				bed = 0;
			}

			if (bed == 2) {
				garo += 1;
			}
		}
	}

	// 새로
	int sero = 0;
	for (int i = 0; i < n; i++) {
		int bed = 0;
		for (int j = 0; j < n; j++) {
			if (room[j][i] == '.')
			{
				bed += 1;
			}
			else {
				bed = 0;
			}

			if (bed == 2) {
				sero += 1;
			}
		}
	}

	cout << garo << " " << sero << "\n";



	return 0;
}