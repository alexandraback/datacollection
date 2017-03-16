#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

long long m[10000];

int main()
{
#ifdef ACMTUYO
	freopen("A-large(1).in","r",stdin);
	freopen("A-large(1).out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int n;
		cin >> n;
		
		forn(i, n) cin >> m[i];
		
		long long ans1=0, ans2=0, best=0;
		forn(i, n-1)
		{
			long long como=max(0LL, m[i]-m[i+1]);
			ans1+=como;
			best=max(best, como);
		}
		
		forn(i, n-1)
		{
			ans2+=min(best, m[i]);
		}
		
		cout << "Case #" << tc+1 << ": " << ans1 << " " << ans2 << endl;
	}
	return 0;
}
