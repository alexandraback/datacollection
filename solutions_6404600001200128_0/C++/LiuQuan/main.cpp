#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int N=1111;
int T,n,rate,cas=0,a[N];
int ans1,ans2;


int main(){
    freopen("A-small-attempt0.in","rb",stdin);
    freopen("data.out","wb",stdout);
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        rate=ans1=ans2=0;

        for (int i=1; i<n; i++)
            if (a[i]>a[i+1]){
                ans1+=a[i]-a[i+1];
                rate=max(rate,a[i]-a[i+1]);
            }

        for (int i=1; i<n; i++)
            if (a[i]>rate) ans2+=rate;
                else ans2+=a[i];

        printf("Case #%d: %d %d\n",++cas,ans1,ans2);
    }
    return 0;
}
