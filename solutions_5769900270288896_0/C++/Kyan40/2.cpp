#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("B-small-attempt0.in");
ofstream fout("output.txt");

int main(int argc, const char * argv[]) {
    int t, n, r, c;
    fin >> t;
    for (int ti = 1; ti <= t; ti ++) {
        fin >> r >> c >> n;
        int ans = 2e9;
        int g[r][c];
        for (int x = 0; x < (1 << (r * c)); ++ x){
            int cnt = 0;
            for (int i = 0; i < (r * c); ++ i) {
                if ((x & (1 << i)) != 0) cnt ++;
            }
//            cout << x << " " << cnt << endl;
            if (cnt != n) continue;
            int tans = 0;
            for (int i = 0; i < r; i ++ ) {
                for (int j = 0; j < c; j ++) {
                    g[i][j] = (x & (1 << (i * c + j))) != 0 ? 1 : 0;
                }
            }
            for (int i = 0; i < r - 1; i ++) {
                for (int j = 0; j < c; j ++){
                    if (g[i][j] + g[i+1][j] == 2) tans ++;
                }
            }
            for (int i = 0; i < r; i ++) {
                for (int j = 0; j < c - 1; j ++){
                    if (g[i][j] + g[i][j+1] == 2) tans ++;
                }
            }
//            cout << "tans" << tans << endl;
            ans = min(ans, tans);
        }
        fout << "Case #" << ti << ": " << ans << endl;
    }
    return 0;
}
