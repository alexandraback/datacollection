#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
#define rep(i,n) for (int i = 0; i < int(n); i++)
const int inf = 1e9;

int W, H, N;
int c, a[16][16];

void dfs(int i = 0, int x = 0, int y = 0) {
    if (i < N) {
        if (!(x < W && y < H)) return;
        int nx, ny;
        if (x+1 < W) { nx = x+1; ny = y; }
        else { nx = 0; ny = y+1; }
        a[x][y] = 1; dfs(i+1, nx, ny);
        a[x][y] = 0; dfs(i  , nx, ny);
    } else {
        int d = 0;
        rep (i,W-1) rep (j,H) if (a[i][j] == 1 && a[i+1][j] == 1) d++;
        rep (i,W) rep (j,H-1) if (a[i][j] == 1 && a[i][j+1] == 1) d++;
        c = min(c, d);
    }
}
            

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        c = inf;
        rep (i,16) rep (j,16) a[i][j] = 0;
        cin >> H >> W >> N;
        dfs();
        cout << "Case #" << t << ": " << c << endl;
    }
}
