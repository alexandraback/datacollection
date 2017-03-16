#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<queue>
#include<iostream>
#include<sstream>
using namespace std;
int T,cas=0,x,A,B,cnt[17];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&A);
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            scanf("%d",&x);
            if(i+1==A)cnt[x]++;
        }
        scanf("%d",&B);
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
        {
            scanf("%d",&x);
            if(i+1==B)cnt[x]++;
        }
        int ans=0,ct=0;
        for(int i=1;i<=16;i++)
        if(cnt[i]==2)
        {
            ans=i;
            ct++;
        }
        printf("Case #%d: ",++cas);
        if(ct==0)puts("Volunteer cheated!");
        else if(ct==1)printf("%d\n",ans);
        else puts("Bad magician!");
    }
}
