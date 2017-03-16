#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <ctime>
using namespace std;

#define PII pair<int,int> 
#define MP make_pair
#define FI first
#define SE second
#define PB push_back
#define lid (id << 1)
#define rid (id << 1 | 1)
#define MID(a, b) ((a + b) >> 1)

const int N = 1010;
const int INF = 1000000000;
const int Mod = 1000000007;
const int maxn = 10;
const double PI = acos(-1.0);
const double eps = 1e-6;

int mp[20][20];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m, K;
int ans, tot;

void dfs(int k, int chose) {
    if(chose > K) return;
    if(k == n * m) {
        if(chose < K) return;
        int cc = 0, tt = 0;
        for(int i= 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mp[i][j]) {
                    tt |= 1 << (i * m + j);
                    for(int k = 0; k < 4; k++) {
                        int tx = i + dx[k], ty = j + dy[k];
                        if(tx >= 0 && tx < n && ty >= 0 && ty < m) {
                            cc += mp[tx][ty];
                        }
                    }
                }
            }
        }
        if(cc < ans) {
            ans = cc; tot = tt;
        }
        return;
    }
    int x = k / m, y = k % m;
    mp[x][y] = 1; dfs(k + 1, chose + 1);
    mp[x][y] = 0; dfs(k + 1, chose);
}

void solve() {
    scanf("%d%d%d", &n, &m, &K);
    memset(mp, 0, sizeof(mp));
    ans = INF;
    dfs(0, 0);
    printf("%d\n", ans / 2);
}

int main() {
    freopen("B1.in", "r", stdin);
    freopen("B1.out", "w", stdout);
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}