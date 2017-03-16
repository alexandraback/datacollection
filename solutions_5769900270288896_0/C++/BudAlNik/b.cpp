#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())

using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
const int MAXR = 10005;

int t;
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int field[MAXR][MAXR];

int main() {    
    //freopen(".in", "r", stdin);
    //freopen(".out", "w", stdout);

    cin >> t;

    for (int i = 0; i < t; ++i) {
        int r, c, n;
        cin >> r >> c >> n;
        int bdv = 1 << (r * c);
        int ans = r * c * 2 + 100500;
        for (int j = 0; j < bdv; ++j) {
            int tmp = j;
            int num = 0;
            for (int k = 0; k < r * c; ++k) {
                field[k % r][k / r] = tmp & 1;
                num += tmp & 1;
                tmp >>= 1;
            }
            if (num != n) {
                continue;
            }
            int now = 0;
            for (int k1 = 0; k1 < r; ++k1) {
                for (int k2 = 0; k2 < c; ++k2) {
                    for (int k = 0; k < 2; ++k) {
                        int nx = k1 + dx[k];
                        int ny = k2 + dy[k];
                        if (0 <= nx && nx < r && 0 <= ny && ny < c && field[nx][ny] && field[k1][k2]) {
                            ++now;
                        }
                    }
                }
            }
            ans = min(ans, now);
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }

    return 0;
}