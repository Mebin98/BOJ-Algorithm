#include <iostream>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

int main() {
	int k, l;
	map<string, int> ID;

	cin >> k >> l;

	string student_id;
	for (int i = 0; i < l; i++) {
		cin >> student_id;
		ID[student_id] = i;
	}

    // 맵의 쌍을 벡터에 저장
    vector<pair<string, int>> pairs;
    for (const auto& kv : ID) {
        pairs.push_back(kv);
    }

    // 두 번째 요소 (value)를 기준으로 정렬
    sort(pairs.begin(), pairs.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
        return a.second < b.second;
        });

    for (int i = 0; i < min(k, static_cast<int>(pairs.size())); i++) {
        cout << pairs[i].first << "\n";
    }

    return 0;
}