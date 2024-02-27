#include <iostream>
#include <vector>

using namespace std;

struct Info{
	int weight;
	int height;
	int rank;
	Info(int w, int h, int r) : weight(w), height(h), rank(r) {};
};

vector<Info> vec;
int t;

void input() {
	cin >> t;
	int w, h;
	for (int i = 0; i < t; i++) {
		cin >> w >> h;
		vec.push_back(Info(w, h, 1));
	}
}

void bruteForce() {
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < t; j++) {
			if ((i != j)) {
				if ((vec[j].weight > vec[i].weight) &&
					(vec[j].height > vec[i].height)) {
					vec[i].rank++;
				}
			}
		}
	}

	for (int i = 0; i < t; i++) {
		cout << vec[i].rank << " ";
	}
	cout << "\n";
}

int main() {
	input();
	bruteForce();
	return 0;
}