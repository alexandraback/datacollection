/* base IO */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <fstream>
#include <sstream>

/* data structure */
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <bitset>

/* alrotihm and math */
#include <algorithm>
#include <random>
#include <cmath>

/* run-time */
#include <cstdlib>
#include <ctime>
#include <climits>

/* system dependent */
#include <sys/time.h>

using namespace std;

#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define PDD pair<double, double>
#define PB push_back
#define MP make_pair
#define len(x) ((x).size())

const int inf = INT_MAX;
const long long inf_ll = 0x7f7f7f7f;
const double eps = 1e-8;

/*
 * 0 1 2
 * 3   4
 * 5 6 7
 */
const int bfs_dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int bfs_dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};

/*
 *   3  
 * 2   0
 *   1  
 */
const int dfs_dy[] = {0, 1, 0, -1};
const int dfs_dx[] = {1, 0, -1, 0};

PII dir[] = {make_pair(0,1),make_pair(1,0),make_pair(0,-1),make_pair(-1,0)};
/* TC HEADER END */

int main() {
    int T;
    cin >> T;
    bool m[16][16] = {false};
    for(int _ = 1; _ <= T; _++) {
        int r, c, n;
        cin >> r >> c >> n;
        int _n = r * c;
        int ans = -1;
        for(int i = 0; i < (1 << _n); i++) {
            int cnt = 0;
            for(int j = 0; j < r * c; j++) {
                if((i >> j) & 1) {
                    cnt++;
                }
            }
            memset(m, false, sizeof(m));
            if(cnt != n) {
                continue;
            }
            for(int j = 0; j < r * c; j++) {
                int _i = j / c, _j = j % c;
                if((i >> j) & 1) {
                    m[_i][_j] = true;
                }
            }
            int temp = 0;
            for(int i = 0; i < r; i++) {
                for(int j = 0; j < c; j++) {
                    if(m[i][j] == true) {
                        if(i < r - 1 && m[i+1][j] == true) {
                            temp ++;
                        }
                        if(j < c - 1 && m[i][j+1] == true) {
                            temp ++;
                        }
                    }
                }
            }
            if(ans == -1 || ans > temp) {
                /*for(int i = 0; i < r; i++) {
                    for(int j = 0; j < c; j++) {
                        cout << m[i][j] << ' ';
                    } cout << endl;
                }*/
                ans = temp;
            }
        }
        printf("Case #%d: %d\n", _, ans);
    }
    return 0;
}
