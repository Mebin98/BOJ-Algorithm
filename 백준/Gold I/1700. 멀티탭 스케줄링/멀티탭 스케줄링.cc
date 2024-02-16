#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> mem;
	int input;

	for (int i = 0; i < k; i++) { 
		cin >> input;
		mem.push_back(input);
	}

	// OPT Algorithm 
	// -> 앞으로 가장 오랫동안 사용하지 않을 페이지 교체
	vector<int> multi;
	int index = 0;

	while (true) {
		auto it = find(multi.begin(), multi.end(), mem[index]);
		if (it == multi.end()) {
			multi.push_back(mem[index]);
		}
		if (multi.size() == n || index >= k - 1) {
			break;
		}
		index++;
	}

	/*
	cout << "Debug : \n";
	for (int i = 0; i < multi.size(); i++) {
		cout << multi[i] << " ";
	}
	cout << "\n";
	*/

	if (index >= k-1) {
		cout << 0 << "\n";
		return 0;
	}

	int ans = 0;

	for (int i = n; i < k; i++) {
		bool exit = false;
		for (int c = 0; c < n; c++)
		{
			if (multi[c] == mem[i]) {
				exit = true;
				break;
			}
		}

		if (exit) {
			continue;
		}


		vector<int> index(n, 150);
		vector<int> already;
		int check = 0;
		for (int j = i + 1; j < k; j++) {
			int obj = mem[j];
			bool appeared = false;
			for (int e = 0; e < already.size(); e++)
			{
				if (obj == already[e]) {
					appeared = true;
				}
			}

			if (!appeared)
			{
				for (int a = 0; a < n; a++) {
					if (obj == multi[a]) // hit
					{
						index[a] = j;
						check++;
						// 1 2 3 4 1 1 1 2 의 경우
						// 뒤에서 1이 더 오는경우 불필요하게 check++..
						already.push_back(obj);
					}
				}
			}
			if (check == n) break;
		}


		/*
		cout << "Debug : \n";
		for (int i = 0; i < index.size(); i++) {
			cout << index[i] << " ";
		}
		cout << "\n";
		*/
		
		int max = -1;
		int max_idx = -1;
		for (int b = 0; b < n; b++)
		{
			if (index[b] > max) {
				max = index[b];
				max_idx = b;
			}
		}

		int temp = multi[max_idx];
		multi[max_idx] = mem[i];
		mem[i] = temp;
		ans++;

		/*
		cout << "Debug : \n";
		for (int i = 0; i < multi.size(); i++) {
			cout << multi[i] << " ";
		}
		cout << "\n";
		*/
	}

	cout << ans << "\n";
	return 0;
}