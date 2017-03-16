#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[105][105];
char q[105][105];
int ans[105][105];
int na[105];
int wa[105];
int gao(int a)
{
    int la=strlen(s[a]);
    int ip=1;
    char now=s[a][0];
    int an=0;
    q[a][0]=now;
    int iq=1;
    while(now)
    {
        if(now==s[a][ip])
        {
            ans[a][an]++;
            ip++;
        }
        else
        {
            q[a][iq]=s[a][ip];
            now=s[a][ip];
            ip++;
            iq++;
            an++;
        }
    }
    return an;
}
int ab(int a,int b)
{
    return a>b?a-b:b-a;
}
int main()
{
    freopen("mao.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,n;
    bool can;
    int anss;
    scanf("%d",&T);
    for(int cs=1; cs<=T; cs++)
    {
        memset(s,0,sizeof(s));
        memset(q,0,sizeof(q));
        memset(ans,0,sizeof(ans));
        memset(na,0,sizeof(na));
        memset(wa,0,sizeof(wa));
        can=true;
        scanf("%d",&n);
        for(int t=0; t<n; t++)
        {
            scanf("%s",s[t]);
            na[t]=gao(t);
        }
        for(int t=1; t<n; t++)
        {
            if(strcmp(q[0],q[t])!=0)
            {
                printf("Case #%d: Fegla Won\n",cs);
                can=false;
                break;
            }
        }
/*
        for(int t=0; t<n; t++)
        {
            for(int tt=0; tt<na[t]; tt++)
            {
                printf("%d ",ans[t][tt]);
            }
            puts("");
        }
*/

        if(can==false)continue;
        anss=0;
        int anip=0;
        for(int t=0; t<na[0]; t++)
        {
            anip=0;
            for(int tt=0; tt<n; tt++)
            {
                wa[anip++]=ans[tt][t];
            }
            sort(wa,wa+anip);
            for(int op=0; op<anip; op++)
                anss+=ab(wa[anip/2],wa[op]);
        }
        printf("Case #%d: %d\n",cs,anss);

    }
    return 0;
}
