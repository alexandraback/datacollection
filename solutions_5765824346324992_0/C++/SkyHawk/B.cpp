#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define sz(v) ((long long)v.size())
#define mp make_pair
#define FOR(i,n) for(int i = 0;i < (n);++i)

long long MOD = 1000000007;

int T;
long long ar[1010];

int main() {
    cin >> T;
    FOR(itest, T) {
        long long n, b;
        cin >> b >> n;
        FOR(i, b)
            cin >> ar[i];
        long long l = 0;
        long long r = 100100ll * 1000000000ll;
        while (l + 1 < r) {
            long long m = (l + r) / 2;
            long long nfree = 0;
            long long nout = 0;
            FOR(i, b) {
                nout += m / ar[i] + ((m % ar[i]) != 0);
                nfree += ((m% ar[i]) == 0);
            }
            if (nout >= n) {
                r = m;
            } else {
                l = m;
            }
        }
        long long nout = 0;
        FOR(i, b) {
            nout += l / ar[i] + ((l % ar[i]) != 0);
        }
        long long d = n - nout;
        long long ans = 0;
        FOR(i, b) {
            if((l % ar[i]) == 0) {
                --d;
                if (d == 0) {
                    ans = i+1;
                    break;
                }
            }
        }

        cout << "Case #" << (itest + 1) << ": " << ans << endl;
    }
}