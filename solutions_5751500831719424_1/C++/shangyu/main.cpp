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
char s[N][N],sr[N][N];
int o[N][N];
int main()
{
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int i,k,t,n,j;
    int kk = 0;
    cin>>t;
    while(t--)
    {
        memset(o,0,sizeof(o));
        cin>>n;
        for(i = 1 ;i <= n ;i++)
        cin>>s[i];
        int tg = 0;
        int flag = 1;
        for(i = 1; i <= n ; i++)
        {
            int k = strlen(s[i]);
            int g = 1;
            o[i][g] = 1;
            sr[i][g] = s[i][0];
            for(j = 1; j < k;  j++)
            {
                if(s[i][j]!=s[i][j-1])
                {
                    g++;
                    o[i][g] = 1;
                    sr[i][g] = s[i][j];
                }
                else
                {
                    o[i][g]++;
                }
            }
            if(i==1)
            tg = g;
            else if(tg!=g)
            {
                flag = 0;
                break;
            }
        }
        printf("Case #%d: ",++kk);
        if(!flag)
        {
            puts("Fegla Won");
            continue;
        }
        int ans = 0;
        for(i = 1 ; i <= tg ; i++)
        {
            for(j = 2; j <= n; j++)
            {
                if(sr[j][i]!=sr[1][i])
                {
                    flag = 0;
                    break;
                }
            }
           // cout<<flag<<" "<<sr[1][i]<<" "<<sr[2][i]<<endl;
            if(!flag) break;
            int ts = INF;
            for(int e = 1 ; e <= 100 ; e++)
            {
                int ss = 0;
                for(j = 1 ; j <= n; j++)
                {
                    ss+=abs(o[j][i]-e);
                }
                ts = min(ts,ss);
            }
            ans+=ts;
        }
        if(flag)
        printf("%d\n",ans);
        else
        puts("Fegla Won");
    }
    return 0;
}
