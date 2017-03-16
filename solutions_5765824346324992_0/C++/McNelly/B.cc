#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x

typedef long long llint;

const llint INF = 0x3f3f3f3f3f3f3f3fLL;

int B, N;
vector<llint> Cs;
vector<llint> Bs;

llint gcd(llint a, llint b) {
    if (a < b) {
        return gcd(b, a);
    }

    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

llint lcm() {
    llint u = Bs[0];
    for (int i = 1; i < B; i++) {
        llint g = gcd(u, Bs[i]);
        u = (u * Bs[i]) / g;
    }
    return u;
}

int simulation() {
    Cs.clear();
    Cs.resize(B);
    int num = N;
    while (num) {
        llint mini = INF;
        for (int j = 0; j < B; j++) {
            mini = min(mini, Cs[j]);
        }
        for (int j = 0; j < B; j++) {
            Cs[j] -= mini;
            if (Cs[j] == 0) {
                Cs[j] = Bs[j];
                num--;
            }
            if (num == 0) {
                return j;
            }
        }
    }
    return -123;
}

int main() {
    int T, a, cas = 1;
    input(T);
    while (T--) {
        input(B >> N);
        Bs.clear();
        for (int i = 0; i < B; i++) {
            input(a);
            Bs.push_back(a);
        }

        llint u = lcm();
        llint cnt = 0;
        for (int i = 0; i < B; i++) {
            cnt += u / Bs[i];
        }
        N %= cnt;
        if (N == 0) {
            N = cnt;
        }
        printf("Case #%d: %d\n", cas++, simulation() + 1);
    }
    return 0;
}


