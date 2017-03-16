#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rep(i,s,e) for (int i=(s);i<(e);++i)
#define pb push_back
#define mk make_pair
#define fst first
#define snd second
#define all(x) (x).begin(),(x).end()
#define clr(x,y) memset(x,y,sizeof x)
#define contains(x,y) (x).find(y)!=(x).end()
#define endl "\n"

int dx[]={0,0,1,-1,1,-1,1,-1}, dy[]={-1,1,0,0,1,-1,-1,1};
const int mod = 1e9+7;

#define at(x, y) (i & (1 << ((y) * r + (x))))

int main() {
	ios::sync_with_stdio(0);
	cout << fixed << setprecision(16);

	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case #" << ti << ": ";
    int r, c, n;
    cin >> r >> c >> n;
    unsigned int min_sol = -1;
    rep(i,0,(1 << (r*c)))
      if (__builtin_popcount(i) == n) {
        unsigned int sol = 0;
        rep(x,0,r)
          rep(y,0,c)
            if (at(x, y)) {
              if (x < r-1 && at(x+1, y)) sol++;
              if (y < c-1 && at(x, y+1)) sol++;
            }
        min_sol = min(min_sol, sol);
      }
    cout << min_sol << endl;
	}
}
