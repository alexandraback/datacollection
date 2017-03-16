#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cassert>
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cmath>

#define DEBUGLEVEL
#ifdef DEBUGLEVEL
#define dbg(fmt, args...) fprintf(stderr, fmt, ##args)
#else
#define dbg(fmt, args...)
#endif
#define REPS(i, s, n) for(int (i) = (s); (i) < (int)(n); ++(i))
#define REP(i, n) REPS(i, 0, n)
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
#define x first
#define y second
#define INFI 1234567890
#define INFL 1234567890123456789LL
typedef long long ll;

using namespace std;


#define IS_CORNER(i, j) ((i == 0 && j == 0) || (i == 0 && j == c - 1) || (i == r - 1 && j == 0) || (i == r - 1 && j == c - 1))

int solve (int r, int c, int n, int md) {
  int ans = 0;
  int cnt = 0;
  if (r == 1) {
    swap (r, c);
  }
  if (c == 1) {
    REP(i, r) {
      if (i % 2 == md && cnt < n) {
        cnt++;
      }
    }
    if (cnt == n) {
      return ans;
    }
    md ^= 1;
    REP(i, r) {
      if (i % 2 == md && cnt < n && (i == 0 || i == r - 1)) {
        cnt++;
        ans += 1;
      }
    }
    REP(i, r) {
      if (i % 2 == md && cnt < n && !(i == 0 || i == r - 1)) {
        cnt++;
        ans += 2;
      }
    }
    return ans;
  }
  REP(i, r) {
    REP(j, c) {
      if ((i + j) % 2 == md && cnt < n) {
        cnt++;
      }
    }
  }
  if (cnt == n) {
    return ans;
  }
  md ^= 1;
  REP(i, r) {
    REP(j, c) {
      if ((i + j) % 2 == md && cnt < n && IS_CORNER (i, j)) {
        cnt++;
        ans += 2;
      }
    }
  }
  REP(i, r) {
    REP(j, c) {
      if ((i + j) % 2 == md && cnt < n &&
          !IS_CORNER(i, j) &&
          (i == 0 || j == 0 || i == r - 1 || j == c - 1)) {
        cnt++;
        ans += 3;
      }
    }
  }
  return ans + (n - cnt) * 4;
}

int main() {
#ifdef DEBUG
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int _test_count;
    cin >> _test_count;
    REP(_test_i, _test_count) {
        dbg("Processing test %d\n", _test_i + 1);
        int r, c, n;
        cin >> r >> c >> n;
        int ans = min(solve(r, c, n, 0), solve(r, c, n, 1));
        printf("Case #%d: ", _test_i + 1);
        printf("%d\n", ans);
    }
    return 0;
}