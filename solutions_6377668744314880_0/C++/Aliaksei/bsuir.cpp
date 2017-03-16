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

struct pt{
	ll x, y;
};

struct lin
{
	ll a, b, c;
};

lin getl(pt p, pt q)
{
	lin l;
	l.a = p.y - q.y;
	l.b = q.x - p.x;
	l.c = - l.a * p.x - l.b * p.y;
	return l;
}

int getds(lin l, pt p)
{
	ll res = l.a * p.x + l.b * p.y + l.c;
	if(res < 0) return 0;
	if(res > 0) return 2;
	return 1;
}

void Solve()
{
	int t;
	cin >> t;
	FOR(tk, t)
	{
		int n; cin >> n;
		vector<pt> v(n);
		FOR(i,n)
		{
			cin >> v[i].x >> v[i].y;
		}
		vi ans(n, n+1);
		for(int i = 0; i < n; ++i) {
			int bst = n+1;
			if(n==1) bst = 0;
			for(int j = 0; j < n; ++j)
			{
				vi ms(3);
				if(i == j) continue;
				lin l = getl(v[i],v[j]);
				for(int k = 0; k < n; ++k)
					ms[getds(l, v[k])]++;
				bst = min(bst, min(ms[0], ms[2]));
				//ans[i] = min(ans[i], bst);
				//ans[j] = min(ans[j], min(ms[0], ms[2]));
			}	
			ans[i] = bst;			
		}
		printf("Case #%d:\n", tk+1);
		for(int i = 0; i < n; ++i)
			cout << ans[i] << "\n";
	}
}

int main()
{
	//std::cin.sync_with_stdio(false);
	//cin.tie(0);
	freopen("C1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	Solve();
}