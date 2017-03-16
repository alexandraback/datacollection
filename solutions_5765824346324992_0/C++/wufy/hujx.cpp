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
int n,f[10],t[10],a[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
#endif
    int T,cas=1;
    sf(T);
    int b;
    while(T--){
    	printf("Case #%d: ",cas++);
    	sfd(b,n);
    	for(int i=1;i<=b;i++){
    		sf(f[i]);
    		t[i] = f[i];
    	}
    	if(b>=n){
    		printf("%d\n",n);
    		continue;
    	}
    	int Lcm=1;
    	for(int i=1;i<=b;i++)
    		Lcm=lcm(Lcm,f[i]);
    	int res=0;
    	for(int i=1;i<=b;i++){
    		res += (Lcm/f[i]);
    	}
    	n %= res;
    	if(n == 0)
    		n = res;
		if (b >= n) {
			printf("%d\n", n);
			continue;
		}
		n -= b;
    	int flag;
    	while(n){
    		int mmin = INF;
    		for(int i=1;i<=b;i++){
    			mmin = Min(mmin,f[i]);
    		}
    		for(int i=1;i<=b;i++){
    			f[i] -= mmin;
    			if(f[i] == 0){
    				n--;
    				if(n == 0){
    					flag = i;
    					break;
    				}
    				f[i] = t[i];
    			}
    		}
    		if(n == 0)
    			break;
    	}
    	printf("%d\n",flag);
    }
    return 0;
}
