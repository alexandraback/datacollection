// In the name of Allah

#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for (int i = (a); i < (b); i ++)
#define rep(i,n) for (int i = 0; i < (n); i ++)
#define repd(i,n) for (int i = (n); i >= 0; i --)
#define PI 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int max_n = 1000+10;
int b [max_n];

int main()
{
	int T;
	cin >> T;
	rep (tt, T)
	{
		int n, you;
		cin >> n >> you;
		rep (i, n)
			scanf ("%d", &b[i]);
			
		ll lb = -1, ub = 1e16+10;
		while ( ub-lb > 1 )
		{
			ll mid = ub+lb >> 1;
			ll cnt = 0;
			rep (i, n)
				cnt += (mid+b[i]) / b[i];
			if ( cnt >= you )
				ub = mid;
			else
				lb = mid;
		}
		int ans = 0;
		rep (i, n)
			you -= (ub-1+b[i]) / b[i];
		if ( you < 0 )
			dbg (123);
		rep (i, n)
			if ( ub % b[i] == 0 )
			{
				you --;
				if ( you == 0 )
				{
					ans = i+1;
					break;
				}
			}
		
		printf ("Case #%d: %d\n", tt+1, ans);
		
	}
	
	return 0;
}
