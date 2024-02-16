#include <iostream>

int main() {
	int a, b;
	int sum = 0;
	int arr[1000];

	int tmp = 1;
	bool exit = false;
	while (!exit) {
		int start = ((tmp - 1) * tmp) / 2;
		int end = tmp * (tmp + 1) / 2;
		for (int i = start; i < end; i++) {
			arr[i] = tmp;
			if (i == 999) {
				exit = true;
				break;
			}
		}
		tmp++;
	}
	std::cin >> a >> b;
	for (int i = a-1; i < b; i++) {
		sum += arr[i];
	}
	std::cout << sum << "\n";
	return 0;
}