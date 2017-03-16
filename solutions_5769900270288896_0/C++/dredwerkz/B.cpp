#define DBG 1

#include <cstring>
#include <map>
#include <unordered_map>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstdio>
#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef pair<int, int> pii;

int gi() {
    int a;
    scanf("%d", &a);
    return a;
}

ll gli() {
    ll a;
    scanf("%lld", &a);
    return a;
}

#define SINGLELINE 1
void solve() {
    int r = gi();
    int c = gi();
    int n = gi();
    if (r == 1 || c == 1) {
        r = MAX(r, c);
        int x = 0;
        if (r%2) {
            if (n > (r+1)/2) {
                x = 2 * (n-(r+1)/2);
            }
        } else {
            if (n > r/2) {
                x = 1 + 2*(n-1-r/2);
            }
        }
        printf("%d\n", x);
        return;
    }
    n = r*c-n;
    int t = 2*r*c-r-c;
    int m4 = ((r-2)*(c-2)+1)/2;
    int m2 = (r%2 && c%2) ? 4 : 2;
    int m3 = (r*c+1)/2-(m2+m4);
    if (n) {
        int tt = MIN(n, m4);
        t -= 4*tt;
        n -= tt;
    }
    if (n) {
        int tt = MIN(n, m3);
        t -= 3*tt;
        n -= tt;
    }
    if (n) {
        int tt = MIN(n, m2);
        t -= 2*tt;
    }

    int tr = 10000000;
    if (r%2 && c%2) {
    m3 = 2*(((r-1)/2) + ((c-1)/2));
    m4 = ((r-2)*(c-2))/2;
    tr = 2*r*c-r-c;
    if (n) {
        int tt = MIN(n, m4);
        tr -= 4*tt;
        n -= tt;
    }
    if (n) {
        int tt = MIN(n, m3);
        tr -= 3*tt;
        n -= tt;
    }
    }
    printf("%d\n", MIN(t, tr));
}

int main() {
    int t = gi();

    for (int i = 1; i <= t; i++) {
        printf("Case #%d:%c", i, (SINGLELINE ? ' ' : '\n'));
        solve();
    }

    return 0;
}
