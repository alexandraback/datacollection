#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

LL n, a[10000], c;
void solve() {
    cin >> n >> c;
    for (int i = 0; i < n; i ++) cin >> a[i];
    LL l = 0, r = 1000000000000000LL, cnt = 0;
    while (l < r) {
        LL mid = (l + r) >> 1;
        cnt = n;
        for (int i = 0; i < n; i ++) cnt += mid / a[i];
        if (cnt >= c) r = mid;
        else l = mid + 1;
    }
    cnt = n; for (int i = 0; i < n; i ++) cnt += l / a[i];
    for (int i = n - 1; i >= 0; i --) {
        if (l % a[i] == 0) {
            if (cnt == c) {
                cout << i + 1 << endl;
                return;
            }
            else cnt --;
        }
    }
    cerr << "WA" << endl;
}
int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int Q; cin >> Q;
    for (int i = 0; i < Q; i ++) {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    
    return 0;
}

