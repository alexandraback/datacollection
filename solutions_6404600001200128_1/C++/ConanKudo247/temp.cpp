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
int n,a[30000];

void solve1() {
    int res = 0, curMus = 0;
    FOR(i,1,n) {
        if (curMus < a[i]) {
            curMus = a[i];
        } else {
            res += curMus - a[i];
            curMus = a[i];
        }
    }
    cout << res << " ";
}
void solve2() {
    int speed = 0;
    FOR(i,2,n)
    if (a[i] < a[i-1]) {
        speed = max(speed, a[i-1] - a[i]);
    }

    int res = 0;
    FOR(i,1,n-1) {
        int eaten = min(speed, a[i]);
        res += eaten;
    }
    cout << res << endl;
}
void solve() {
    solve1();
    solve2();
}
int main() {
    std::ios::sync_with_stdio(false);
    freopen("A-large-1.in","r",stdin);
    freopen("output.txt","w",stdout);
    int ntest;
    cin >> ntest;

    FOR(test,1,ntest) {
        cout << "Case #" << test << ": ";
        cin >> n;
        FOR(i,1,n) cin >> a[i];
        solve();
    }
    return 0;
}

