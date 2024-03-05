#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> light;
int dark[100001];
int length;

void input() {
	cin >> length;
	int m, input;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input;
		light.push_back(input);
	}
}

void init() {
	for (int i = 0; i <= length; i++) {
		dark[i] = 0;
	}
}

int binarySearch(int height) {
	int minV = 1; int maxV = height;
	int ans = -1;
	while (true) {
		init();
		int mid = (minV + maxV) / 2;
		for (int i = 0; i < light.size(); i++) {
			int start = max(light[i] - mid, 0);
			int end = min(light[i] + mid, length);
			dark[start]++;
			dark[end]--;
		}
		
		int check = 0;
		int bright = 0;
		for (int i = 0; i <= length; i++) {
			check += dark[i];
			if (check > 0) {
				bright++;
			}
		}

		if (bright >= length) maxV = mid;
		else minV = mid + 1;
		if (minV == maxV) {
			ans = minV;
			break;
		}
	}
	return ans;
}

int main() {
	input();
	int ans = binarySearch(length);
	cout << ans << "\n";
	return 0;
}