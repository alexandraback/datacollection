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

const int maxn=10005;

int a[maxn],n,v[maxn*4];

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int cas=0,T,res1,res2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        res1=0; res2=INF;
        for (int i=2;i<=n;i++)
            if (a[i]<a[i-1]) res1=res1+a[i-1]-a[i];
        int cnt=1;
        for (int i=1;i<=n;i++)
        {
            v[1]=max(0,a[i]-a[i+1]);
            v[++cnt]=a[i];
        }
        for (int k=1;k<=1;k++)
        {
            int temp=0;
            for (int i=1;i<n;i++)
            {
                if (a[i]<=v[k]) temp=temp+a[i];
                else
                {
                    if (a[i]-a[i+1]>v[k]) { temp=-1; break; }
                    temp=temp+v[k];
                }
            }
            //if (v==5) printf("%d\n",temp);
            if (temp!=-1) res2=min(res2,temp);
        }
        printf("Case #%d: %d %d\n",++cas,res1,res2);
    }
    return 0;
}
