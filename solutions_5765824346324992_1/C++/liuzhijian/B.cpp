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

const int B = 111111;

int b;
long long n;
long long m[B];

inline long long check(const long long &x) {
    long long result = 0;
    for (int i = 1; i <= b; ++i) {
        result += x / m[i] + 1;
    }
    return result;
}

inline void solve() {
    cin >> b >> n;
    for (int i = 1; i <= b; ++i) {
        cin >> m[i];
    }

    long long left = 0, right = 1LL << 60;
    for (; left < right; ) {
        long long mid = left + right >> 1;
        if (check(mid) >= n) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    for (; check(left) < n; ++left);
    for (; check(left - 1) >= n; --left);

    int rest = n - check(left - 1);
    for (int i = 1; i <= b; ++i) {
        if (left % m[i] == 0) {
            rest--;
        }
        if (rest == 0) {
            cout << i << endl;
            break;
        }
    }
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
