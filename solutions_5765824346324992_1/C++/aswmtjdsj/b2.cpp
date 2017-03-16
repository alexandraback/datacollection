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
        long long tar = n - 1;
        long long hi = 1000000000ll * 100000ll, lo = 0;
        while(lo < hi) {
            long long mid = (hi + lo) / 2;
            long long cnt = 0;
            for(int i = 0; i < b; i++) {
                cnt += mid / m[i] + ((mid % m[i]) != 0);
            }
            if(cnt > tar) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        long long mid = (lo + hi) / 2;
        long long cnt = 0, cnt2 = 0;
        int chosen = -1;
        for(int i = 0; i < b; i++) {
            cnt += mid / m[i];// + ((mid % m[i]) != 0);
        }
        for(int i = 0; i < b; i++) {
            cnt2 += (mid-1) / m[i] + (((mid-1) % m[i]) != 0);
        }
        long long res = tar - cnt2;
        for(int i = 0; i < b; i++) {
            if((mid-1) % m[i] == 0) {
                if(res == 0) {
                    chosen = i;
                    break;
                }
                res--;
            }
        }
        // cout << lo << ' ' << mid << ' ' << hi << " : " << cnt << ' ' << cnt2 << ' ' << tar << endl;
        printf("Case #%d: %d\n", _, chosen + 1);
    }
}
