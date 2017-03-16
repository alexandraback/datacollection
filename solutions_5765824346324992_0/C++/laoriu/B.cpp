#include <bits/stdc++.h>

using namespace std;

const int MAXM = 1000 + 10;
const int MAXT = 100000;

int a[MAXM];
int n, m;

long long count_customer(long long current_time) {
    if (current_time < 0) return 0;
    long long res = 0;
    for(int i = 1; i <= m; i++) res += (current_time / a[i]) + 1;
    return res;
}

int solve() {
    cin >> m >> n;
    for(int i = 1; i <= m; i++) cin >> a[i];
    long long low = 0, high = 1LL * n * MAXT;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long t = count_customer(mid);
        if (t >= n) high = mid - 1;
        else low = mid + 1;
    }
    long long serve_time = high + 1;
    long long t = count_customer(serve_time - 1);
    for(int i = 1; i <= m; i++) {
        if (serve_time % a[i] == 0) {
            t++;
            if (t >= n) return i;
        }
    }
    return -1;
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);

    int test;
    cin >> test;
    for(int tc = 1; tc <= test; tc++) {
        cout << "Case #" << tc << ": " << solve() << endl;
    }
}
