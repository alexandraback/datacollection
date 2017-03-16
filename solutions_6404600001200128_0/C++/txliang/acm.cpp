#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <functional>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef long long ll;
#define INF 1e9
#define maxn 1005
#define maxm 100086+10
#define mod 100007
#define eps 1e-8
#define PI acos(-1.0)
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define scan(n) scanf("%d",&n)
#define scanll(n) scanf("%I64d",&n)
#define scan2(n,m) scanf("%d%d",&n,&m)
#define scans(s) scanf("%s",s);
#define ini(a) memset(a,0,sizeof(a))
#define out(n) printf("%d\n",n)
#define out1(ans,i,n) rep(i,n) printf("%d%c",ans[i],i==n-1?'\n':' ')
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int n;
int a[maxn];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt", "w", stdout);
#endif    
	int T;
	cin>>T;
	int cas = 1;
	while(T--)
	{
		cin>>n;
		rep(i, n) cin>>a[i];
		int y = 0, z = 0;
		int d = 0;
		for(int i = 1;i < n; i++)
		{
			if(a[i] < a[i-1]){
				y += a[i-1] - a[i];
				d = max(d, a[i-1] - a[i]);
			}
		}
		for(int i = 0;i < n - 1; i++)
		{
			z += min(d, a[i]);
		}
		printf("Case #%d: %d %d\n",cas++, y, z);
	}
	return 0;
}