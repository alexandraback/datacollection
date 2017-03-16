#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <valarray>

using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": "  << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template <class F, class S> ostream& operator << (ostream& o, const pair<F,S>& p) {
return o << "(" << p.first << ", " << p.second << ")";}

template<class C>void O__(ostream& o, const C& c) {
bool f = 1; for(const auto& x: c) {if (!f) o << ", "; f = 0; o << x;}}

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {o << "[";O__(o, v);o << "]";return o;}

template <class T, class V>
ostream& operator << (ostream& o, const map<T, V>& v) {o << "{";O__(o, v);o << "}"; return o;}

template <class T>
ostream& operator << (ostream& o, const set<T>& v) {o << "{";O__(o, v);o << "}";return o;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

void solveTest() {
    int n;
    cin >> n;
    vector<int> ptrs(n, 0);
    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    int res = 0;

    while(true) {
        for (int i = 0; i < n; ++i) {
            if (ptrs[i] >= s[i].length())
                goto stop;
        }
        for (int i = 0; i < n; ++i) {
            if (s[i][ptrs[i]] != s[0][ptrs[0]])
                goto stop;
        }
        char ch = s[0][ptrs[0]];
        vector<int> num(n);
        for (int i = 0; i < n; ++i) {
            while(ptrs[i] < s[i].size() && s[i][ptrs[i]] == ch) {
                ++ptrs[i];
                ++num[i];
            }
        }
        assert(*min_element(all(num)));
        int m = *max_element(all(num));
        int cur = INF;
        for (int r = 1; r <= m + 1; ++r) {
            int ans = 0;
            for (int i = 0; i < n; ++i) {
                ans += abs(num[i] - r);
            }
            cur = min(cur, ans);
        }
        res += cur;
    }
    stop:
    for (int i = 0; i < n; ++i)
        if (ptrs[i] != s[i].length()) {
            cout << "Fegla Won\n";
            return;
        }
    cout << res << "\n";
}

int main() {
    int tests;
    cin >> tests;
    for (int t = 0; t < tests; ++t) {
        cout << "Case #" << t + 1 << ": ";
        solveTest();
    }
    return 0;
}

