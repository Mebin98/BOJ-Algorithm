#include <iostream>
#include <vector>

using namespace std;
int heap[100005];
int sz = 0; // heap 에 들어있는 원소의 수

void push(int data) {
	heap[++sz] = data;
	
	int index = sz;
	int parentIndex = index / 2;

	while (heap[index] < heap[parentIndex] && sz > 1) {
		int temp = heap[index];
		heap[index] = heap[parentIndex];
		heap[parentIndex] = temp;
		index = parentIndex;
		parentIndex = index / 2;
	}

	// Debugging
	/*
	cout << "\n";
	for (int i = 1; i <= sz; i++) {
		cout << heap[i] << " ";
	}
	cout << "\n";
	*/
}

int top() {
	if (sz == 0) {
		return 0;
	}
	return heap[1];
}

void pop() { // 최솟값을 트리에서 제거하는 함수 
	int temp = heap[1];
	heap[1] = heap[sz];
	heap[sz] = temp;
	sz--;

	int index = 1;

	while (true) {
		int left = 2 * index;
		int right = 2 * index + 1;
		if (left > sz) break;
		if (right > sz && left == sz) {
			if (heap[index] > heap[left]) {
				temp = heap[index];
				heap[index] = heap[left];
				heap[left] = temp;
			}
			break;
		}

		if (heap[index] < heap[left] && heap[index] < heap[right]) {
			break;
		}

		if (heap[left] < heap[right]) {
			temp = heap[index];
			heap[index] = heap[left];
			heap[left] = temp;
			index = left;
		}
		else {
			temp = heap[index];
			heap[index] = heap[right];
			heap[right] = temp;
			index = right;
		}
	}
}

int main() {
	heap[0] = -1;
	int n;
	cin >> n;
	
	int input;
	int ans;
	vector<int> answer;
	for (int i = 0; i < n; i++) {
		//Debugging
		//cout << "=================\n";
		cin >> input;
		if (input != 0) {
			push(input);
		}
		else {
			ans = top();
			answer.push_back(ans);
			if (ans != 0) {
				pop();
			}
			//Debugging
			/*
			cout << "\n";
			for (int i = 1; i <= sz; i++) {
				cout << heap[i] << " ";
			}
			cout << "\n";
			*/
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << "\n";
	}
	return 0;
}