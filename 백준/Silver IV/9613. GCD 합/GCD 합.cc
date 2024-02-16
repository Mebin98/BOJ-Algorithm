#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b){
	if (b > a) {
		int temp = a;
		a = b;
		b = temp;
	}

	if (a % b == 0)
	{
		return b;
	}
	else
	{
		return gcd(b, a % b);
	}
}

int main() {
	int t;
	int n;
	int num;

	cin >> t;
	vector<int> answer;

	for (int i = 0; i < t; i++) {
		cin >> n;
		vector<int> arr;

		for (int j = 0; j < n; j++) {
			cin >> num;
			arr.push_back(num);
		}

		long long res = 0;
		for (int k = 0; k < arr.size()-1; k++) {
			for (int l = k+1; l < arr.size(); l++) {
				if(k != l) res += gcd(arr[k], arr[l]);
			}
		}
		cout << res << "\n";
	}

	return 0;
}