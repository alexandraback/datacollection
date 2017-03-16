#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
#include <set>
#include <sstream>
#include <cstdio>
#define FOR(i,a,b) for(int i=(a);i<=(b); i++)
#define FR(i,b) for(int i=0; i<(b);i++)
#define DR(i,b) for(int i=(b)-1; i>=0;i--)
#define DOWN(i,a,b) for(int i=(a); i >=(b); i--)
#define X first
#define Y second
#define XX first.first
#define XY first.second
#define YX second.first
#define YY second.second
using namespace std;
long long n,m,a[30000];
long long nCut(long long T) {
    if (T < 0) return 0;
    long long res = 0;
    FOR(i,1,n)
    res += T / a[i] + 1;
    return res;
}
long long getTimeCut() {
    long long first = 0, last = 1000000000000000LL, mid;
    do {
        mid = (first + last) / 2;
        if (nCut(mid) < m) first = mid;
        else last = mid;
    } while (last - first > 1);

    if (nCut(first) >= m) return first;
    else return last;
}
void solve() {
    long long T = getTimeCut();
    long long remain = m - nCut(T-1);

    FOR(i,1,n)
    if (T % a[i] == 0) {
        remain--;
        if (!remain) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    freopen("B-small-1.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest;
    cin >> ntest;

    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n >> m;
        FOR(i,1,n) cin >> a[i];
        solve();
    }
    return 0;
}

