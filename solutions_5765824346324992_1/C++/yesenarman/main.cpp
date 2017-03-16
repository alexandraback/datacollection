#include <bits/stdc++.h>
#define vec vector
#define sz(c) int(c.size())
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define fori(i, a, b) for (int i = a; i <= (b); ++i)
#define ford(i, a, b) for (int i = a; i >= (b); --i)
using namespace std;
typedef long long int64;
typedef pair<int64,int64> pii;

int64 calc(const vec<int> &a, int64 t) {
  int64 res = 0;
  for (int i : a) {
    res += t / i;
    if (t % i > 0) res += 1;
  }
  return res;
}

void solve(int testcase) {
  cout << "Case #" << testcase << ": ";
  int n, b;
  cin >> b >> n;
  vec<int> a(b);
  forn(i, b)
    cin >> a[i];
  int64 l = 0, r = 1e15;
  //cerr << l << " " << r << endl;
  while (l < r) {
    int64 m = (l + r) / 2;
    if (calc(a, m) < n)
      l = m + 1;
    else
      r = m;
  }
  priority_queue<pii> q;
  int64 done = 0;
  forn(i, b) {
    int64 t = l / a[i];
    if (l % a[i] == 0) t -= 1;
    done += t;
    q.push(pii{-(t * a[i]), -i});
  }
  int64 res = -1;
  while (done < n) {
    done += 1;
    assert(!q.empty());
    res = -q.top().second;
    q.pop();
  }
  cout << res + 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int testcases;
  cin >> testcases;
  fori(testcase, 1, testcases) {
    cerr << "Case " << testcase << "/" << testcases << endl;
    solve(testcase);
  }

  return 0;
}
