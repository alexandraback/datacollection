#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, ar[MAXN];

void go(int casenum) {
    cin >> n;
    for (int i=0; i<n; i++) cin >> ar[i];

    int ans = 0, ma = 0;
    for (int i=0; i<n-1; i++)
        if (ar[i+1] < ar[i]) {
            ans += ar[i]-ar[i+1];
            ma = max(ma, ar[i]-ar[i+1]);
        }


    printf("Case #%d: %d ", casenum, ans);

    ans = 0;
    for (int i=0; i<n-1; i++)
        ans += min(ma, ar[i]);
    printf("%d\n", ans);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) go(i);
}
