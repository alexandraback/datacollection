#include<bits/stdc++.h>
using namespace std;

#define MAX 1111111
#define gi(n) scanf("%d",&n)
#define gl(n) scanf("%lld",&n)
#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define all(c) c.begin(), c.end()
#define MOD 1000000007
#define M_PI 3.14159265358979323846
#define tr(v, it) for(typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define mp make_pair
#define F first
#define S second
#define SET(p,v) memset(p, v, sizeof(p))
#define chkC(x,n) (x[n>>6]&(1<<((n>>1)&31)))
#define setC(x,n) (x[n>>6]|=(1<<((n>>1)&31)))
typedef long long ll;
typedef pair<long long int,long long int> pii;

long long int cnt[1 << 18];
long long int R, C, N;
 
long long int compute(long long int x)
{
	long long int ans = 0;
	for (long long int r = 0; r < R; r++)
	{
		for (long long int c = 0; c < C; c++)
		{
			if (c > 0 and (x & (1 << (r * C + c))) and (x & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 and (x & (1 << (r * C + c))) and (x & (1 << (r * C + c - C))))
				ans++;
		}
	}
	return ans;
}
 
int main() 
{
	freopen("B-large.in","r",stdin);
	freopen("B-l.txt","w",stdout);
	long long int T;
	gi(T);
	for (long long int t = 1; t <= T; t++)
	{
		
		gl(R);gl(C);gl(N);
 
		long long int bst = R * C * N * 100;
		for (long long int i = 1; i < (1 << (R * C)); i++)
		{
			cnt[i] = cnt[i - (i & -i)] + 1;
			if (cnt[i] == N) bst = min(bst, compute(i));
		}
		printf("Case #%lld: %lld\n", t, bst);
	}
	return 0;
}
