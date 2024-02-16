#include <iostream>

using namespace std;

int main() {
	int arr[501];
	arr[0] = 0;
	int tmp;


	for (int i = 1; i <= 500; i++) {
		int cnt = 0;
		tmp = i;
		while (tmp % 5 == 0) {
			tmp = tmp / 5;
			cnt += 1;
		}

		if (i % 5 == 0) {
			arr[i] = arr[i - 1] + cnt;
		}
		else {
			arr[i] = arr[i - 1];
		}
	}

	int n;
	cin >> n;
	cout << arr[n] << "\n";

	return 0;
}