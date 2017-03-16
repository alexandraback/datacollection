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

int N;
int m[1000];

int solve1() {
    int res = 0;

    for (int i = 0; i < N - 1; i++) {
        res += max(0, m[i] - m[i + 1]);
    }

    return res;
}

int solve2() {
    int maxi = 0;

    for (int i = 0; i < N - 1; i++) {
        if (maxi < max(0, m[i] - m[i + 1])) {
            maxi = max(0, m[i] - m[i + 1]);
        }
    }

    int res = 0;

    for (int i = 0; i < N - 1; i++) {
        res += min(m[i], maxi);
    }

    return res;
}

int main() {
    int T;
    cin >> T;
    
    for (int k = 1; k <= T; k++) {
        cin >> N;

        for (int i = 0; i < N; i++) {
            cin >> m[i];
        }

        int ans1 = solve1();
        int ans2 = solve2();

        printf("Case #%d: %d %d\n", k, ans1, ans2);
    }
}
