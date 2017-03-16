#include <iostream>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <map>
#include <algorithm>
#include <set>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
#define prev qwerty
vector < int > arr[100005];
int n, m, val;
int cnt[105][105];
int c1[105][10005];
int c2[105][10005];
int ans = 0;
int sol() {
    int va = val;
    for (int i = 0; i < n; ++i){
        arr[i].clear();
        for (int j = 0; j < m; ++j)
            arr[i].push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (va > 0) {
                if ((i + j) % 2 == 0) {
                    arr[i][j] = 1;
                    va--;
                }
            }
        }
    }

    if (va == 0) {
        return 0;
    }
    vector < int > ret;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (arr[i][j] == 1) continue;
            int cur = 0;
            for (int dx = -1; dx <= 1; ++dx)
                for (int dy = -1; dy <= 1; dy++) {
                    if (abs(dx) + abs(dy) != 1) continue;
                    int x = i + dx, y = j + dy;
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    cur += arr[x][y];
                }
            ret.push_back(cur);
        }
    }
    int answer = 0;
    sort(ret.begin(), ret.end());
    for (int i = 0; i < va; ++i) {
        answer += ret[i];
    }

    return answer;
}

bool bit(int mask, int x) {
    mask &= (1 << x);
    return mask > 0;
}

int get() {
    int answer = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (!arr[i][j]) continue;
            if (i + 1 < n && arr[i + 1][j]) answer++;
            if (j + 1 < m && arr[i][j + 1]) answer++;
        }
    return answer;
}
const int inf = 1000000000;
int f(int mask) {
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if (bit(mask, i) && bit(mask, i - 1)) ans++;
    }
    return ans;
}

int f(int m1, int m2) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (bit(m1, i) && bit(m2, i)) ans++;
    }
    return ans;
}
int all;
int bits[1005];
int run() {
    all = n * m;
    for (int i = 0; i < (1 << n); ++i) {
        for (int j = 0; j <= all; ++j) {
            c1[i][j] = inf;
            c2[i][j] = inf;
        }
    }
    for (int i = 0; i < (1 << n); ++i) {
        bits[i] = 0;
        for (int j = 0; j < n; ++j)
            bits[i] += bit(i, j);
    }
    c1[0][0] = 0;
    for (int i = 0; i < (1 << n); ++i)
        for (int j = 0; j < (1 << n); ++j) {
            cnt[i][j] = f(j) + f(i, j);
        }
    all = n * m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (1 << n); ++j) {
            for (int v = 0; v <= val; ++v) {
                if (c1[j][v] == inf) continue;
                if ((m - i) * n + v < val) continue;
                for (int c = 0; c < (1 << n); ++c) {
                    c2[c][v + bits[c]] = min(c2[c][v + bits[c]], c1[j][v] + cnt[j][c]);
                }
            }
        }

        for (int j = 0; j < (1 << n); ++j) {
            for (int v = 0; v <= val; ++v) {
                c1[j][v] = c2[j][v];
                c2[j][v] = inf;
            }
        }
    }

    int ans = inf;
    for (int i = 0; i < (1 << n); ++i) {
        ans = min(ans, c1[i][val]);
    }
    return ans;
}
void solve() {
    cin >> n >> m >> val;
    int all = n * m;
    for (int i = 0; i < n; ++i) {
        arr[i].clear();
        for (int j = 0; j < m; ++j) arr[i].push_back(0);
    }
    ans = sol();
    if (n > m) swap(n, m);
    if (n > 6 || m > 300) {
        cout << ans << endl;
        return;
    }
    int res = run();
    ans = min(ans, res);
    cout << ans << endl;
}
int main(){
    freopen("input.txt","r",stdin);
   //    freopen("/home/furko/Downloads/A-small-attempt0.in", "r", stdin);
    //freopen("/home/furko/Downloads/A-small-attempt0.out", "w", stdout);
    freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}
