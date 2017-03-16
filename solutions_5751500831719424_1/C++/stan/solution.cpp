#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
#include <limits>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

template<typename T>
inline int popcount(T t) {
    if (std::numeric_limits<T>::digits <=
                            std::numeric_limits<unsigned int>::digits) {
        return __builtin_popcount(t);
    } else {
        return __builtin_popcountll(t);
    }
}

const ld EPS = 1e-8;
const ld PI = acosl(0.0) * 2;

string normalized(const string& s)
{
    string ret;
    forv(i, s) {
        if (i == 0 || s[i] != s[i - 1]) {
            ret += s[i];
        }
    }
    return ret;
}

const int INF = 1e8;

string solveInternal()
{
    int n;
    cin >> n;
    vector<string> w(n);
    forn(i, n) cin >> w[i];
    string norm = normalized(w[0]);
    for1(i, n - 1) {
        if (norm != normalized(w[i])) return "Fegla Won";
    }
    //cerr << norm << endl;
    vi pos(n);
    int ans = 0;
    for (char c : norm) {
        //cerr << c << endl;
        vi cnt(n);
        int mx = 0;
        forn(i, n) {
            cnt[i] = 1;
            assert(w[i][pos[i]] == c);
            int r = pos[i] + 1;
            while (r < w[i].size() && w[i][r] == c) ++r, ++cnt[i];
            mx = max(mx, cnt[i]);
            //cerr << r << endl;
            pos[i] = r;
        }
        //cerr << mx << endl;
        int pen = INF;
        for1(len, mx) {
            int cc = 0;
            forn(i, n) cc += abs(cnt[i] - len);
            pen = min(cc, pen);
        }
        ans += pen;
    }
    ostringstream os;
    os << ans;
    return os.str();
}

void solve()
{
    int tc;
    cin >> tc;
    forn(it, tc) {
        cout << "Case #" << it + 1 << ":";
        cout << " " << solveInternal() << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
