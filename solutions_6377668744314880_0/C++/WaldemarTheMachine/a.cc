#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <queue>
#include <stack>
#include <iomanip>
#include <ctype.h>
#include <sstream>
#include <map>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <iostream>
 
using namespace std;

typedef long long LL;

#define FOR(i,n) for(int i = 0;i < n;i++)
#define MP make_pair
#define PB push_back
#define ALL(a) (a).begin(),(a).end()
#define PII pair<int, int>
#define PDD pair<double, double>
#define PSS pair<string, string>
#define PLL pair<long long, long long>
#define CLEAR(a) memset(a, 0, sizeof(a))
#define prev eruyvuy
#define INF 2000000007
#define next abc
const double EPS = 1E-7;
const LL mod = 1000000007;

using namespace std;

int n;

struct pt {
  LL x, y;

  pt(LL x, LL y) :x(x), y(y) {}
};

bool cmp (pt a, pt b) {
  return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

bool cw1 (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool ccw1 (pt a, pt b, pt c) {
  return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}

void convex_hull (vector<pt> & a) {
  if (a.size() == 1)  return;
  sort (a.begin(), a.end(), &cmp);
  pt p1 = a[0],  p2 = a.back();
  vector<pt> up, down;
  up.push_back (p1);
  down.push_back (p1);
  for (size_t i=1; i<a.size(); ++i) {
    if (i==a.size()-1 || cw (p1, a[i], p2)) {
      while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
        up.pop_back();
      up.push_back (a[i]);
    }
    if (i==a.size()-1 || ccw (p1, a[i], p2)) {
      while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
        down.pop_back();
      down.push_back (a[i]);
    }
  }
  a.clear();
  for (size_t i=0; i<up.size(); ++i)
    a.push_back (up[i]);
  for (size_t i=down.size()-2; i>0; --i)
    a.push_back (down[i]);
}

vector<pt> hull,all;

int ans(int idx) {
  int bst = INF,c1,c2;
  FOR(i, n) {
    if (i == idx)
      continue;

    c1=0,c2=0;
    FOR(j,n) {
      if (cw1(all[i],all[idx],all[j]))
        c1++;
      if (ccw1(all[i],all[idx],all[j]))
        c2++;

      //cout << idx << ' ' << c1 << ' ' << c2 << endl;

      bst = min(bst, n-c1);
      bst = min(bst, n-c2);
    }
  }
  return bst;
}

int main() {
  ios_base::sync_with_stdio(0);
  int t,idx=1;
  cin >> t;
  FOR(tt,t) {
    cin >> n;
    cout << "Case #" << idx++ << ":" << endl;

    hull.clear();
    all.clear();
    FOR(i, n) {
      LL x,y;
      cin >> x >> y;
      hull.push_back(pt(x,y));
      all.push_back(pt(x,y));
    }

    convex_hull(hull);
    set<PII> hullset;
    FOR(i, hull.size()) {
      hullset.insert(MP(hull[i].x, hull[i].y));
    }

    FOR(i, n) {
      if (hullset.find(MP(all[i].x, all[i].y)) != hullset.end()) {
        cout << 0 << endl;
      } else {
        cout << ans(i) << endl;
      }
    }
  }  

  return 0;
}
