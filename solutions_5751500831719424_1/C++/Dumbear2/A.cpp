/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t, n;
vector<pair<char, int> > vec[128];

void process(int id) {
    string s;
    cin >> s;
    vec[id].clear();
    for (int i = 0; i < s.size(); ++i) {
        if (vec[id].empty() || s[i] != vec[id].back().first) {
            vec[id].push_back(make_pair(s[i], 1));
        } else {
            ++vec[id].back().second;
        }
    }
}

int get_min_steps() {
    for (int i = 1; i < n; ++i) {
        if (vec[i].size() != vec[0].size())
            return -1;
    }
    int res = 0;
    for (int i = 0; i < vec[0].size(); ++i) {
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            if (vec[j][i].first != vec[0][i].first)
                return -1;
            v.push_back(vec[j][i].second);
        }
        sort(v.begin(), v.end());
        int k = v[v.size() / 2];
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            cnt += abs(v[j] - k);
        }
        res += cnt;
    }
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        process(i);
    }
    int res = get_min_steps();
    if (res == -1) {
        printf("Case #%d: Fegla Won\n", ++t);
    } else {
        printf("Case #%d: %d\n", ++t, res);
    }
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
