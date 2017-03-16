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
#define maxn 100005
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
//ll gcd(ll a, ll b)
//{
//	return b == 0 ? a : gcd(b, a % b);
//}
//ll lcm(ll a, ll b)
//{
//	return a * b / gcd(a,b);
//}
int n,m;
ll a[maxn];
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
		cin>>m>>n;
		rep(i, m)
		{
			cin>>a[i];
		}
		int ans = 0;
		if(n <= m) ans = n;
		else
		{
			n -= m;
			ll L = 1, R = 1LL << 60;
			ll t = R;
			while(L <= R)
			{
				ll mid = (L + R) / 2;
				ll sum = 0;
				rep(i, m)
				{
					sum += mid / a[i];
				}
				if(sum >= n)
				{
					R = mid - 1;
					t = min(t, mid);
				}
				else 
					L = mid + 1;
			}
		//	cout<<t<<endl;
			ll s = 0;
			rep(i, m)
			{
				s += (t-1) / a[i];
			}
			rep(i, m)
			{
				if(t % a[i] == 0)
				{
					s++;
					if(s == n)
					{
						ans = i + 1;
						break;
					}
				}
			}
		}
		printf("Case #%d: %d\n",cas++,ans);
	}
	return 0;
}