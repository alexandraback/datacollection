#include <iostream>
#include <sstream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <math.h>
#include <stack>
#include <queue>
#include <ctype.h>
#include <map>
#include <bitset>
#include <limits>
typedef long long ll;
#define filla(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define F first
#define S second
#define MOD 1000000007
using namespace std;
/*long long choose(int n,int k)
{
    if(k==0)
        return 1;
    else
    {
        long long f=1;
        if(k>n-k)
            k=n-k;
        int p=1;
        while(p<=k)
        {
            f*=n--;
            f/=p++;
        }
        return f;
    }
}
ll power(int a,int b)
{
    ll ret;
    if(b==0)
        return 1;
    if(b==1)
        return a;
    ret=power(a,b/2);
    ret=(ret*ret);
    if(b&1)
        ret=(ret*a);
    return ret;
}
bool cmp(int a,int b)
{
    return a>b;
}*/
int main()
{
    freopen("A-large (2).in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int z,i;
    for(z=1;z<=t;z++)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        vector<int> v;
        int m1,m2,p;
        m1=0;
        int k=n;
        printf("Case #%d: ",z);
        while(k>2)
        {
            m1=0;
            for(i=0;i<n;i++)
            {
                if(a[i]>m1)
                {
                    m1=a[i];
                    p=i;
                }
            }
            printf("%c ",(char)(65+p));
            a[p]--;
            if(a[p]==0)
                k--;
        }
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                p=a[i];
                v.pb(i);
            }
        }
        for(i=0;i<p;i++)
            printf("%c%c ",char(v[0]+65),char(v[1]+65)); 
        printf("\n");
    }
    return 0;
}