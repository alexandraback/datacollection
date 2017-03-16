#include <bits/stdc++.h>
#include <ext/hash_map>

using namespace std;
using namespace __gnu_cxx;

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
#define iter(it,s) for(__typeof(s.begin())it = s.begin();it!=s.end();it++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pi;
typedef vector<pi> vpi;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int arr[20][20];
int res;

void calc(int r, int c, int n) {
  FOR (msk , 0 , (1 << r))
  {
    mem(arr, 0);
    int p = ppc(msk);
    if (p * c < n || !p)
      continue;
    int d = n / p, rem = n % p;
    FOR (i, 0 , r)
    {
      if ((msk >> i) & 1) {
        int cnt = -(rem > 0);
        rem--;
        FOR (j , 0 , c)
        {
          if (cnt < d)
            arr[i][j] = 1, cnt++;
          j++;
        }
        for (int j = c - 1 - (c & 1); j >= 0; j -= 2) {
          if (cnt < d)
            arr[i][j] = 1, cnt++;
        }
      }
      i++;
    }
    for (int i = r - 1 - (r & 1); i >= 0; i -= 2) {
      if ((msk >> i) & 1) {
        int cnt = -(rem > 0);
        rem--;
        FOR (j , 0 , c)
        {
          if (cnt < d)
            arr[i][j] = 1, cnt++;
          j++;
        }
        for (int j = c - 1 - (c & 1); j >= 0; j -= 2) {
          if (cnt < d)
            arr[i][j] = 1, cnt++;
        }
      }
    }
    int cnt = 0;
    FOR (i , 0 , r)
    {
      FOR (j , 0 , c)
      {
        if (i && arr[i][j] && arr[i - 1][j])
          cnt++;
        if (j && arr[i][j] && arr[i][j - 1])
          cnt++;
      }
    }
    res = min(res, cnt);
  }
  if (!n)
    res = 0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("b3.in", "rt", stdin);
	freopen("o.txt", "wt", stdout);
#endif
  int t;
  scanf("%d", &t);
  FOR (cs, 1 , t + 1)
  {
    int r, c, n;
    scanf("%d%d%d", &r, &c, &n);
    res = oo;
    calc(r, c, n);
    calc(c, r, n);
    printf("Case #%d: %d\n", cs, res);
  }
  return 0;
}
