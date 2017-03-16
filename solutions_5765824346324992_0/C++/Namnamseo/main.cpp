#include <cstdio>

typedef long long ll;

int t;
ll n;
int b;
ll data[1010];

ll count(ll time){
    ll ret=0;
    for(int i=0;i<b;++i) ret+=(time/data[i])+1;
    return ret;
}

int main()
{
    freopen("D:\\gcj\\input.txt","r",stdin);
    freopen("D:\\gcj\\output.txt","w",stdout);
    scanf("%d",&t);
    int tc;
for(tc=1;tc<=t;++tc){
    scanf("%d",&b);
    scanf("%I64d",&n);
    int i;
    for(i=0;i<b;++i){
        scanf("%I64d",data+i);
    }
    ll left=-1, right=1e16, mid;
    while(left+1!=right){
        mid=(left+right)/2;
        if(count(mid)<n) left=mid;
        else right=mid;
    }
    if(left==-1){
        printf("Case #%d: %I64d\n",tc,n);
        continue;
    }
    n-=count(left)+1;
    for(i=0;i<b;++i){
        if(!(right%data[i])){
            if(n==0) break;
            else --n;
        }
    }
    printf("Case #%d: %d\n",tc,i+1);
}
    return 0;
}
