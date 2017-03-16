#include <stdio.h>

typedef long long ll;

int t,n,b,m[10];

ll gcd(ll a,ll b){
    return !b?a:gcd(b,a%b);
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%d%d",&b,&n);
        ll p = 1;
        for(int i=0;i<b;i++){
            scanf("%d",&m[i]);
            p = p/gcd(p,m[i])*m[i];
        }
        int turn = 0;
        for(int i=0;i<b;i++){
            turn += p/m[i];
        }
        n %= turn;
        if(n == 0) n=turn;
        int a[10] = {0};
        int id=0;
        for(int i=0;i<n;i++){
            int tt=a[0];id=0;
            for(int j=0;j<b;j++) if(a[j]<tt){
                tt=a[j];
                id=j;
            }
            a[id] += m[id];
        }
        printf("Case #%d: %d\n",ca,id+1);
    }
    return 0;
}
