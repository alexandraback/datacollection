#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1111;
int a[N],txt = 1;
void solve(){
    int n;
    int s1,s2,vv;
    s1 = s2 = vv = 0;
    scanf("%d",&n);
    for(int i = 1 ; i <= n ; i ++){
        scanf("%d",&a[i]);
    }
    for(int i = 1 ; i < n ; i ++){
        s1 += max(a[i] - a[i + 1],0);
        vv = max(vv,a[i] - a[i + 1]);
    }
    for(int i = 1 ; i < n ; i ++){
        s2 += min(vv,a[i]);
    }
    printf("Case #%d: %d %d\n",txt ++,s1,s2);
}
int main()
{
    freopen("dataPA.in","r",stdin);
    freopen("dataPA.out","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
