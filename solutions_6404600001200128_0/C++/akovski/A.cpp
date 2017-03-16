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

int a[2000];
void solve() {
    int N; cin >> N;
    for (int i = 0; i < N; i ++) cin >> a[i];
    int res = 0;
    for (int i = 0; i < N - 1; i ++) if (a[i] >= a[i + 1]) res += a[i] - a[i + 1];
    cout << res << ' ';
    res = 0;
    int rate = 0;
    for (int i = 0; i < N - 1; i ++) rate = max(rate, a[i] - a[i + 1]);
    for (int i = 0; i < N - 1; i ++) {
        if (a[i] >= rate) res += rate;
        else res += a[i];
    }
    cout << res << endl;
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
