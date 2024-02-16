#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a;
	vector<int> b;
	vector<pair<int, int>> memory;
	int element;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> element;
			if (i == 0) a.push_back(element);
			if (i == 1) {
				b.push_back(element);
				memory.push_back(make_pair(element, j));
			}
		}
	}

	// memory 내림차순으로 정렬
	sort(memory.begin(), memory.end(), [](const pair<int, int>& a,
		const pair<int, int>& b) {
			return a.first > b.first;
	});


	// a 오름차순으로 정렬
	sort(a.begin(), a.end(), [](int a, int b) {
		return a < b;
	});
	
	int answer[51];
	for (int i = 0; i < a.size(); i++) {
		answer[memory[i].second] = a[i];
	}

	int sum = 0;
	for (int i = 0; i < b.size(); i++) {
		sum += answer[i] * b[i];
	}

	cout << sum << "\n";

	return 0;
}