#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;
void pre_calc() {}
int calc(int k, int n, int m) {
    int ret = 0;
    vector<vector<int>> color(n, vector<int>(m));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            color[i][j] = ((k >> (i * m + j)) & 1);
            //cout << color[i][j] << " ";
        } //cout << endl;
    }
    //cout << "========="<<endl;
    int d[4][2] = { {1, 0},  {0, 1}, {-1, 0}, {0, -1}};
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if (color[i][j] == 0) continue;
            for(int k = 0; k < 4; k ++) {
                int x = i + d[k][0];
                int y = j + d[k][1];
                if (x < 0 || x >= n || y < 0 || y >= m) continue;
                ret += color[x][y];
            }
            //cout << i << " " << j << " " << ret << endl;
        }
    }
    return ret / 2;
}
void solve(int ncase) {
    int r, c, n;
    cin >> r >> c >> n;
    int N = r * c;
    int ret = 4 * N;
    for(int i = 0; i < (1 << N); i ++) {
        if (__builtin_popcount(i) == n) {
            ret = min(ret, calc(i, r, c));
        }
    }
    cout << "Case #" << ncase << ": " << ret << endl;
}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    pre_calc();
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
