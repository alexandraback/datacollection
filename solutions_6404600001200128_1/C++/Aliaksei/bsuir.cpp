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
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

#define mp(a,b) make_pair((a), (b))
#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define ROF(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(v) v.begin(),v.end()


void Solve()
{
	int t;
	cin >> t;
	FOR(tk, t)
	{
		int n;
		cin >> n;
		vi v(n);
		FOR(i,n)
		{
			cin >> v[i]; //v[i]*=10;
		}
		int ans1 = 0;
		if(n==1)
		{
			printf("Case #%d: %d %d\n", tk+1, 0, 0);
			continue;
		}
		for(int i = 1;i < n; ++i)
		{
			if(v[i] < v[i-1])
				ans1 += v[i-1] - v[i];
		}
		int ans2 = 0;
		int mx = 0;
		for(int i = 1; i < n; ++i)
			if(v[i] < v[i-1])
				mx = max(mx, v[i-1] - v[i]);
		for(int i = 0; i < n-1; ++i)
			ans2 += min(mx, v[i]);
		printf("Case #%d: %d %d\n", tk+1, ans1, ans2);
	}
}

int main()
{
	//std::cin.sync_with_stdio(false);
	//cin.tie(0);
	freopen("A1.in", "r", stdin);
	freopen("A0.out", "w", stdout);
	Solve();
}