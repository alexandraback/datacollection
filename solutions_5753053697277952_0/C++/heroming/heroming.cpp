/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2016/5/8 16:51:44
 */
#include <vector>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#define px first
#define py second
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define clr(v, e) memset(v, e, sizeof(v))
#define rep(it, v) for (auto it : v)
#define forn(i, n) for (int i = 0; i < (n); ++ i)
#define rforn(i, n) for (int i = (n) - 1; i >= 0; -- i)
#define form(i, a, b) for (int i = (a); i <= (b); ++ i)
#define rform(i, a, b) for (int i = (b); i >= (a); -- i)
#define forv(i, v) for (int i = 0; i < sz(v); ++ i)
#define iter(it, v) for (auto it = v.begin(); it != v.end(); ++ it)

typedef long long lint;
typedef vector<int> vint;
typedef vector<string> vstring;
typedef pair<int, int> pint;
typedef vector<lint> vlint;
typedef vector<pint> vpint;

const int maxn = 32;

int t, n;
int v[maxn];

int main() {
    freopen("heroming.out", "w", stdout);
    scanf("%d", &t);
    form (cas, 1, t) {
        printf("Case #%d:", cas);
        scanf("%d", &n);
        int s = 0;
        forn (i, n) {
            scanf("%d", &v[i]);
            s += v[i];
        }
        int m;
        vint ve;
        while (1) {
            m = -1;
            ve.clear();
            forn (i, n) {
                if (v[i] > 0) {
                    if ( m < v[i]) {
                        m = v[i];
                        ve.clear();
                        ve.pb(i);
                    } else if (m == v[i]) {
                        ve.pb(i);
                    }
                }
            }
            if (ve.empty()) break;
            
            if (sz(ve) == 1) {
                -- v[ve[0]];
                printf(" %c", char('A' + ve[0]));
                -- s;
            } else {
                if (s == 3) {
                    -- v[ve[0]];
                    printf(" %c", char('A' + ve[0]));
                    -- s;
                } else {
                    -- v[ve[0]];
                    printf(" %c", char('A' + ve[0]));
                    -- v[ve[1]];
                    printf("%c", char('A' + ve[1]));
                    s -= 2;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
