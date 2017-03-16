#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stdlib.h>
#include<vector>
#include<cmath>
#include<queue>
#include<set>
using namespace std;
#define N 105
#define LL long long
#define INF 0xfffffff
const double eps = 1e-8;
const double pi = acos(-1.0);
const double inf = ~0u>>2;
char s[N][N],s1[N],s2[N];
int o[N],p[N];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int i,k,t,n;
    int kk = 0;
    cin>>t;
    while(t--)
    {
        memset(o,0,sizeof(o));
        memset(p,0,sizeof(p));
        cin>>n;
        for(i = 1 ;i <= n ;i++)
        cin>>s[i];
        int k1 = strlen(s[1]),k2 = strlen(s[2]);
        int g = 1;
        o[1] = 1;
        s1[1] = s[1][0];
        for(i = 1 ; i < k1 ; i++)
        {
            if(s[1][i]!=s[1][i-1])
            {
                g++;
                o[g] = 1;
                s1[g] = s[1][i];
            }
            else
            {
                o[g]++;
            }
        }
        int e = 1;
        p[1] = 1;
        s2[1] = s[2][0];
        for(i = 1 ; i < k2 ; i++)
        {
            if(s[2][i]!=s[2][i-1])
            {
                e++;
                p[e] = 1;
                s2[e] = s[2][i];
            }
            else
            {
                p[e]++;
            }
        }
        printf("Case #%d: ",++kk);
        if(g!=e)
        {
            puts("Fegla Won");
            continue;
        }
        int flag = 1;
        int ans = 0;
        for(i = 1 ; i <= g ; i++)
        {
            if(s1[i]!=s2[i])
            {
                flag = 0;
                break;
            }
            else
            ans+=abs(o[i]-p[i]);
        }
        if(flag)
        printf("%d\n",ans);
        else
        puts("Fegla Won");
    }
    return 0;
}
