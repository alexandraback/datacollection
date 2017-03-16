#include <bits\stdc++.h>
typedef long long ll;
using namespace std;
int t;
int n;
ll a[(1 << 17)];
int main(){
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int qr = 0; qr < t; ++qr){
        cin >> n;
        ll ans1 = 0;
        ll ans2 = 0;
        ll mx = 0;
        for(int i  =0; i < n; ++i){
            scanf("%I64d", &a[i]);
            if(i){
                mx = max(a[i - 1] - a[i], mx);
                ans1 += max(a[i - 1] - a[i], (ll)0);
            }
        }
        for(int i = 0; i < n; ++i){
            if(i){
                    ans2 += min(mx, a[i - 1]);
            }
        }
        cout << "Case #" << qr + 1 << ": " << ans1 << " " << ans2 << "\n";
    }
}
