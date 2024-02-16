#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	int dp[300][300];
	dp[0][0] = 0;

	for (int i = 1; i < 300; i++) {
		dp[i][0] = i; dp[0][i] = i;
	}

	int tmp = 0;
	for (int i = 1; i < 300; i++) {
		for (int j = 1; j < 300; j++) {
			if (j % 2 != 0) {
				dp[j][i] = dp[(j-1)/2][i] * 2 + 1;
			}
			else {
				dp[j][i] = dp[j / 2][i] + dp[(j / 2) - 1][i] + 1;
			}
		}
	}

	cout << dp[n - 1][m - 1] << "\n";


	return 0;
}