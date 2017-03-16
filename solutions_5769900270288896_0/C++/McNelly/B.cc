#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <bitset>
#include <map>
#include <set>

using namespace std;

#define print(x) cout<<x<<endl
#define input(x) cin>>x

const int SIZE = 20;
const int INF = 0x3f3f3f3f;

const int mx[] = {0, 1, 0, -1};
const int my[] = {-1, 0, 1, 0};

int n, m, p;
int ans = 0;

int g[SIZE][SIZE];

void solve(int bin, int p) {
    int cnt = 0;
    memset(g, 0, sizeof(g));
    for (int i = 0; i < (n * m); i++) {
        if (bin & (1 << i)) {
            cnt++;
            g[i / m][i % m] = 1;
        }
    }
    if (cnt != p) {
        return;
    }
    
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            //printf("%d ", g[i][j]);
            if (g[i][j] == 0) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int ny = i + my[k];
                int nx = j + mx[k];
                
                if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
                    continue;
                }
                
                if (g[ny][nx]) {
                    res++;
                }
            }
        }
        //puts("");
    }
    //puts("---");
    //print(res / 2);
    ans = min(ans, res / 2);
}

int main() {
    //freopen("B.txt", "r", stdin);
    int T;
    int ca = 1;
    input(T);
    while (T--) {
        ans = INF;
        input(n >> m >> p);
        for (int i = 0; i < 1 << (n * m); i++) {
            solve(i, p);
        }
        printf("Case #%d: %d\n", ca++, ans);
    }
    return 0;
}
