#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <cstdio>
using namespace std;

typedef long long ll;

ll M[1000];
ll B, N;

// (lb, ub]
ll minimum(bool(*C)(ll), ll lb, ll ub) {
    while (ub - lb > 1ll) {
        ll mid = (lb + ub) / 2ll;
        (C(mid) ? ub : lb) = mid;
    }
    return ub;
}

bool pred(ll t) {
    ll sum = 0;

    for (int i = 0; i < B; i++) {
        sum += (t + M[i]) / M[i];
    }

    return sum >= N;
}

int get(ll t) {
    ll sum = 0;

    for (int i = 0; i < B; i++) {
        sum += (t + M[i] - 1) / M[i];
    }

    int c = N - sum - 1;

    for (int i = 0; i < B; i++) {
        if (t % M[i] == 0ll) {
            if (c == 0) return i + 1;
            else c--;
        }
    }
}

int main() {
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        cin >> B >> N;
        
        for (int k = 0; k < B; k++) {
            cin >> M[k];
        }

        ll t = minimum(pred, 0, 1e16);
        int ans = get(t);

        printf("Case #%d: %d\n", i, ans);
    }
}
