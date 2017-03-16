#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = -1;
const int inf = 1e9;


int main() {
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

	//ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cerr << "Case #" << test << ": ";
        cout << "Case #" << test << ": ";

        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        ll tm = 1e18;
        int ans = -1;
        for (int i = 0; i < n; i++) {
            int l = -1, r = 1.05e9;
            while (r - l > 1) {
                int m = (l + r) >> 1;

                ll start = a[i] * 1LL * m;
                ll cnt = 0;
                for (int j = 0; j < n; j++) {
                    cnt += start / a[j] + (start % a[j] != 0 || j <= i);
                }
                if (cnt < k) l = m;
                else r = m;
            }
            if (tm > a[i] * 1LL * r) {
                tm = a[i] * 1LL * r;
                ans = i + 1;
            }
        }
        cout << ans << endl;
        cerr << ans << endl;
    }


	return 0;
}
