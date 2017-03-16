#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define inf 1000000007

using namespace std;

int n, a[30];

void solve() {
    int sum = 0;    
    for (int i = 1; i <= n; ++ i) sum += a[i];
    if (sum & 1) {
        int k1 = 1;
        for (int i = 2; i <= n; ++ i) if (a[i] > a[k1]) k1 = i;
        -- a[k1], -- sum;
        printf(" %c", 'A' + k1 - 1);
    }
    for (; sum; sum -= 2) {
        int k1 = 0, k2 = 0;
        for (int i = 1; i <= n; ++ i) if (a[i] > a[k1]) k1 = i;
        for (int i = 1; i <= n; ++ i) if (a[i] > a[k2] && i != k1) k2 = i;
        -- a[k1], -- a[k2];
        printf(" %c%c", 'A' + k1 - 1, 'A' + k2 - 1);
    }
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++ i) scanf("%d", &a[i]);
        printf("Case #%d:", t);
        solve();
        printf("\n");
    }
    
    return 0;
}