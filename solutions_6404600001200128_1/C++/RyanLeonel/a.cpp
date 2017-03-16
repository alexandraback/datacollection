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
    int a, b, cnt, i, maxrate, n, rate, t, temp;
    vector <int> m;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n; m.resize(n);
        for (i = 0; i < n; i++) cin >> m[i];
        a = 0; maxrate = 0;
        for (i = 1; i < n; i++) { // count added mushrooms
            if (m[i] < m[i - 1]) {
                rate = m[i - 1] - m[i];
                a += rate;
                if (rate > maxrate) maxrate = rate;
            }
        }
        b = 0;
        for (i = 1; i < n; i++) { // simulation
            if (m[i - 1] >= maxrate) b += maxrate;
            else b += m[i - 1];
        }
        cout << "Case #" << cnt << ": " << a << " " << b << endl;
    }
    return 0;
}
