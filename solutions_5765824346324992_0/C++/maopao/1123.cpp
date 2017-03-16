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
struct barber
{
    int bgtim;
    int pos;
}bar[6],bb[1000005];
int btim[6];
int bn;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
bool cmp(barber a,barber b)
{
    if(a.bgtim==b.bgtim)
        return a.pos<b.pos;
    return a.bgtim<b.bgtim;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int t;
    int n;
    scanf("%d",&t);
    for(int cas=1; cas<=t; cas++)
    {
        memset(bb,0,sizeof(bb));
        bn=0;
        int nb,n;
        scanf("%d%d",&nb,&n);
        int leastcm=1;
        for(int i=0;i<nb;i++)
        {
            scanf("%d",&btim[i]);
            leastcm=lcm(leastcm,btim[i]);
        }
        for(int i=0;i<nb;i++)
        {
            for(int j=0;j<leastcm/btim[i];j++)
            {
                bb[bn].bgtim=j*btim[i];
                bb[bn++].pos=i+1;
            }
        }
        sort(bb,bb+bn,cmp);
        n=((n-1)%bn+bn)%bn;
        printf("Case #%d: %d\n",cas,bb[n].pos);
    }
    return 0;
}
