#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long LL;
int n, r, c, select[16], unhappy;

inline bool inside(int x, int y) {
    return 0 <= x && x < r && 0 <= y && y < c;
}

void DFS(int k, int idx) {
    if (k == n) {
        vector<bool> room(r * c, false);
        for (int i = 0; i < n; ++i) {
            room[select[i]] = true;
        }
        int cnt = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) if (room[i * c + j]){
                if (inside(i + 1, j) && room[(i + 1) * c + j]) {
                    ++ cnt;
                }
                if (inside(i, j + 1) && room[i * c + j + 1]) {
                    ++ cnt;
                }
            }
        }
        if (cnt < unhappy) unhappy = cnt;
        return ;
    }
    for (int i = idx; i <= r * c - (n - k); ++i) {
        select[k] = i;
        DFS(k + 1, i + 1);
    }
}
void solve() {
    cin >> r >> c >> n;
    unhappy = r * c * 4;
    DFS(0, 0);
    cout << unhappy << endl;
}
int main() {
    
    int testcase;
    freopen("/Volumes/Data/download/B-small-attempt0.in", "r", stdin);
    freopen("/Volumes/Data/download/out.txt", "w", stdout);

    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}
