//ITNOG
#include<bits/stdc++.h>

using namespace std;

//#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)

const int maxN = 1000*1000 + 5;
const int mod = 1000*1000*1000 + 7;

int a[20][20];
int check(int r, int c)
{
    int res = 0;
    rep(i,0,r)rep(j,0,c)
    {
	  if(i + 1 < r) if(a[i][j] && a[i + 1][j]) res ++;
	  if(j + 1 < c) if(a[i][j] && a[i][j + 1]) res ++;
    }
    return res;
}
int  solve()
{
    int r, c, n; cin >> r >> c >> n;
    int x = (r * c);
    int ans = mod;
    rep(mask,0,(1 << x))
    {
	  memset(a,0,sizeof a);
	  rep(i,0,r)rep(j,0,c)
	  {
		int ind = i * c + j;
//		if(__builtin_popcount(mask) == n) cout << (mask >> ind & 1) << ' ';
		if(mask >> ind & 1) a[i][j] = 1;
		else a[i][j] = 0;
		
	  }

//	  cout << mask << endl;
//	  if(__builtin_popcount(mask) == n) cout << check(r, c) << endl;
	  if(__builtin_popcount(mask) == n) ans = min(ans, check(r, c));
    }
    return ans;
}

main()
{
    ios::sync_with_stdio(0); cin.tie();
    int T; cin >> T;
    rep(i,1,T+1)
    {
	  cout << "Case #" << i << ": " << solve() << endl;
    }
    
    return 0;
}
