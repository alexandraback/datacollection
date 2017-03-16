#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int dp[1 << 17];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
vector<int> v;

int solve(int n, int r, int c) {
    v.clear();
    v.resize(r * c);
    for (int i = 0; i < n; i++) {
        v[i] = 1;
    }
    sort(v.begin(), v.end());
    int res = -1;
    do {
        int cnt = 0;
        for (int i = 0; i < r * c; i++) {
            if (v[i] == 1) {
                int x = i / c;
                int y = i % c;
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    int p = nx * c + ny;
                    if (nx >= 0 && nx < r && ny >= 0 && ny < c) {
                        if (v[p] == 1) {
                            cnt++;
                        }
                    }
                }
            }
        }
        if (res == -1 || cnt < res) {
            res = cnt;
        }
    } while (next_permutation(v.begin(), v.end()));
    return res >> 1;
}

int t, n, r, c;
int cas = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(false);
    freopen("dat.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> t;
    while (t--) {
        cin >> r >> c >> n;
        cout << "Case #" << cas++ << ": " << solve(n, r, c) << "\n";
    }
}
