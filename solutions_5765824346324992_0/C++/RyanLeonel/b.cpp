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

long long gcd(long long a, long long b)
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

long long lcm(long long a, long long b)
{
  return a * b / gcd(a, b);
}

long long n_proc(long long t) {
    long long i, n = 0;
    for (i = 0; i < b; i++) {
        n += (t / m[i]); if (t % m[i]) n++;
    }
    return n;
}

int main()
{
    long long cnt, curtime, i, j, m_notbusy, n, n_busy, n1, n2, num, t, time1, x, x1;
    long long min, med, max, time_a;
    vector <bool> m_busy;
    vector <long long> m_done;
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (cnt = 1; cnt <= t; cnt++) {
        cin >> b; cin >> n; m.resize(b); m_busy.resize(b); m_done.resize(b);
        for (i = 0; i < b; i++) cin >> m[i];
        num = 0; curtime = 0; n_busy = 0; m_notbusy = 0; time1 = 0;
        for (i = 0; i < b; i++) { m_busy[i] = false; m_done[i] = 0; }
        x = m[0]; for (i = 1; i < b; i++) x = lcm(x, m[i]); //cout << x;
        x1 = 0; for (i = 0; i < b; i++) x1 += (x / m[i]);
        //for (i = 1; i <= b; i++) x1 *= i;
        n1 = n % x1; if (!n1) n1 = x1;
        //cout << x << " " << x1 << ": " << n << " -> " << n1 << endl;
        //O(N) simulation
        if (n < 1) {
            for (i = 0; i <= n; i++) {
                if (i == x1) { cout << n_busy; break; }
                //debug simulation
                /*cout << "i=" << i << " t=" << curtime << ": before ";
                for (j = 0; j < b; j++) cout << (m_busy[j] ? 1 : 0) << " ";
                cout << "~";
                for (j = 0; j < b; j++) cout << m_done[j] << " ";
                cout << endl;*/
                //assign to lowest numbered idle barber (m_notbusy)
                num = m_notbusy; m_busy[num] = true; m_done[num] = curtime + m[num]; n_busy++;
                //debug simulation
                /*cout << "i=" << i << " t=" << curtime << ": after ";
                for (j = 0; j < b; j++) cout << (m_busy[j] ? 1 : 0) << " ";
                cout << "~";
                for (j = 0; j < b; j++) cout << m_done[j] << " ";
                cout << endl;*/
                //update time1 (next time checkpoint in simulation) and the list of "freed" barbers then
                if (time1 == curtime) time1 += m[num];
                if (curtime + m[num] < time1) time1 = curtime + m[num];
                //all busy, forward time simulation
                if (n_busy == b) {
                    curtime = time1;
                    for (j = 0; j < b; j++) {
                        if (m_done[j] == time1) {
                            m_busy[j] = false; n_busy--;
                            if (j < m_notbusy) m_notbusy = j;
                        }
                    }
                }
                else {
                    while (m_busy[m_notbusy]) m_notbusy++;
                }
            }
            num++;
        }
        else {
            min = 0; med = 0; for (i = 0; i < b; i++) if (m[i] > med) med = m[i];
            med *= n; max = 1; while (max < med) max *= 2;
            num = max;
            //for (i = 0; i < b; i++) cout << m[i] << " "; cout << endl;
            while (1) {
                med = (min + max) / 2;
                //cout << min << " " << med << " " << max << endl;
                if (n_proc(med) >= n) max = med;
                else min = med;
                if (max - min <= 1) break;
            }
            //cout << "m=" << med << " n(m-1)=" << n_proc(med - 1) << " n(m)=" << n_proc(med) << " n(m+1)=" << n_proc(med + 1) << " n=" << n << endl;
            time_a = med;
            while(n_proc(time_a) < n) time_a++;
            while(n_proc(time_a) >= n) time_a--;
            n2 = n - n_proc(time_a);
            for (i = 0; i < b; i++) m_busy[i] = ((time_a % m[i]) ? true : false);
            for (i = 0; i < b; i++) {
                if (!m_busy[i]) n2--;
                if (!n2) { num = i + 1; break; }
            }
            //cout << "n=" << n << " time=" << a << " n1=" << n_proc(a) << " n2=" << n_proc(a+1) << endl;
            //cout << n2 << endl;
        }
        cout << "Case #" << cnt << ": " << num << endl;
    }
    return 0;
}
