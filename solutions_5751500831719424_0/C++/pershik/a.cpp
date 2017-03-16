#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <queue>
#include <deque>
#include <memory.h>
#include <complex>
#include <numeric>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define INF (1000000000)
#define LINF (1000000000000000000ll)
#define EPS (1e-9)

#define MOD 1000000007

#define NAME "test"
#ifndef NAME
    #error Write problem name!
#endif

using namespace std;

typedef long long li;
typedef unsigned long long uli;

li gcd(li x, li y){
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

li lcm(li x, li y){
    return x / gcd(x, y) * y;
}

li binpow(li a, li p){
    if (!p)
        return 1;
    li g = binpow(a, p >> 1);
    if (p % 2 == 0)
        return (g * g) % MOD;
    else
        return (((g * g) % MOD) * a) % MOD;
}

li rev(li n){
    return binpow(n, (li)MOD - 2LL);
}

void solve(int test_number);

int main() {
#ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    assert(freopen(NAME ".out", "w", stdout));
#endif
    cout.setf(ios::fixed);
    cout.precision(20);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i + 1);
}

int n;
string s[1010];
string x[1010];
int a[1000][1000];
int b[1000];

void solve(int test_number) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        //cout << s[i] << endl;
        x[i] = " ";
        x[i][0] = s[i][0];
        //cout << x[i] << endl;
        for (int j = 1; j < (int)s[i].length(); j++)
            if (s[i][j] != s[i][j - 1])
                x[i] += s[i][j];
    }
    cout << "Case #" << test_number << ": ";
    for (int i = 0; i < n - 1; i++)
        if (x[i] != x[i + 1]) {
            cout << "Fegla Won\n";
            return;
        }
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < (int)x[0].length(); j++) {
            while (s[i][cur] == x[i][j]) {
                cur++;
                a[i][j]++;
            }
        }
    }
    
    li res = 0;
    for (int i = 0; i < (int)x[0].size(); i++) {
        for (int j = 0; j < n; j++)
            b[j] = a[j][i];
        sort(b, b + n);
        int d = n / 2;
        for (int j = 0; j < n; j++)
            res += (li)abs(b[d] - b[j]);
    }
    cout << res << endl;
}

