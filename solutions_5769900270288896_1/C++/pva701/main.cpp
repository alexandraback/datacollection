#include <iostream>
#include <vector>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
long long next(long long x) {
    long long n = x;
    vector <int> digits;
    while (x) {
        digits.push_back(x % 10);
        x /= 10;
    }
    sort(digits.begin(), digits.end());
    long long ret = 0;
    for (int i = digits.size() - 1; i >= 0; --i)
        ret = ret * 10 + digits[i];
    if (ret <= n)
        return n + 1;
    return ret;
}
long long next(long long x, long long n) {
    long long nn = n;
    long long xx = x;
    vector <int> digitsx;
    vector <int> digitsn;
    while (x) {
        digitsx.push_back(x % 10);
        x /= 10;
    }

    while (n) {
        digitsn.push_back(n % 10);
        n /= 10;
    }
    reverse(digitsn.begin(), digitsn.end());
    sort(digitsx.begin(), digitsx.end(), greater<int>());
    bool flag = false;
    long long ret = 0;
    for (int i = 0; i < digitsn.size(); ++i) {
        int j = 0;
        while (j < digitsn.size()) {
            long long res = ret * 10 + digitsx[j];
            for (int p = digitsx.size() - 1; p >= 0; --p)
                if (p != j) res = res * 10 + digitsx[p];
            if (res <= nn) break;
            ++j;
        }
        ret = ret * 10 + digitsx[j];
        digitsx.erase(digitsx.begin() + j);
    }
    if (ret <= xx)
        return xx + 1;
    return ret;
}

int len(long long x) {
    int ret = 0;
    while (x) {
        ret++;
        x /= 10;
    }
    return ret;
}

int solve(long long n) {
    cerr << "NOW " << n << endl;
    long long x = 1;
    int ans = 1;
    int lenN = len(n);
    while (len(x) != lenN) {
        x = next(x);
        ++ans;
    }
    //cerr << "x = " << x << endl;
    cerr << "n = " << n << "it = " << n << endl;
    cerr << "x = " << x << endl;
    while (x != n) {
        x = next(x, n);
        //cerr << "nx x = " << x << endl;
        ++ans;
    }
    cerr << "n = " << "it = " << n << endl;
    return ans;
}

typedef pair <int, pair <int, int> > piii;
#define f first
#define s second

/*struct Comparator1 {
    bool operator () (const piii& a, const piii& b) {
        return a.first < b.first || a.first == b.first && (a.s.f + a.s.s) % 2 < (b.s.f + b.s.s) % 2;
    }
};

struct Comparator2 {
    bool operator () (const piii& a, const piii& b) {
        return a.first < b.first || a.first == b.first && (a.s.f + a.s.s) % 2 > (b.s.f + b.s.s) % 2;
    }
};*/


bool c1(const piii& a, const piii& b) {
        return a.first < b.first || a.first == b.first && (a.s.f + a.s.s) % 2 < (b.s.f + b.s.s) % 2 ||
        a.first == b.first && (a.s.f + a.s.s) % 2 == (b.s.f + b.s.s) % 2 && a < b;
}

bool c2(const piii& a, const piii& b) {
    return a.first < b.first || a.first == b.first && (a.s.f + a.s.s) % 2 > (b.s.f + b.s.s) % 2 ||
    a.first == b.first && (a.s.f + a.s.s) % 2 == (b.s.f + b.s.s) % 2 && a < b;
}


int solveB(int r, int c, int n, bool (*cmp)(const piii& a, const piii& b)) {
    vector <vector <int> > a(r);
    for (int i = 0; i < r; ++i)
        a[i] = vector <int>(c);
    set <piii, bool(*)(const piii&,const piii&)> q(cmp);
    int ans = 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j) {
            q.insert(make_pair(0, make_pair(i, j)));
            a[i][j] = 0;

        }
    const int X[] = {-1, 1, 0, 0};
    const int Y[] = {0, 0, -1, 1};
    for (int it = 0; it < n; ++it) {
        //cerr << "n = " << n << " it = " << it << " " << r * c << endl;
        piii b = *q.begin();
        q.erase(q.begin());
        ans += b.first;
        int i  = b.s.f;
        int j = b.s.s;
        a[i][j] = -1;
        for (int p = 0; p < 4; ++p) {
            int ni = i + X[p];
            int nj = j + Y[p];
            if (ni >= 0 && nj >= 0 && ni < r && nj < c && a[ni][nj] != -1) {
                q.erase(make_pair(a[ni][nj], make_pair(ni, nj)));
                a[ni][nj]++;
                q.insert(make_pair(a[ni][nj], make_pair(ni, nj)));
            }
        }
    }
    return ans;
}


/*int solveB(int r, int c, int n) {
    int tot=1<<(r*c);
    bool a[20][20] = {0};
    const int X[] = {-1, 1, 0, 0};
    const int Y[] = {0, 0, -1, 1};
    int ans = 1e9;
    int mmm = 0;
    for (int ms = 0; ms < tot; ++ms) {
        int cnt = 0;
        for (int i = 0; i < r * c; ++i)
            if ((ms>>i)&1) ++cnt;
        if (cnt != n)
            continue;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                a[i][j] = (ms>>(c*i+j))&1;

        int cur = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (a[i][j])
                for (int p = 0; p < 4; ++p) {
                    int ni = i + X[p];
                    int nj = j + Y[p];
                    if (ni >= 0 && nj >= 0 && ni < r && nj < c) cur += a[ni][nj];
                }
        if (cur < ans) {
            ans = cur;
            mmm = ms;
        }
        //ans = min(ans, cur);
    }
    for (int i = 0; i < r; ++i, cout << endl)
        for (int j = 0; j < c; ++j)
            cout << ((mmm>>(c*i+j))&1);
                //a[i][j] = (ms>>(c*i+j))&1;
    return ans / 2;
}*/

int main() {
    //freopen("input.txt", "r", stdin);
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    //Comparator1 c1;
    //Comparator2 c2;
    int t;
    cin >> t;
    long long n;
    for (int i = 1; i <= t; ++i) {
        cerr << "it = " << i << endl;
        int r, c, n;
        cin >> r >> c >> n;
        cout << "Case #" << i << ": " << min(solveB(r, c, n, c1), solveB(r, c, n, c2)) << endl;
    }
    return 0;
}
