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
    for(int _ = 1; _ <= T; _++) {
        int b, n;
        cin >> b >> n;
        int m[1005];
        for(int i = 0; i < b; i++) {
            cin >> m[i];
        }
        int can[1005];
        for(int i = 0; i < b; i++) {
            can[i] = 0;
        }
        int ans = -1;
        vector <int> loop;
        bool found = false;
        map < vector<int>, bool > M;
        for(int k = 1; k <= n; k++) {
            bool flag = false;
            int chosen = -1;
            for(int i = 0; i < b; i++) {
                if(can[i] == 0) {
                    can[i] = m[i];
                    chosen = i;
                    flag = true;
                    break;
                }
            }
            if(!flag) {
                int minn = 100001;
                for(int i = 0; i < b; i++) {
                    if(minn > can[i]) {
                        minn = can[i];
                    }
                }
                for(int i = 0; i < b; i++) {
                    can[i] -= minn;
                }
                for(int i = 0; i < b; i++) {
                    if(can[i] == 0) {
                        can[i] = m[i];
                        chosen = i;
                        flag = true;
                        break;
                    }
                }
            }
            vector <int> order(b);
            for(int i = 0; i < b; i++) {
                order[i] = can[i];
            }
            if(M.find(order) == M.end()) {
                M[order] = true;
                loop.push_back(chosen);
            } else {
                found = true;
                break;
            }
            /*if(loop.size() % 2 == 0) {
                int biu = loop.size() / 2;
                bool mark = true;
                for(int i = 0; i < biu; i++) {
                    if(loop[i] != loop[i+biu]) {
                        mark = false;
                    }
                }
                if(mark) {
                    found = true;
                }
            }
            if(found) {
                break;
            }*/
            /*cout << k << ": ";
            for(int i = 0; i < b; i++) {
                cout << can[i] << ' ';
            } cout << endl;*/
            if(k == n) ans = chosen;
        }
        int mod = loop.size();
        /*for(int i = 0; i < mod * 2; i++) {
            cout << loop[i] << ' ';
        } cout << endl;*/
        int temp = (n-1) % mod;
        printf("Case #%d: %d\n", _, loop[temp] + 1);
    }
}
