#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cassert>
#include <climits>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

#define sqr(x) ((x) * (x))
#define abs(x) (((x) > 0) ? (x) : (-(x))) 
#define lowbit(x) ((x) & (-(x)))

using namespace std;

const int N = 1111;

int n;
int a[N];

inline void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    int result1 = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i + 1]) {
            result1 += a[i] - a[i + 1];
        }
    }
    cout << result1 << " ";

    int delta = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] > a[i + 1]) {
            delta = max(delta, a[i] - a[i + 1]);
        }
    }
    
    int result2 = 0;
    for (int i = 1; i < n; ++i) {
        result2 += min(delta, a[i]);
    }
    
    cout << result2 << endl;
}

int main() {
	ios::sync_with_stdio(false);

	int tests;
	cin >> tests;
	for (int i = 1; i <= tests; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
