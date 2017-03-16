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
        cout << "Case #" << test << ": ";

        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int ans1 = 0;
        for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) ans1 += a[i - 1] - a[i];
        cout << ans1 << " ";

        int ans2 = 0;
        int mx = 0;
        for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) mx = max(mx, a[i - 1] - a[i]);

        for (int i = 0; i < n - 1; i++) {
            if (a[i] >= mx) ans2 += mx;
            else ans2 += a[i];
        }
        cout << ans2;

        cout << endl;
    }


	return 0;
}
