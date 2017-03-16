

#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>
#include <time.h>


#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-8



#define pii pair<int,int>
#define FFF freopen("test","r",stdin)
#define all(a) a.begin(),a.end()

using namespace std;


void output(i64 x)
{
    if(x<0) putchar('-'),x=-x;
    if(x==0)
    {
        putchar('0');
        return;
    }
    int a[20],num=0;
    while(x) a[++num]=x%10,x/=10;
    while(num>0) putchar('0'+a[num--]);
}

inline i64 myInt()
{
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    int flag=1;
    if(c=='-') flag=-1,c=getchar();
    i64 x=0;
    while(isdigit(c))
    {
        x=(x*10)+(c-'0');
        c=getchar();
    }
    if(-1==flag) return -x;
    return x;
}


const i64 INF=1e16;
const int mod=1000000007;
const int N=1000005;

int n,m;
int K;

int a[22][22];

i64 calCost()
{
    i64 ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i][j])
            {
                if(j+1<m&&a[i][j+1]) ans++;
                if(i+1<n&&a[i+1][j]) ans++;
            }
        }
    }
    return ans;
}

i64 cal()
{
    int t=n*m;
    if(K<=(n*m+1)/2) return 0;

    i64 ans=INF;
    for(int i=0;i<(1<<t);i++)
    {
        clr(a,0);
        int cnt=0;
        for(int j=0;j<t;j++) if(i&(1<<j))
        {
            a[j/m][j%m]=1;
            cnt++;
        }
        if(cnt!=K) continue;
        i64 tmp=calCost();
        if(tmp<ans) ans=tmp;
    }
    return ans;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
   freopen("A-small-attempt0.out","w",stdout);
  //  init();
    int T=myInt();
    int num=0;
    while(T--)
    {
        n=myInt();
        m=myInt();
        K=myInt();
        i64 ans=cal();



        printf("Case #%d: %lld\n",++num,ans);
      //  if(nn<N&&ans!=f[nn]) printf("%lld: %lld %lld\n",nn,ans,f[nn]);
    }
    return 0;
}

