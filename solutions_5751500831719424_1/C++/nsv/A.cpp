#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }

// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"

pair<string, vi> zip(string s)
{
    s += '#';

    vi v;
    string r;
    int pos = 0;
    forn(i, s.length())
    {
        if (i > 0 && s[i - 1] != s[i])
        {
            r += s[i - 1];
            v.push_back(i - pos);
            pos = i;
        }
    }

    return mp(r, v);
}

void test()
{
    string s = "abbcca";
    dbg(zip(s).X);
    dbg(zip(s).Y);
    exit(0);
}

void solve(int test)
{
    int n; cin >> n;
    vector<string> a(n);
    cin >> a;
    
    vector<string> ss(n);
    vvi lens(n);
    forn(i, n)
    {
        auto tmp = zip(a[i]);
        ss[i] = tmp.X;
        lens[i] = tmp.Y;
    }
    
    cout << "Case #" << test << ": ";
    forn(i, n - 1)
        if (ss[i] != ss[i + 1])
        {
            cout << "Fegla Won" << endl;
            return;
        }

    int res = 0;
    forn(i, lens[0].size())
    {
        vi t;
        forn(j, n)
            t.push_back(lens[j][i]);

        int mn = *min_element(all(t));
        int mx = *max_element(all(t));

        int mn_cur = -1;
        for (int z = mn; z <= mx; ++z)
        {
            int cur = 0;
            forn(j, t.size())
                cur += abs(t[j] - z);

            if (mn_cur == -1 || cur < mn_cur)
                mn_cur = cur;
        }

        mn_cur = max(0, mn_cur);
        res += mn_cur;
    }

    cout << res << endl;
}

int main()
{
    //test();
    START
    // freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("A-large.in", "r", stdin);  freopen("output.txt", "w", stdout);
 
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    forn(i, t)
        solve(i + 1);

    END
    return 0;
}
/*******************************************
*******************************************/

template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif