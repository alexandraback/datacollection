#include <cstdio>
#include <algorithm>

using namespace std;

#define ll long long

const int N = 3e3+10;

int n;
struct point {
  int first,second,id;
} p[N];
int q[N],l[N],nl;
int ans[N];

inline bool comp (point a, point b) {
  if (a.first == b.first) {
    return a.second < b.second;
  } else {
    return a.first < b.first;
  }
}

inline bool left (ll a, ll b, ll c, ll d) {
  return a*d-b*c < 0;
}

inline void solve () {
  scanf ("%d", &n);
  for (int i = 0;i < n;i ++) {
    scanf ("%d %d", &p[i].first, &p[i].second);
    p[i].id = i;
    ans[i] = n;
  }

  sort (p, p+n, comp);

  for (int j = (1<<n)-1;j > 0;j --) {
    nl = 0;
    for (int i = 0;i < n;i ++) {
      if ((j >> i)&1) {
	l[nl ++] = i;
      }
    }

    int r = -1;
    q[++ r] = l[0];
    for (int i = 1;i < nl;i ++) {
      while (r > 0 and left (p[q[r]].first-p[q[r-1]].first, p[q[r]].second-p[q[r-1]].second, p[l[i]].first-p[q[r-1]].first, p[l[i]].second-p[q[r-1]].second)) r --;
      q[++ r] = l[i];
    }
    int k = r;
    for (int i = nl-2;i >= 0;i --) {
      while (r > k and left (p[q[r]].first-p[q[r-1]].first, p[q[r]].second-p[q[r-1]].second, p[l[i]].first-p[q[r-1]].first, p[l[i]].second-p[q[r-1]].second)) r --;
      q[++ r] = l[i];
    }

    for (int i = 0;i < r;i ++) {
      ans[p[q[i]].id] = min (ans[p[q[i]].id], n-nl);
    }
  }

  for (int i = 0;i < n;i ++) {
    printf ("%d\n", ans[i]);
  }
}

int main () {
  int t;
  scanf ("%d", &t);

  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d:\n", i);
    solve ();
  }
}
