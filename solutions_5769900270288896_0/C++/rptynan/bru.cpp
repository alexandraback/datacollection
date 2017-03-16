#include <iostream>
using namespace std;
#define INF 1 << 30;


int N;
int R, C;
bool grid[20][20];


int dfs(int r, int c, int n, int tot) {

    if (r == 0 && c == C) {
        if (n != N) return INF;
        return tot;
        /* int count = 0; */
        /* for (int i = 0; i < R; i++) { */
        /*     for (int j = 0; j < C; j++) { */
        /*         /1* cout << grid[i][j]; //DEB *1/ */
        /*         if (!grid[i][j]) continue; */
        /*         if (i-1 >= 0) count += grid[i-1][j]; */
        /*         if (j-1 >= 0) count += grid[i][j-1]; */
        /*         /1* if (i+1 < R) count += grid[i+1][j]; *1/ */
        /*         /1* if (j+1 < C) count += grid[i][j+1]; *1/ */
        /*     } */
        /*     /1* cout << endl; //DEB *1/ */
        /* } */
        /* /1* cout << "*" << count << endl; //DEB *1/ */
        /* return count; */
    }

    int newr, newc;
    if (r == R-1) {
        newr = 0;
        newc = c+1;
    }
    else {
        newr = r+1;
        newc = c;
    }

    // place here
    grid[r][c] = 1;
    int newtot = tot + (r-1>=0 && grid[r-1][c]) + (c-1>=0 && grid[r][c-1]);
    int res1 = dfs(newr, newc, n+1, newtot);
    grid[r][c] = 0;
    // don't place here
    int res2 = dfs(newr, newc, n, tot);

    return min(res1, res2);
}



int main() {
    int TC;
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++) {

        cin >> R >> C >> N;
        int res = dfs(0, 0, 0, 0);

        cout << "Case #" << tc << ": " << res << endl;

    }
    return 0;
}
