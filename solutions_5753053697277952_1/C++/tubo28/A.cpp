#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
#include <cassert>
#include <array>
#include <tuple>
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <forward_list>

using namespace std;
#define all(c) begin(c), end(c)
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;
using pii = pair<int, int>;
#define VV(T) vector<vector<T>>

int n;
vector<int> a;

bool ok(vector<pair<int,char>> A) {
    sort(all(A));
    reverse(all(A));

    int sum = 0;
    rep(i, A.size()) {
        sum += A[i].first;
    }
    int ma = max_element(all(A))->first;

    return ma * 2 <= sum;
}

vector<string> solve() {
    int rem = 0;
    rem += accumulate(all(a), 0);
    vector<pair<int, char>> A(n);
    rep(i, n) {
        A[i] = make_pair(a[i], 'A' + i);
    }

    vector<string> res;
    while (rem) {
        sort(all(A));
        reverse(all(A));

        string del;

        del.push_back(A[0].second);
        --A[0].first;
        --rem;

        if (!ok(A)) {
            sort(all(A));
            reverse(all(A));

            del.push_back(A[0].second);
            --A[0].first;
            --rem;
        }

        res.push_back(del);
        assert(ok(A));

        //for (auto &e : A) {
        //    for (int i = 0; i < e.first; ++i) cout << e.second;
        //}
        //cout << endl;
    }

    return res;
}

int main() {
    int T;
    cin >> T;
    rep(it, T) {
        cin >> n;
        a.resize(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        auto ans = solve();

        cout << "Case #" << it + 1 << ':';
        int len = ans.size();
        for (int i = 0; i < len; ++i) {
            cout << ' ' << ans[i];
        }
        cout << endl;
    }
}
