#include <bits/stdc++.h>
using namespace std;

int T;
int R, C, N;
vector<vector<bool>> graph;
vector<vector<bool>> visit;
int res;

bool isValid(int x, int y) {
    if (x < 0 || x >= R || y < 0 || y >= C || visit[x][y])
        return false;
    return true;
}

int getVal() {
    int res = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (graph[i][j]) {
                if (i > 0 && graph[i-1][j]) ++res;
                if (j > 0 && graph[i][j-1]) ++res;
            }
        }
    }
    return res;
}

void dfs(int x, int y, int cnt) {
    if (cnt == N) {
        int tmp = getVal();
        res = min(res, tmp);
        return;
    }
    if (!isValid(x, y)) return;
    int xx[4] = { 1, 0, -1, 0};
    int yy[4] = { 0, 1, 0, -1};
    visit[x][y] = true;
    if (cnt == N) {
        int tmp = getVal();
        res = min(res, tmp);
        graph[x][y] = false;
        return;
    }
    for (int i = 0; i < 4; ++i) {
        dfs(x + xx[i], y + yy[i], cnt);
    }
    graph[x][y] = true;
    for (int i = 0; i < 4; ++i) {
        dfs(x + xx[i], y + yy[i], cnt + 1);
    }
    graph[x][y] = false;
    visit[x][y] = false;
}

void solve() {
    res = 1e9;
    dfs(0, 0, 0);
    cout << res << endl;
}

int main() {
    //freopen("b.in", "r", stdin);
    cin >> T;
    for (int caseID = 1; caseID <= T; ++caseID) {
        cin >> R >> C >> N;
        graph.assign(R, vector<bool>(C, false));
        visit.assign(R, vector<bool>(C, false));
        cout << "Case #" << caseID << ": ";
        solve();
    }
    return 0;
}
