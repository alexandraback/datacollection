/**
 * Copyright (c) 2014 Authors. All rights reserved.
 * 
 * FileName: A.cpp
 * Author: Beiyu Li <sysulby@gmail.com>
 * Date: 2014-04-12
 */
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for (int i = 0; i < (n); ++i)
#define FOR(i,s,t) for (LL i = (s); i <= (t); ++i)
#define FOREACH(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

typedef long long LL;
typedef pair<int, int> Pii;
typedef complex<double> Point;
typedef complex<double> Vector;
#define X real()
#define Y imag()

const double pi = acos(-1);
const double eps = 1e-10;
const int inf = 0x3f3f3f3f;
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

int n, m;
int a[4][4], b[4][4];

int main()
{
        int T, cas = 0;
        cin >> T;

        while (T--) {
                cin >> n; --n;
                REP(i,4) REP(j,4) cin >> a[i][j];
                cin >> m; --m;
                REP(i,4) REP(j,4) cin >> b[i][j];
                int res = -1;
                REP(j,4) {
                        REP(i,4) if (a[n][i] == b[m][j]) {
                                if (res == -1) res = b[m][j];
                                else res = inf;
                                break;
                        }
                }
                cout << "Case #" << ++cas << ": ";
                if (res == -1) cout << "Volunteer cheated!" << endl;
                else if (res == inf) cout << "Bad magician!" << endl;
                else cout << res << endl;
        }

        return 0;
}
