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

int b, n;

int check(int x)
{
    int ans = 0;
    rep(i, 0, b) ans += x / a[i];
    return ans + b;
}

void solve()
{
    cin >> b >> n;
    rep(i, 0, b) cin >> a[i];

    if(n <= b) { cout << n << endl; return; }

    int mi = mod * 100000;

    vector<int> v;

    rep(i, 0, b)
    {
	  int lo = 0, hi = mod;

	  while(hi - lo > 1)
	  {
		int mid = (hi + lo) >> 1;

		int sec = mid * a[i];
		if(check(sec) >= n) hi = mid;
		else lo = mid;
	  }

//	  cout << hi << endl;
//	  cout << check(hi * a[i]) << end
	  if(mi > hi * a[i]) mi = hi * a[i], v.clear();
	  if(mi == hi * a[i]) v.push_back(i);
    }

    int dd = check(mi - 1);
    
    int dis = n - dd; dis --;
    dis %= v.size();

    cout << v[dis] + 1 << endl;
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
