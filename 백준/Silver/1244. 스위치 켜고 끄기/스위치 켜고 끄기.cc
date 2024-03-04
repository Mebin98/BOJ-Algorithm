#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;

int num;
int student;
vector<int> sw;
vector<pii> info;

void input() {
	cin >> num;
	int light = -1;
	sw.push_back(light);
	for (int i = 0; i < num; i++) {
		cin >> light;
		sw.push_back(light);
	}

	cin >> student;
	int gender; int n;
	for (int i = 0; i < student; i++) {
		cin >> gender >> n;
		info.push_back({ gender , n });
	}
}

void man(int index) {
	int firstCrt = info[index].second;
	int crt;
	int mul = 1;
	while (true) {
		crt =  firstCrt * mul;
		if (crt > 0 && crt <= num) {
			if (sw[crt] == 0) sw[crt] = 1;
			else sw[crt] = 0;
		}
		else {
			break;
		}
		mul += 1;
	}
}

void women(int index) {
	int crt = info[index].second;
	if (sw[crt] == 0) sw[crt] = 1;
	else sw[crt] = 0;
	for (int offset = 1; ; offset++) {
		if (((crt - offset) <= 0 || (crt - offset) > num)
			|| (crt + offset) <= 0 || (crt + offset) > num) {
			break;
		}
		if (sw[crt - offset] == sw[crt + offset]) {
			if (sw[crt - offset] == 0) {
				sw[crt - offset] = 1; sw[crt + offset] = 1;
			}
			else {
				sw[crt - offset] = 0; sw[crt + offset] = 0;
			}
		}
		else {
			break;
		}
	}
}

void printList() {
	int index = 1;
	while (true) {
		cout << sw[index] << " ";
		index += 1;
		if (index == sw.size()) {
			break;
		}
		if ((index-1) % 20 == 0) {
			cout << "\n";
		}
	}
}

void simulation() {
	for (int i = 0; i < student; i++) {
		if (info[i].first == 1) { // 남학생일 경우
			man(i);
		}
		else { // 여학생일 경우
			women(i);
		}
	}
}

int main() {
	input();
	simulation();
	printList();
	return 0;
}