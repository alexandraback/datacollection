#include <cstdio>
#include <algorithm>
using namespace std;
int hm[1001];
int main() {
    freopen("hey2.in","r",stdin);
    freopen("wow.in","w",stdout);
    int t,a,i,j,maxx,sum,sum2;
    scanf("%d",&t);
    for(i=0;i<t;i++) {
        scanf("%d",&a);
        sum=sum2=maxx=0;
        scanf("%d",&hm[0]);
        for(j=1;j<a;j++) {
            scanf("%d",&hm[j]);
            if(hm[j]<=hm[j-1]) {
                sum+=hm[j-1]-hm[j];
                maxx=max(maxx,hm[j-1]-hm[j]);
            }
        }
        for(j=0;j<a-1;j++) {
            if(hm[j]<=maxx) sum2+=hm[j];
            else sum2+=maxx;
        }
        printf("Case #%d: %d %d\n",i+1,sum,sum2);
    }
}
