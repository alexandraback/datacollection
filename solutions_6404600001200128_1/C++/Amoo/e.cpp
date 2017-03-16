//ITNOG
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define rep(i, s, e) for(int i = s; i < e; i ++)
//#define x first
//#define y second

const int maxN = 400*1000 + 5;
int mod = 1000*1000*1000 + 9;
int a[maxN];



void solve()
{
    int n; cin >> n;
    rep(i, 0, n) cin >> a[i];

    int ans1 = 0, ans2 = 0;
    rep(i, 0, n - 1) ans1 += max(a[i] - a[i + 1], 0LL);
    

    int mx = 0;
    rep(i, 0, n - 1) mx = max(mx, a[i] - a[i + 1]);

//    cout << mx << endl;

    rep(i, 0, n - 1)
    {
	  if(a[i] >= mx) { ans2 += mx; continue; }

	  ans2 += a[i];
    }

    
    cout << ans1 << ' ' << ans2 << endl;
}

main()
{
    ios::sync_with_stdio(0); cin.tie();
    int T; cin >> T;
    rep(i, 0, T)
    {
	  cout << "Case #" << i + 1 << ": ";
	  solve();
    }
    return 0;
}
