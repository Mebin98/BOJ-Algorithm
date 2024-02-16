#include <iostream>

using namespace std;

int main() {
	int num, avg;
	cin >> num >> avg;

	int min = num * (avg-1);
	int max = num * avg;


	cout << min + 1 << "\n";


	return 0;
}