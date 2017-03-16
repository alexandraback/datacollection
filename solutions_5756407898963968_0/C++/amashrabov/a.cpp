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

int main() {
#ifdef HOME
	freopen("small.txt", "r", stdin);
	freopen("res.txt", "w", stdout);
#endif // HOME
	int T;
    cin >> T;
    for1 (t, T)
    {
        cout << "Case #" << t << ": ";
        int r1, r2;
        cin >> r1; --r1;
        vi a, b;
        int n = 4;
        forn (i, n)
            forn (j, n)
            {
                int x;
                cin >> x;
                if (i == r1)
                    a.pb(x);
            }
        cin >> r2; --r2;
        forn (i, n)
            forn (j, n)
            {
                int x;
                cin >> x;
                if (i == r2)
                    b.pb(x);
            }
        vi c;
        for (int x: a)
        {
            if (find(all(b), x) != b.end())
                c.pb(x);
        }
        if (c.size() == 1)
            cout << c[0] << endl;
        if (c.size() > 1)
            cout << "Bad magician!" << endl;
        if (c.empty())
            cout << "Volunteer cheated!" << endl;
    }
    return 0;
}
