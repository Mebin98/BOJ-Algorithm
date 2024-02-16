#include <iostream>
#include <map>

using namespace std;
map<long long, long long> hashTable;
long long n, p, q;

long long seq(long long num) {
	if (num == 0) {
		return hashTable[0];
	}

	long long num1, num2;
	
	long long idx_1 = num / p;
	if (hashTable.count(idx_1) > 0) {
		num1 = hashTable[idx_1];
	}
	else {
		num1 = seq(idx_1);
	}

	long long idx_2 = num / q;
	if (hashTable.count(idx_2) > 0) {
		num2 = hashTable[idx_2];
	}
	else {
		num2 = seq(idx_2);
	}

	hashTable[num] = num1 + num2;
	
	return hashTable[num];
}

int main() {
	cin >> n >> p >> q;
	long long ans;
	hashTable[0] = 1;

	ans = seq(n);
	
	cout << ans << "\n";

	return 0;
}