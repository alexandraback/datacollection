#include <bits/stdc++.h>
using namespace std;
int main() {
    int TC; cin >> TC;
    for (int tc = 1; tc <= TC; ++tc) {
        int N; cin >> N;
        vector<int> nums(N);
        for (int &i : nums) cin >> i;
        cout << "Case #" << tc << ":";
        vector<pair<int, int>> tmp;
        for (int i = 0; i < N; ++i) {
            tmp.push_back(make_pair(nums[i], i));
        }
        while (true) {
            sort(tmp.begin(), tmp.end());
            if (tmp.back().first == 0) break;
            if (tmp.size() > 2 && tmp.back().first == tmp[N-2].first && tmp[N-3].first == tmp[N-2].first && tmp[N-1].first == 1) {
                cout << " " << (char)('A'+tmp[N-1].second);
                tmp[N-1].first--;
            }
            else if (tmp.back().first == tmp[N-2].first) {
                cout << " " << (char)('A'+tmp[N-1].second) << (char)('A'+tmp[N-2].second);
                tmp[N-2].first--;
                tmp[N-1].first--;
            } else {
                cout << " " << (char)('A'+tmp[N-1].second);
                tmp[N-1].first--;
            }
        }
        cout << endl;
    }
    return 0;
}