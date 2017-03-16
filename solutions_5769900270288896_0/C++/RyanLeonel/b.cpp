#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
    int c, cnt, i, i1, j, k, n, n1, n2, r, rc, res, t, z, zmin;
    vector <int> x;
    vector <vector <int> > xx;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++) {
        cin >> r; cin >> c; cin >> n;
        n1 = 1; rc = r * c;  for (i = 0; i < rc; i++) n1 *= 2;
        x.resize(rc); xx.resize(r); for (i = 0; i < r; i++) xx[i].resize(c);
        zmin = 999;
        for (i = 0; i < n1; i++) {
            n2 = 0; i1 = i;
            for (j = 0; j < rc; j++) {
                x[j] = i1 % 2; i1 /= 2; if (x[j]) n2++;
            }
            if (n2 == n) {
                for (j = 0; j < r; j++) {
                    for (k = 0; k < c; k++) xx[j][k] = x[(j * c) + k];
                }
                z = 0;
                for (j = 0; j < r - 1; j++) {
                    for (k = 0; k < c; k++) if ((xx[j][k]) && (xx[j + 1][k])) z++;
                }
                for (j = 0; j < r; j++) {
                    for (k = 0; k < c - 1; k++) if ((xx[j][k]) && (xx[j][k + 1])) z++;
                }
                if (z < zmin) zmin = z;
            }
        }
        cout << "Case #" << cnt << ": " << zmin << endl;
    }
    return 0;
}
