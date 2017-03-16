#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<time.h>
#include<queue>
#include<stack>
#include<iterator>
#include<math.h>
#include<stdlib.h>
#include<limits.h>
#include<set>
#include<map>
//#define ONLINE_JUDGE
#define eps 1e-3
#define INF 0x7fffffff
#define FOR(i,a) for((i)=0;i<(a);(i)++)
#define MEM(a) (memset((a),0,sizeof(a)))
#define sfs(a) scanf("%s",a)
#define sf(a) scanf("%d",&a)
#define sfI(a) scanf("%I64d",&a)
#define pf(a) printf("%d\n",a)
#define pfI(a) printf("%I64d\n",a)
#define pfs(a) printf("%s\n",a)
#define sfd(a,b) scanf("%d%d",&a,&b)
#define sft(a,b,c)scanf("%d%d%d",&a,&b,&c)
#define for1(i,a,b) for(int i=(a);i<b;i++)
#define for2(i,a,b) for(int i=(a);i<=b;i++)
#define for3(i,a,b)for(int i=(b);i>=a;i--)
#define MEM1(a) memset(a,0,sizeof(a))
#define MEM2(a) memset(a,-1,sizeof(a))
const double PI=acos(-1.0);
template<class T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
template<class T> T lcm(T a,T b){return a/gcd(a,b)*b;}
template<class T> inline T Min(T a,T b){return a<b?a:b;}
template<class T> inline T Max(T a,T b){return a>b?a:b;}
using namespace std;
int n,f[1010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    int T,cas=1;
    sf(T);
    while(T--)
    {
    	printf("Case #%d: ",cas++);
    	sf(n);
    	for(int i=0;i<n;i++)
    		sf(f[i]);
    	int s1=0,s2=0,mx=0;
    	for(int i=0;i<n-1;i++)
    	{
    		if(f[i+1] < f[i])
    		{
    			int t=f[i]-f[i+1];
    			s1+=t;
    			mx=max(mx,t);
    		}
    	}
    	for(int i=0;i<n-1;i++)
    	{
    		if(f[i] <= mx)
    			s2+=f[i];
    		else
    			s2+=mx;
    	}
    	printf("%d %d\n",s1,s2);
    }
    return 0;
}
