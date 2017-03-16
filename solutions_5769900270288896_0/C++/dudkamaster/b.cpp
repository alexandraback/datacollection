# define _USE_MATH_DEFINES
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <fstream>
#include <iostream>
#include <map>
#include <memory.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()

#define forn(i,n) for (int i=0; i<int(n); ++i)

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;


const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;

int n,r,c;
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

void read(){
    scanf("%d%d%d", &r, &c, &n);
}

void solve(){
    int ans = INF;
    forn(mask, (1 << (r*c))) {
        int cnt = 0;
        forn(j, r*c)
            if ((1 << j) & mask)
                cnt++;
        if (cnt != n) continue;
        int unh = 0;
        forn(row, r) {
            forn(col, c) {
                if ((1 << (row*c + col)) & mask) {
                    forn(dir, 4) {
                        int nr, nc;
                        nr = row + dx[dir];
                        nc = col + dy[dir];
                        if (nr >=0 && nr < r && nc >=0 && nc < c && ((1 << (nr*c + nc)) & mask))
                            unh++;
                    }
                }

            }
        }
        unh /= 2;
        ans = min(ans, unh);
    }
    printf("%d\n", ans);
}

int main(){
#ifdef dudkamaster
    freopen("input.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    int test_cases;
    scanf("%d", &test_cases);
    for (int test = 1; test <= test_cases; test++) {
        read();
        printf("Case #%d: ", test);
        solve();
    }
    return 0;
}
