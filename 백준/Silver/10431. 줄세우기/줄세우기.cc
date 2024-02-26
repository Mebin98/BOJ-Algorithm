#include <iostream>

using namespace std;

int arr[21];
int back;

// 자기보다 키가 큰 사람중 가장 앞에있는 사람의 앞에 스라는 것
void swap(int index) {
	int tmpIndex;
	for (int i = index - 1; i > 0; i--) {
		if (arr[i] > arr[index]) {
			tmpIndex = i;
		}
	}

	// tmpIndex -> 자기보다 키가 큰 사람중 가장 앞에있는 사람의 index
	for (int i = index; i > tmpIndex; i--) {
		int temp = arr[i];
		arr[i] = arr[i - 1];
		arr[i - 1] = temp;
		back += 1;
	}
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		int max = -1;
		back = 0;
		for (int j = 0; j < 21; j++) {
			cin >> arr[j]; // arr[0]은 케이스번호이므로 건들면 안됨
			if (j > 0) {
				if (arr[j] > max) {
					max = arr[j];
				}
				else {
					swap(j);
				}
			}
		}
		cout << arr[0] << " " << back << "\n";
	}
	return 0;
}