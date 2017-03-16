//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i ++)
#define DOW(i, a, b) for(int i = a; i >= b; i --)
#define RESET(c, val) memset(c, val, sizeof(c))
#define oo 1e9
#define eps 1e-9
#define base 1000000007
#define maxn 100005
#define maxx 10000000

int a[100][100];

int main() {
    ios_base::sync_with_stdio(0);
    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int test;
    cin >> test;

    FOR(t, 1, test) {
        cout << "Case #" << t << ": ";

        long long m, n, k;
        cin >> m >> n >> k;

        int res = 1000000000;
        RESET(a, 0);
        FOR(state, 0, (1 << (m*n)) - 1) {
            int x = state;
            FOR(i, 1, m) FOR(j, 1, n) a[i][j] = x % 2, x/=2;

            int rr = 0, cc = 0;
            FOR(i, 1, m) FOR(j, 1, n) {
                cc += a[i][j];
                rr += (a[i][j] && a[i+1][j]) + (a[i][j] && a[i][j+1]);
            }
            if (cc == k) {
                res = min(res, rr);
            }
        }

        cout << res << endl;
    }
    return 0;
}