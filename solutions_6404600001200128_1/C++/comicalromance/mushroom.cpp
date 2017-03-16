#include <cstdio>
#include <algorithm>
using namespace std;
long long hm[1001];
int main() {
    freopen("hey2.in","r",stdin);
    freopen("wow.in","w",stdout);
    long long t,a,i,j,maxx,sum,sum2;
    scanf("%lld",&t);
    for(i=0;i<t;i++) {
        scanf("%lld",&a);
        sum=sum2=maxx=0;
        scanf("%lld",&hm[0]);
        for(j=1;j<a;j++) {
            scanf("%lld",&hm[j]);
            if(hm[j]<=hm[j-1]) {
                sum+=hm[j-1]-hm[j];
                maxx=max(maxx,hm[j-1]-hm[j]);
            }
        }
        for(j=0;j<a-1;j++) {
            if(hm[j]<=maxx) sum2+=hm[j];
            else sum2+=maxx;
        }
        printf("Case #%lld: %lld %lld\n",i+1,sum,sum2);
    }
}
