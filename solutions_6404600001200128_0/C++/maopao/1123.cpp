#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
const int ifcheck=0;
int m[1005];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    int n;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        memset(m,0,sizeof(m));
        int tim1=0,tim2=0;
        int v=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&m[i]);
        }
        int upflag=1;
        for(int i=1; i<n; i++)
        {
            if(m[i]<m[i-1])
            {
                v=max(v,m[i-1]-m[i]);
                upflag=0;
                tim1+=m[i-1]-m[i];
            }
        }
        if(upflag)
        {
            printf("Case #%d: 0 0\n",cas);
        }
        else
        {

//            for(int i=down; i<=up; i++)
//            {
//                int ans=0;
//
//                for(int j=0; j<n-1; j++)
//                {
//                    if(m[j]<i*10)
//                        ans+=m[j];
//                    else
//                        ans+=i*10;
//                }
//                printf("%d %d\n",i,ans);
//                tim2=min(tim2,ans);
//            }
            for(int i=0;i<n-1;i++)
            {
                if(m[i]<v)
                        tim2+=m[i];
                    else
                        tim2+=v;
            }
            printf("Case #%d: %d %d\n",cas,tim1,tim2);
        }

    }
    return 0;
}
