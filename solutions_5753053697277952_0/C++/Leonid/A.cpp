#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <list>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

void openFiles() {
    //freopen("test.in", "rt", stdin);
    //freopen("test.out", "wt", stdout);
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	// freopen("A-large.in", "rt", stdin);
	// freopen("A-large.out", "wt", stdout);
}

void solve() {
	vector<pair<int, char> > v;
    int n; scanf("%d ", &n);
    int s = 0;
    REP(i, n) {
        int a; scanf("%d ", &a);
        v.push_back(make_pair(a, 'A' + i));
        s += a;
    }

    while (v.size() > 0) {
        sort(v.rbegin(), v.rend());
        if (v[0].first == 0) break;

        int a = v[0].first, b = v[1].first;
        char ca = v[0].second, cb = v[1].second;
        if (a > b || s % 2) {
            printf(" %c", ca);
            v[0].first--;
            s--;
        } else if (a == b) {
            printf(" %c%c", ca, cb);
            v[0].first--;
            v[1].first--;
            s -= 2;
        }
    }
    printf("\n");
}

int main() {
    openFiles();
    int n; scanf("%d ", &n);
    for (int i = 0; i < n; i++) {
            printf("Case #%d: ", i + 1);
            solve();
    }
    return 0;
}
