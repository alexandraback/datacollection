#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>

using namespace std;

long long b;
vector <long long> m;

long long n_proc(long long t) {
    long long i, n = 0;
    for (i = 0; i < b; i++) {
        n += (t / m[i]); if (t % m[i]) n++;
    }
    return n;
}

int main()
{
    long long cnt, i, n, n2, num, t;
    long long min, med, max, time_a;
    vector <bool> m_busy;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++) {
        cin >> b; cin >> n; m.resize(b); m_busy.resize(b);
        for (i = 0; i < b; i++) cin >> m[i];
        min = 0; med = 0; for (i = 0; i < b; i++) if (m[i] > med) med = m[i];
        med *= n; max = 1; while (max < med) max *= 2;
        num = max;
        while (1) {
            med = (min + max) / 2;
            if (n_proc(med) >= n) max = med;
            else min = med;
            if (max - min <= 1) break;
        }
        time_a = med;
        while(n_proc(time_a) < n) time_a++;
        while(n_proc(time_a) >= n) time_a--;
        n2 = n - n_proc(time_a);
        for (i = 0; i < b; i++) m_busy[i] = ((time_a % m[i]) ? true : false);
        for (i = 0; i < b; i++) {
            if (!m_busy[i]) n2--;
            if (!n2) { num = i + 1; break; }
        }
        cout << "Case #" << cnt << ": " << num << endl;
    }
    return 0;
}
