#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define mp(a,b) make_pair((a), (b))
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define ROF(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(v) v.begin(),v.end()

int bs(vi v, int n)
{
	ll lo = 0, hi = 1000000000;
	int m = v.size();
	hi *= 10000000;
	
	FOR(i, 200)
	{
		ll mid = (lo + hi) / 2;
		ll cur = 0;
		FOR(j,m)
		{
			cur += (mid + v[j] - 1) / v[j];
		}
		if(cur >= n)
			hi = mid;
		else
			lo = mid;
	}

	ll cur = 0;
	FOR(j,m)
	{
		cur += (lo + v[j] - 1) / v[j];
	}

	FOR(i, m)
	{
		if(lo % v[i] == 0)
			++cur;
		if(cur == n)
			return i + 1;
	}
	return -1;

}


void Solve()
{
	int t;
	cin >> t;
	FOR(tk, t)
	{
		int b, n;
		cin >> b >> n;
		vi v(b);
		FOR(i,b) cin >> v[i];
		int ans = bs(v, n);
		assert(ans > 0);
		printf("Case #%d: %d\n", tk+1, ans);
	}
}

int main()
{
	//std::cin.sync_with_stdio(false);
	//cin.tie(0);
	freopen("B1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	Solve();
}