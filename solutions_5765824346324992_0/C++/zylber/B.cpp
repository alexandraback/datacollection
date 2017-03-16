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
	freopen("B-small-attempt0(1).in","r",stdin);
	freopen("B-small-attempt0(1).out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int b, n;
		cin >> b >> n;
		
		forn(i, b) cin >> m[i];
		
		long long top=1000000000000000LL, bot=-1;
		while(top-bot>1)
		{
			long long mid=(top+bot)/2LL;
			
			long long att=0;
			forn(i, b)
			{
				att+=mid/m[i]+1;
			}
			
			if(att<n)
			{
				bot=mid;
			}
			else
			{
				top=mid;
			}
		}
		
		long long att=0;
		if(bot>=0) forn(i, b) att+=bot/m[i]+1;
		
		int act=0;
		while(att<n)
		{
			if(top%m[act]==0) att++;
			act++;
		}
		
		cout << "Case #" << tc+1 << ": " << act << endl;
	}
	return 0;
}
