#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REV(i,b,a) for(int i=(a);i>=(b);i--)
#define mp make_pair
#define pb push_back
#define oo (1<<30)
#define sz(v) (int)v.size()
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
#define mem(s,v) memset(s,v,sizeof(s))
#define ppc(x) __builtin_popcount((x))
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define mt make_tuple // you can ignore
#define eb emplace_back
#define endl '\n'

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
  freopen("test.in", "rt", stdin);
  freopen("o.txt", "wt", stdout);
  int t;
  scanf ("%d", &t);
  FOR (cs, 1, t + 1) {
	  int n;
	  scanf ("%d", &n);
	  vpi v(n);
	  FOR (i , 0 , n)
	  	  scanf ("%d", &v[i].first), v[i].second = i;
	  printf ("Case #%d:", cs);
	  sort (rall(v));
	  while (v[0].first) {
		  int r = v[0].first + v[1].first;
		  if (n > 2)
			  r += v[2].first;
		  if (r == 3) {
			  v[0].first --;
			  char c = ('A' + v[0].second);
			  printf (" %c", c);
			  sort (rall(v));
			  continue;
		  }
		  if (v[0].first - v[1].first >= 2) {
			  v[0].first -= 2;
			  char c = ('A' + v[0].second);
			  printf (" %c%c", c, c);
		  }
		  else {
			  v[0].first --, v[1].first --;
			  char a = ('A' + v[0].second);
			  char b = ('A' + v[1].second);
			  printf (" %c%c", a, b);
		  }
		  sort (rall(v));
	  }
	  printf ("\n");
  }
  return 0;
}
