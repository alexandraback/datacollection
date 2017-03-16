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
    bool valid;
    char ch;
    int cnt, i, j, k, l, n, p_total, pp, pp2, pos, t, temp;
    string res;
    vector <int> p, p1;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++)
    {
        cin >> n; p.resize(n); p1.resize(n); p_total = 0;
        for (i = 0; i < n; i++) { cin >> p[i]; p_total += p[i]; }

        for (i = 0; i < n; i++) p1[i] = p[i]; pp = p_total; res = "";
        while (pp > 0) {
            valid = false;
            for (j = 0; j < n; j++) {
                if (p1[j] > 0) {
                    for (k = 0; k < n; k++) {
                        if (((p1[k] > 0) && (j != k)) || ((p1[k] > 1) && (j == k))) {
                            pp2 = (pp - 2) / 2;
                            valid = true;
                            //try to evacuate j, k
                            for (l = 0; l < n; l++) {
                                temp = p1[l];
                                if (l == j) temp--;
                                if (l == k) temp--;
                                if (temp > pp2) { valid = false; break; }
                            }
                            if (valid) break;
                        }
                    }
                    if (!valid) {
                        k = -1;
                        pp2 = (pp - 1) / 2;
                        //try to evacuate j
                        valid = true;
                        for (l = 0; l < n; l++) {
                            temp = p1[l];
                            if (l == j) temp--;
                            if (temp > pp2) { valid = false; break; }
                        }
                        if (valid) break;
                    }
                }
                if (valid) break;
            }
            if (valid) {
                p1[j]--; pp--; ch = j + 'A'; res += ch;
                if (k != -1) { p1[k]--; pp--; ch = k + 'A'; res += ch; }
            }
            if (pp) res += " ";
        }

        //display results
        cout << "Case #" << cnt << ": " << res << endl;
    }
    return 0;
}
