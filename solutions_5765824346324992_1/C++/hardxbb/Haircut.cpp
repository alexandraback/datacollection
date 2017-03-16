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
int n,cnt;
int a[1005];
ll fun(ll x)
{
    ll ret=0;
    for(int i=0;i<n;i++){
        ret+=x/a[i]+1;
    }
    return ret;
}
ll solve()
{
    ll l,r,mid;
    l=0;r=1e17;
    while(l<r){
        mid=(l+r)>>1;
        ll y=fun(mid);
        if(y<cnt)l=mid+1;
        else r=mid;
    }
    return l;
}
int main()
{
    int T;
    scanf("%d",&T);
    int Case=1;
    while(T--)
    {
        scanf("%d%I64d",&n,&cnt);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        ll sec=solve();
        //printf("%I64d\n",sec);
        if(sec){
            cnt-=fun(sec-1);
        }
        int ans;
        for(int i=0;i<n;i++){
            if(sec%a[i]==0){
                cnt--;
                if(cnt==0){
                    ans=i+1;
                    break;
                }
            }
        }
        printf("Case #%d: %d\n",Case++,ans);
    }


}
