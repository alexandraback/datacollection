#include <bits/stdc++.h>
using namespace std;
const bool SUBMIT=true;
const int INF=0x3f3f3f3f;
const int MAXN=1010;
int a[MAXN];
int main()
{
    if(SUBMIT)
    {
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    }
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int maxdec=0;
        int ans1=0,ans2=0;
        for(int i=0;i+1<n;i++)
        {
            ans1+=max(0,a[i]-a[i+1]);
            maxdec=max(maxdec,a[i]-a[i+1]);
        }
        //printf("%d\n",maxdec);
        for(int i=0;i<n-1;i++) if(a[i]>=maxdec) ans2+=maxdec; else ans2+=a[i];
        printf("Case #%d: %d %d\n",tt,ans1,ans2);
    }
    return 0;
}
