#include <iostream>

using namespace std;

#define ll long long

int t;
int b;
ll n;
ll m[1111];

ll s(ll z) {
    ll u = 0;
    for (int i = 0; i < b; i++) u += z/m[i];
    return u;
}

void solve(int x) {
    cin >> b >> n;
    for (int i = 0; i < b; i++) cin >> m[i];
    ll t = 0;
    for (ll u = 10e12; u >= 1; u /= 2) {
        while (s(t+u) < n) t += u;
    }
    t -= 200000;
    if (t < 0) t = 0;
    ll a = 0;
    for (int i = 0; i < b; i++) {
        a += t/m[i];
        if (t%m[i] != 0) a++;
    }
    while (true) {
        for (int i = 0; i < b; i++) {
            if (t%m[i] == 0) a++;
            if (a == n) {
                cout << "Case #" << x << ": " << i+1 << "\n";
                return;
            }
        }
        t++;
    }
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
