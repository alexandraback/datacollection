#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<char, int> > get(string a) {
    vector<pair<char, int> > res;
    for (int i = 0; i < a.size(); ++i) {
        int j = i + 1;
        while (j < a.size() && a[j] == a[i]) j++;
        res.push_back(make_pair(a[i], j - i));
        i = j - 1;
    }
    return res;
}

const int maxn = 111;

string a[maxn];
vector<pair<char, int> > v[maxn];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        v[i] = get(a[i]);
    }
    int std = v[0].size();
    for (int i = 0; i < n; ++i) {
        if (v[i].size() != std) {
            cout << "Fegla Won" << endl;
            return;
        }
    }
    int ans = 0;
    for (int i = 0; i < v[0].size(); ++i) {
        char std = v[0][i].first;
        vector<int> nums;
        for (int j = 0; j < n; ++j) {
            if (v[j][i].first != std) {
                cout << "Fegla Won" << endl;
                return;
            }
            nums.push_back(v[j][i].second);
        }
        sort(nums.begin(), nums.end());
        for (int j = 0; j < n; ++j) {
            ans += abs(nums[j] - nums[j / 2]);
        }
    }
    cout << ans << endl;
}

int main() {
    int testCount;
    cin >> testCount;
    for (int testId = 1; testId <= testCount; ++testId) {
        printf("Case #%d: ", testId);
        solve();
    }
}
