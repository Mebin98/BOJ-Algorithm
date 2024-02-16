#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		string school;
		long long amount;
		int maxAmount = 0;
		string maxSchool;
		for (int j = 0; j < n; j++)
		{
			cin >> school >> amount;
			if (amount > maxAmount) {
				maxAmount = amount;
				maxSchool = school;
			}
		}
		cout << maxSchool << "\n";
	}

	return 0;
}