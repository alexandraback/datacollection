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

vector< pair<int, char> > parties;
vector<char> sol;

int main()
{
#ifdef ACMTUYO
	freopen("A-small-attempt0(2).in","r",stdin);
	freopen("A-small-attempt0(2).out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int n;
		cin >> n;
		parties.clear();
		sol.clear();
		int R = 0;
		forn(i, n)
		{
			int k;
			cin >> k;
			R+=k;
			parties.push_back(make_pair(k, 'A'+i));
		}
		
		forn(i, R) {
			sort(parties.rbegin(), parties.rend());
			sol.push_back(parties[0].second);
			parties[0].first--;
		}
		
		cout << "Case #" << tc+1 << ":";
		forn(i, R) {
			if((R-i+1) %2 || i==0) cout << " ";
			cout << sol[i];
		}
		cout  << endl;
	}
	return 0;
}
