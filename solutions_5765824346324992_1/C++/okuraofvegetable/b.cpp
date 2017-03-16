#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int B,N;
ll M[1010];
ll C(ll x)
{
	ll sum = 0ll;
	for(int i=0;i<B;i++)sum += (x-1ll)/M[i]+1ll;
	return sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d %d",&B,&N);
		for(int i=0;i<B;i++)scanf("%lld",&M[i]);
		ll l = 0ll,r = 1000000000000000ll;
		while(r-l>1)
		{
			ll mid = (l+r)/2ll;
			if(C(mid)>=N)r = mid;
			else l = mid;
		}
		//cout << l << ' ' << r << endl;
		ll wait = N-C(l);
		int ans = -1,cnt = 0;
		for(int i=0;i<B;i++)if(l%M[i]==0)
		{
			cnt++;
			if(cnt==wait)
			{
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n",t+1,ans+1);
	}
	return 0;
}
