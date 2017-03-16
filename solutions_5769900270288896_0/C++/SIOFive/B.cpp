/*
ID: wuqi9395@126.com
PROG:
LANG: C++
*/
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<fstream>
#include<cstring>
#include<ctype.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define INF (1 << 30)
#define LINF (1LL << 60)
#define PI acos(-1.0)
#define mem(a, b) memset(a, b, sizeof(a))
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define eps 1e-6
#define debug puts("===============")
#define pb push_back
#define mkp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define POSIN(x,y) (0 <= (x) && (x) < r && 0 <= (y) && (y) < c)
typedef long long ll;
typedef unsigned long long ULL;
int t, n, r, c, m;
int mx = INF;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void work(int x) {
    //cout<<x<<endl;
    int a[20][20] = {0};
    for (int j = 0; j < m; j++) if (x & (1 << j)) {
        a[j / c][j % c] = 1;
    }
    int s = 0;
//    for (int i = 0; i < r; i++) {
//        for (int j = 0; j < c; j++) {
//            cout<<a[i][j];
//        }
//        cout<<endl;
//    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) if (a[i][j]){
            for (int l = 0; l < 4; l++) {
                int x = i + dx[l], y = j + dy[l];
                if (POSIN(x, y) && a[x][y]) s++;
            }
        }
    }
    s /= 2;
    mx = min(s, mx);
}
int main () {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("2.out", "w", stdout);
    cin>>t;
    for (int cas = 1; cas <= t; cas++) {
        scanf("%d%d%d", &r, &c, &n);
        mx = INF;
        m = r * c;
        int tot = (1 << m);
        for (int i = 0; i < tot; i++) {
            int s = 0;
            for (int j = 0; j < m; j++) if (i & (1 << j)) s++;
            if (s != n) continue;
            work(i);
        }
        printf("Case #%d: %d\n", cas, mx);
    }
    return 0;
}
