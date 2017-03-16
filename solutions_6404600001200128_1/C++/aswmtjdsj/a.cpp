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
        int n;
        cin >> n;
        int a[1005];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans1 = 0, ans2 = 100000000;
        for(int i = 1; i < n; i++) {
            if(a[i] < a[i-1]) {
                ans1 += a[i-1] - a[i];
            }
        }

        for(int value = 10000; value >= 0; value--) {
            int cnt = 0;
            bool flag = true;
            for(int i = 0; i < n - 1; i++) {
                if(a[i] <= value) {
                    cnt += a[i];
                } else {
                    if(a[i] < a[i+1]) {
                        cnt += value;
                    } else {
                        if(a[i] - a[i+1] > value) {
                            flag = false;
                            break;
                        } else {
                            cnt += value;
                        }
                    }
                }
            }
            if(flag && cnt < ans2) {
                ans2 = cnt;
                // cout << "fuck " << value << ' ' << ans2 << endl;
            }
        }

        printf("Case #%d: %d %d\n", _, ans1, ans2);
    }
}
