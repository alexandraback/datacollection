#include<stdio.h>
#include<string.h>
#include<math.h>
#include<string>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<cmath>
#include<deque>
#include<time.h>
#include<fstream>
#include<bitset>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
#define cl(x,v); memset(x,v,sizeof(x));
#define llINF 1ll<<60
#define INF 1<<29
#define EPS 1e-8
#define MID int mid=(l+r)>>1; int ls=o<<1; int rs=o<<1|1;
#define pii pair<int,int>
#define pli pair<long long,int>
#define pll pair<long long,long long>
#define pss pair<short,short>
#define psi pair<string,int>
#define F first
#define S second
#define PB push_back
#define BR puts("");
#define SCn scanf("%d",&n)
#define SCnm scanf("%d%d",&n,&m)
#define rep(i,s,n) for(int i=(s);i<=(n);++i)
#define rrep(i,s,n) for(int i=(s);i>=(n);--i)
#define TSC int T; scanf("%d",&T);
#define PI acos(-1.0)
#define test printf("test\n");
#define db double
typedef unsigned long long ull;
typedef long long ll;
int n;
int a[1005];
int main()
{
    int T;
    scanf("%d",&T);
    int Case=1;
    while(T--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int ans1=0;
        int Max=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1])ans1+=a[i]-a[i+1],Max=max(Max,a[i]-a[i+1]);
        }
        int ans2=0;
        for(int i=0;i<n-1;i++){
            ans2+=min(a[i],Max);
        }
        printf("Case #%d: %d %d\n",Case++,ans1,ans2);
    }
    return 0;
}
