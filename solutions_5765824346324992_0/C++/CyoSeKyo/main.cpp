#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#define INF 1000000005
#define eps 1e-9
#define PI acos(-1.0)
#define K (0.017453292519943295769236907684886l)
#define LL long long

using namespace std;

const int maxn=1005;

int b,a[maxn],n,t[maxn];

int Gcd(int x,int y)
{
    if (y==0) return x; else return Gcd(y,x%y);
}

int Lcm(int x,int y)
{
    return x*y/Gcd(x,y);
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int cas=0,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&b,&n);
        for (int i=1;i<=b;i++)
            scanf("%d",&a[i]);
        int L=1;
        for (int i=1;i<=b;i++)
            L=Lcm(L,a[i]);
        int cnt=0;
        for (int i=1;i<=b;i++)
            cnt=cnt+L/a[i];
        n=n%cnt;
        if (n==0) n=cnt;
        memset(t,0,sizeof(t));
        int mint=INF,p;
        while(n--)
        {
            mint=INF;
            for (int i=1;i<=b;i++)
                if (t[i]<mint)
                {
                    mint=t[i];
                    p=i;
                }
            t[p]+=a[p];
        }
        printf("Case #%d: %d\n",++cas,p);
    }
    return 0;
}
