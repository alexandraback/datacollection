#include <iostream>

using namespace std;

#define SHOW_A(x) {cout << #x << " = " << x << endl;}
#define SHOW_B(x, y) {cout << #x << " = " << x << ", " << #y << " = " << y << endl;}
#define SHOW_C(x, y, z) {cout << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;}
#define REACH_HERE {cout << "REACH_HERE! line: " << __LINE__ << endl;}

#define HHH 1002

long long b, n;
long long t[HHH];

long long cut(long long ttt) {
    long long can = 0;
    for (long long i = 0; i < b; i++)
        can += ttt / t[i] + 1;
    return can;
}

long long get(long long slowestB) {
    long long maxTotalTime = slowestB * n - slowestB;
    long long r = maxTotalTime * 2;
    long long l = 0;

    while (l < r) {
        long long m = (l + r) / 2;
        // SHOW_C(l, m, r);
        if (m == l)
            break;
        
        long long can = cut(m);

        // SHOW_A(can);
        if (can >= n)
            r = m;
        else
            l = m;
    }
    return r;
}

long long sol() {
    long long slowestB = 0;
    for (long long i = 0; i < b; i++)
        slowestB = max(slowestB, t[i]);

    long long finalTime = get(slowestB);

    // SHOW_A(finalTime);

    long long acc = n;
    long long i;
    for (i = 0; i < b; i++) {
        acc -= finalTime / t[i];
        if (finalTime % t[i])
            acc--;
        if (acc == 0)
            break;
    }
    if (acc > 0)
    for (i = 0; i < b; i++) {
        if (finalTime % t[i] == 0)
            acc--;
        if (acc == 0)
            break;
    }
    return i + 1;
}

int main() {
    long long x;
    cin >> x;
    for (long long c = 1; c <= x; c++) {
        cin >> b >> n;
        for (long long i = 0; i < b; i++)
            cin >> t[i];

        // cout << "Case " << c << endl;

        long long ans = sol();
        cout << "Case #" << c << ": " << ans << endl;
    }
}