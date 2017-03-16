#include <bits/stdc++.h>
#define MAX_N 1010
using namespace std;

int t, n, arr[MAX_N], ans1, ans2, rate;

int main(void) {
    if (fopen("a.in","r")) {
        freopen("a.in","r",stdin);
        freopen("a.out","w",stdout);
    }
    cin >> t;
    for (int ii=1; ii<=t; ii++) {
        ans1=0; ans2=0; rate=0;
        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];
        for (int i=0; i<n-1; i++) {
            if (arr[i]>=arr[i+1]) ans1+=arr[i]-arr[i+1];
            if (arr[i]>=arr[i+1]) {
                rate=max(rate,(arr[i]-arr[i+1]));
            }
        }
        for (int i=0; i<n-1; i++) {
            if (arr[i]<rate) ans2+=arr[i];
            else ans2+=rate;
        }
        cout << "Case #" << ii << ": ";
        cout << ans1 << " " << ans2 << "\n";
    }
    return 0;
}
