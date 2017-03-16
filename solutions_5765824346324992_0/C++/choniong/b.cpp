#include <iostream>
using namespace std;

typedef long long ll;

ll getCus(ll m[], int b, ll t) {
    ll cus = 0;
    for (int i = 0; i < b; ++i) {
        cus += t / m[i] + 1;
    }

    return cus;
}

ll getStartTime(ll m[], int b, ll n) {
    ll t1 = 0, t2 = ll(1) << 60;

    while (t2 - t1 > 1) {
        ll tm = (t1 + t2) / 2;
        if (getCus(m, b, tm) >= n) {
            t2 = tm;
        } else {
            t1 = tm;
        }
    }

    if (getCus(m, b, t1) >= n) {
        t2 = t1;
    }
    return t2;
}

int main () {
    int T;
    cin >> T;
    for (int tt = 1; tt <= T; ++tt) {
        int b;
        ll n;
        cin >> b >> n;
        ll m[b];
        for (int i = 0; i < b; ++i) {
            cin >> m[i];
        }

        ll starttime = getStartTime(m, b, n);
        ll lastcus = getCus(m, b, starttime-1);
        ll cusinline = n - lastcus;

        int num = -1;
        for (int i = 0; i < b; ++i) {
            if (starttime % m[i] == 0) {
                --cusinline;
                if (cusinline == 0) {
                    num = i;
                    break;
                }
            }
        }

        printf("Case #%d: %d\n", tt, num+1);
    }

    return 0;
}

