#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
int n,M[1111],txt = 1;
LL check(LL time){
    LL res = 0;
    for(int i = 1 ; i <= n ; i ++){
        res += time / M[i] + (time % M[i] != 0);
    }
    return res;
}
LL Find(LL tt){
    LL l = 0,r = 1e18;
    LL ans = 0;
    while(l + 1 < r){
        LL mid = (l + r) >> 1;
        LL tcnt = check(mid);
        if(tcnt >= tt) r = mid;
        else l = mid;
    }
    ans = r;
    if(check(l) >= tt) ans = l;
    return ans;
}
void solve(){
    LL aim;
    scanf("%d%I64d",&n,&aim);
    for(int i = 1 ; i <= n ; i ++) scanf("%d",&M[i]);
    LL ans = Find(aim),cnt = 0;
    ans --;
    for(int i = 1 ; i <= n ; i ++){
        aim -= ans / M[i] + (ans % M[i] != 0);
    }
    int res;
    for(int i = 1 ; i <= n ; i ++){
        if(ans % M[i] == 0){
            aim --;
            if(aim == 0){
                res = i;
                break;
            }
        }
    }
    printf("Case #%d: %d\n",txt ++,res);
    return;
}
int main()
{
    freopen("dataPB.in","r",stdin);
    freopen("dataPB.out","w",stdout);
    int _;
    scanf("%d",&_);
    while(_--) solve();
    return 0;
}
