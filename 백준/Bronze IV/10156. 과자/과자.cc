#include <iostream>

using namespace std;

int main() {
	int price;
	int num;
	int crtMoney;
	
	cin >> price >> num >> crtMoney;

	int temp = price * num;

	if (temp > crtMoney) {
		cout << temp - crtMoney;
	}
	else {
		cout << 0;
	}

	return 0;
}