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
/*
void solve() {
    cin >> n >> m >> val;

    for (int i = 0; i < n; ++i){
        arr[i].clear();
        for (int j = 0; j < m; ++j)
            arr[i].push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (val > 0) {
                if ((i + j) % 2 == 0) {
                    arr[i][j] = 1;
                    val--;
                }
            }
        }
    }

    if (val == 0) {
        cout << 0 << endl;
        return;
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
    for (int i = 0; i < val; ++i) {
        answer += ret[i];
    }

    cout << answer << endl;
}*/

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

void solve() {
    cin >> n >> m >> val;
    int all = n * m;
    int ans = 100000;
    for (int i = 0; i < n; ++i) {
        arr[i].clear();
        for (int j = 0; j < m; ++j) arr[i].push_back(0);
    }
    for (int mask = 0; mask < (1 << all); ++mask) {
        int counter = 0, num = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                if (bit(mask, counter)) arr[i][j] = 1;
                else arr[i][j] = 0;
                num += bit(mask, counter);
                counter++;
            }
        if (num != val) continue;
        int ret = get();
        ans = min(ans, ret);
    }
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
