#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
const double eps = 1e-9;
bool dcmp(double x){
    if (fabs(x) < eps) return 0;
    return x>0?1:-1;
}
int n;
int a[2000];
int main(){
freopen("A.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int T=1; T<=test; T++){
        ll ans1 = 0, ans2 = 0;
        scanf("%d", &n);
        for (int i=1; i<=n; i++){
            scanf("%d", &a[i]);
        }
        for (int i=2; i<=n; i++){
            if (a[i] < a[i-1]){
                ans1 += a[i-1] - a[i];
            }
        }
        int seg = 0;
        for (int i=1; i<n; i++){
            seg = max(seg, a[i]-a[i+1]);
        }
        double v = seg/10.0;
        for (int i=2; i<=n; i++){
            ans2 += min(a[i-1], seg);
        }
        printf("Case #%d: ", T);
        cout << ans1 << ' ' << ans2 << endl;
    }
    return 0;
}
