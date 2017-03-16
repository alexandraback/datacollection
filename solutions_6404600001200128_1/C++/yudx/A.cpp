#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<string.h>
#include<vector>
#include<map>
#include<set>
#include<iostream>

using namespace std;

typedef long long ll;

int n,a[1005];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,I=1,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",a+i);
        int r1=0,r2=0;
        for(i=1;i<n;i++) if(a[i]<a[i-1]) r1+=(a[i-1]-a[i]);
        double v=0;
        for(i=0;i<n-1;i++) v=max(v,(a[i]-a[i+1])/10.0);
        for(i=0;i<n-1;i++) r2+=min(a[i],int(10*v+1e-3));
        printf("Case #%d: %d %d\n",I++,r1,r2);
    }
    return 0;
}
