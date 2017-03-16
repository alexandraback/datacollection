#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

void solve() {
    int b, n;
    cin >> b >> n;
    vector<long long> M(b);
    long long m = 1;
    for (int i = 0; i < b; ++i) {
        cin >> M[i];
        m *= M[i];
    }
    int k = 0;
    for (int i = 0; i < b; ++i)
        k += (m / M[i]);
    n %= k;
    cout << "[K: " << k << "] ";

    if (n == 0) {
        cout << "1\n";
        return;
    }

    set<pair<long long, int>> S;
    for (int i = 0; i < b; ++i)
        S.insert(make_pair(0, i + 1));

    pair<long long, int> barb;
    for (int i = 1; i <= n; ++i) {
        barb = *(S.begin());
        S.erase(S.begin());
        S.insert(make_pair(barb.first + M[barb.second - 1], barb.second));
    }
    cout << barb.second << "\n";
}

void solve2() {
    long long b, n, nn;
    cin >> b >> n;
    nn = n;
    vector<long long> M(b);
    for (int i = 0; i < b; ++i)
        cin >> M[i];

    long long l = 0, m, r = 1e12;
    long long k, t;
    while (r - l > 1) {
        m = (l + r) / 2;
        k = t = 0;
        for (int i = 0; i < b; ++i)
            k += ((m + M[i] - 1) / M[i]);
        for (int i = 0; i < b; ++i)
            t += ((m % M[i]) == 0ll);
        if (k + t < n)
            l = m;
        else if (k < n && k + t >= n) {
            l = r = 0;
        }
        else
            r = m;
    }
    k = 0;
    for (int i = 0; i < b; ++i)
        k += ((m + M[i] - 1) / M[i]);
    n -= k;
    int i;
    for (i = 0; i < b && n > 0; ++i)
        n -= (m % M[i] == 0);
    if (i == 0)
        i = nn;
    cout << i << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int T, _T;
    scanf("%d", &T);
    for (_T = 1; _T <= T; ++_T) {
        printf("Case #%d: ", _T);
        solve2();
    }
    return 0;
}