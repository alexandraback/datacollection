#include <bits/stdc++.h>
#define debug(x) cout << #x << " = " << x << endl;
#define INF 100000007
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int unhappiness(vector<vector<bool>> occ, int r, int c) {
    int res = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (!occ[i][j]) continue;
            if (i + 1 < r && occ[i + 1][j]) res++;
            if (j + 1 < c && occ[i][j + 1]) res++;
        }
    }
    return res;
}

int sharedWalls(vector<vector<bool>> occ, int r, int c, int cr, int cc) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        int nr = cr + dx[i], nc = cc + dy[i];
        if (nr >= 0 && nr < r && nc >= 0 && nc < c) {
            if (occ[nr][nc]) res++;
        }
    }
    return res;
}

int fill(int r, int c, int n, bool next) {
    vector<vector<bool>> occ(r, vector<bool>(c, false));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (n && (i + j) % 2 == next) {
                occ[i][j] = true;
                n--;
            }
        }
    }
    while (n) {
        int nr = -1, nc = -1, mn = INF;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (occ[i][j]) continue;
                int cnt = sharedWalls(occ, r, c, i, j);
                if (cnt < mn) {
                    nr = i;
                    nc = j;
                    mn = cnt;
                }
            }
        }
        if (nr == -1 || nc == -1) continue;
        occ[nr][nc] = true;
        n--;
    }
    return unhappiness(occ, r, c);
}

int main() {
    freopen("in", "r", stdin); freopen("out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int r, c, n;
        cin >> r >> c >> n;
        cout << "Case #" << t << ": ";
        cout << min(fill(r, c, n, true), fill(r, c, n, false));
        cout << endl;
    }
    return 0;
}
