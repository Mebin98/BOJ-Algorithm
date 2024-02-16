#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a, b, v;

	cin >> a >> b >> v;

	double temp = static_cast<double>(v - a) / static_cast<double>(a - b);
	int day = static_cast<int>(ceil(temp)) + 1;

	cout << day << "\n";
	
	return 0;
}