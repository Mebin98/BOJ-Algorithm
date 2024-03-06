#include <iostream>
#include <queue>

using namespace std;

queue<int> card;
int n;

void init() {
	for (int i = 0; i < n; i++) {
		card.push(i + 1);
	}
}

int simulation() {
	int ans = -1;
	while (true) {
		if (!card.empty()) { // 첫째로, 맨 앞에있는 요소를 버린다.
			card.pop();
		}
		if (card.size() == 1) {
			ans = card.front();
			break;
		}
		if (!card.empty()) {
			int element = card.front();
			card.pop();
			card.push(element);
		}
		if (card.size() == 1) {
			ans = card.front();
			break;
		}
	}
	return ans;
}

int main() {
	cin >> n;
	init();
	if (card.size() == 1) {
		cout << card.front() << "\n";
		return 0;
	}
	int ans = simulation();
	cout << ans << "\n";
	return 0;
}