#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int t, r, c, n;

void solve(int num) {
    scanf("%d%d%d", &r, &c, &n);
    int a[20][20];
    memset(a, 0, sizeof a);
    int res = inf;
    for(int mask = 0; mask < (1<<(r * c)); mask++) {
        if(__builtin_popcount(mask) != n) continue;
        int cnt = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(mask&(1<<cnt)) a[i][j] = 1;
                else a[i][j] = 0;
                cnt++;
            }
        }
        int ans = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                ans += (a[i][j] && a[i][j+1]);
                ans += (a[i][j] && a[i+1][j]);
            }
        }
        res = min(res, ans);
    }
    printf("Case #%d: %d\n", num, res);
}

int main(){
    
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++) {
        solve(i);
    }
        
    return 0;
}
