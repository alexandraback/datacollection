#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <numeric>
#include <bitset>
#include <vector>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <functional>
#include <cstring>
#include <ctime>
#include <memory.h>

#define y1 AAA_BBB
#define y0 AAA_AAA

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = (int)(a); i <= (int)(b); ++i)
#define for1(i, n) for(int i = 1; i <= (int)(n); ++i)
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v.size()))

using namespace std;

typedef long long i64;
typedef unsigned long long u64;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpi;

template <class T> T inline sqr(T x) {
    return x * x;
}

const ld pi = 3.1415926535897932384626433832795;
const ld eps = 1e-8;

#define TEST "small"

vector<pair<char, int> > f(const string& t)
{
    vector<pair<char, int> > res;
    for (auto it = t.begin(); it != t.end();)
    {
        auto j = it;
        while (j != t.end() && *it == *j)
            j++;
        res.pb(mp(*it, j - it));
        it = j;
    }
    return res;
}

int g(vi a)
{
    sort(all(a));
    int res = 1e9;
    forn (i, a.size())
    {
        int c = 0;
        forn (j, a.size())
            c += abs(a[j] - a[i]);
        res = min(res, c);
    }
    return res;
}

int solve()
{
    int n;
    cin >> n;
    vector<string> s(n);
    forn (i, n)
    {
        cin >> s[i];
    }
    vector<vector<pair<char, int> >> r(n);
    forn (i, n)
    {
        r[i] = f(s[i]);
    }
    forn (i, n)
    {
        if (r[i].size() != r[0].size()) return -1;
        forn (j, r[0].size())
            if (r[0][j].fi != r[i][j].fi) return -1;
    }
    int ans = 0;
    forn (j, r[0].size())
    {
        vi a(n);
        forn (i, n)
            a[i] = r[i][j].se;
        ans += g(a);
    }
    return ans;
}

int main() {
#ifndef TEST
	freopen("input.txt", "r", stdin);
#else 
    freopen(TEST".in", "r", stdin);
    freopen(TEST".out", "w", stdout);
#endif
    int T;
    cin >> T;
    for1 (t, T)
	{
		cout << "Case #" << t << ": ";
	    int x = solve();
        if (x == -1)
            cout << "Fegla Won\n";
        else
            cout << x << "\n";
    }
	return 0;
}
