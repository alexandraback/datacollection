#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(a) (a).begin(), (a).end()
#define inf 0x3f3f3f3f
#define pb(x) push_back(x)
#define sz(a) ((int)(a.size()))

#ifdef DEBUG
#include "/home/lucas/Topcoder/debug.h"
#define dbg(args...) do {cerr << #args << ": "; dbg,args; cerr << endl;} while(0)
#else
#define dbg(args...)
#endif

struct PT {
  ll x, y;
};
int n;
#define MAXN 4000
#define mp make_pair

PT pts[MAXN];
int perm[MAXN];
int ans[MAXN];

bool cmp(int i, int j) {
  return mp(pts[i].x, pts[i].y) < mp(pts[j].x, pts[j].y);
}

ll cross(int i, int j, int k) {
  return (pts[j].x - pts[i].x) * (pts[k].y - pts[i].y)
        -(pts[k].x - pts[i].x) * (pts[j].y - pts[i].y);
}

ll dot(int i, int j, int k) {
  return (pts[j].x-pts[i].x) * (pts[k].x - pts[i].x)
        +(pts[j].y-pts[i].y) * (pts[k].y - pts[i].y);
}

struct CmpInt {
  int a, b;
  CmpInt(int _a, int _b) {
    a=_a;
    b=_b;
  }
  bool operator()(int i, int j) {
    if (dot(a,b,i) < 0 && dot(a,b,j) > 0) return true;
    else if(dot(a,b,i) > 0 && dot(a,b,j) < 0) return false;
    else return cross(a,i,j) < 0;
  }

};

int main() {
  ios :: sync_with_stdio(0);
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    cin >> n;
    for(int i=0; i<n; i++) {
      cin >> pts[i].x >> pts[i].y;
      perm[i] = i;
    }
    sort(perm, perm+n, cmp);

    vector<int> dn,up;
    for(int j=0; j<n; j++) {
      int i = perm[j];
      while (dn.size() > 1 && cross(dn[dn.size()-2], dn.back(), i) < 0) dn.pop_back();
      while (up.size() > 1 && cross(up[up.size()-2], up.back(), i) > 0) up.pop_back();
      dn.pb(i);
      up.pb(i);
    }

    for(int i=sz(up)-2; i>0; i--) {
      dn.pb(up[i]);
    }

    memset(ans, inf, sizeof(int) * n);
    for(int i=0; i<sz(dn); i++) {
      ans[dn[i]] = 0;
      CmpInt cmp(dn[i], dn[(i+1)%sz(dn)]);

      vector<int> points;
      for(int j=0; j<n; j++) {
        if (j != dn[i]) {
          points.pb(j);
        } else {
          ans[j] = 0;
        }
      }
      sort(all(points), cmp);

      int lst = 0;
      int acc = 0;
      for(int j=1; j<=sz(points); j++) {
        if (j == sz(points) || cmp(points[lst], points[j])) {
          for(int k=lst; k<j; k++) {
            ans[points[k]] = min(acc, ans[points[k]]);
          }
          acc += j - lst;
          lst = j;
        }
      }
      lst = 0;
      acc = 0;
      reverse(all(points));
      for(int j=1; j<=sz(points); j++) {
        if (j == sz(points) || cmp(points[j], points[lst])) {
          for(int k=lst; k<j; k++) {
            ans[points[k]] = min(acc, ans[points[k]]);
          }
          acc += j - lst;
          lst = j;
        }
      }
    }

    printf("Case #%d:\n", cn);
    for(int i=0; i<n; i++) {
      printf("%d\n", ans[i]);
    }
  }
  return 0;
}
