#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int compute_day(int month) {
    if (month == 1) return 0;
    if (month == 2) return 31;
    if (month == 3) return (31 + 28);
    if (month == 4) return (31 + 28 + 31);
    if (month == 5) return (31 + 28 + 31 + 30);
    if (month == 6) return (31 + 28 + 31 + 30 + 31);
    if (month == 7) return (31 + 28 + 31 + 30 + 31 + 30);
    if (month == 8) return (31 + 28 + 31 + 30 + 31 + 30 + 31);
    if (month == 9) return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31);
    if (month == 10) return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
    if (month == 11) return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
    if (month == 12) return (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
}

bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
    int n;
    vector<pair<int, int>> flower;

    cin >> n;
    int a, b, c, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        int s_temp = b, d_temp = d;
        s_temp += compute_day(a);
        d_temp += compute_day(c);
        flower.push_back({ s_temp, d_temp });
    }

    int princessStart = 1 + compute_day(3);
    int princessDone = 30 + compute_day(11);

    sort(flower.begin(), flower.end(), customComparator);
    auto it = unique(flower.begin(), flower.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first == b.first;
        });
    flower.erase(it, flower.end());

    int mid = princessStart;
    int start = 0;
    int max = -1;
    int max_idx = -1;
    bool update = false;
    int ans = 0;
    int cnt = 0;
  
    while (mid <= princessDone) {
        for (int i = start; i < flower.size(); i++) {
            if (mid >= flower[i].first && mid < flower[i].second) { // 사이에 있을 경우 
                if (flower[i].second > max) {
                    max = flower[i].second;
                    max_idx = i;
                    update = true;
                }
            }
        }
        if (update) {
            ans += 1;
        }
        mid = max;
        update = false;
        cnt++;
        if (cnt == flower.size()) break;
    }
    if (mid <= princessDone) {
        cout << 0 << "\n";
        return 0;
    }

    cout << ans << "\n";

    return 0;
}