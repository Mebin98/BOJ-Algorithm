#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	int a, b;
	vector<int> ans;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		ans.push_back(a + b); 

	}
	for (int j = 0; j < n; j++) {
		cout << "Case #" << j+1 << ": " << ans[j] << "\n";
	}

	return 0;
}