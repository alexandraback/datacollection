#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <iomanip>
inline int Max(int a,int b)
{
    return a>b?a:b;
}
inline int Min(int a,int b)
{
    return a<b?a:b;
}
const double pi=3.1415926;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> ii;
const long double inf=1000000007;
const long double eps=1e-6;
const int maxn=1005;
int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}
int g[10][10],v[10][10];
int use[20];
int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int cas,c=1;
    scanf("%d",&cas);
    while(cas--)
    {
        int n,m,flag=0,ans;
        memset(use,0,sizeof(use));
        scanf("%d",&n);
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                scanf("%d",&g[i][j]);
                if(i==n)
                    use[g[i][j]]=1;
            }
        }
        scanf("%d",&m);
        for(int i=1;i<=4;i++)
        {
            for(int j=1;j<=4;j++)
            {
                scanf("%d",&v[i][j]);
                if(i==m)
                {
                    if(use[v[i][j]])
                    {
                        ans=v[i][j];
                        flag++;
                    }
                }
            }
        }
        if(flag==0)
        {
            printf("Case #%d: Volunteer cheated!\n",c++);
        }
        else if(flag>1)
        {
            printf("Case #%d: Bad magician!\n",c++);
        }
        else
        {
            printf("Case #%d: %d\n",c++,ans);
        }
    }
    return 0;
}
