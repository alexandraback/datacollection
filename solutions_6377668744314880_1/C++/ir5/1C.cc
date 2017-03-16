#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

class range {private: struct I{int x;int operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:range(int n):i({0}),n({n}){}range(int i,int n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};

void solve();

int main() {
  int T; cin >> T;
  for (int test : range(1, T+1)) {
    cout << "Case #" << test << ": ";
    solve();
  }
}

//=====

#include <complex>
typedef long double ld;
typedef complex<ld> P;
const ld EPS=1e-8, PI=acos(-1.0);
#define EQ(a,b) (abs((a)-(b)) < EPS)

struct IP {
  ll x, y;
  IP(){}
  IP(ll x, ll y) : x(x), y(y) {}
  IP operator+(const IP &rhs) const { return IP(x + rhs.x, y + rhs.y); }
  IP operator-(const IP &rhs) const { return IP(x - rhs.x, y - rhs.y); }
  IP operator-() const { return IP(0, 0) - *this; }

};

ll dot(IP p1, IP p2) { return p1.x * p2.x + p1.y * p2.y; }
ll cross(IP p1, IP p2) { return p1.x * p2.y - p1.y * p2.x; }
double arg(IP p) { return atan2(p.y, p.x); }

bool operator<(const IP& lhs, const IP& rhs) {
  if (dot(lhs, rhs) > 0 && cross(lhs, rhs) == 0) return false;
  return arg(lhs) < arg(rhs);
}

bool operator==(const IP& lhs, const IP& rhs) {
  return !(lhs < rhs) && !(rhs < lhs);
}

IP getp() { ll x, y; cin>>x>>y; return IP(x, y); }

int solve2(vector<IP> vp) {
  int n = vp.size();
  if (n <= 1) return 0;

  // int aaa=0;
  // cout <<endl;
  // for (auto p : vp) {
  //   cout << "           #" << p.x << " " << p.y << "   "<<aaa++<<endl;
  // }

  int ret = n;
  int prev = n, j = n;
  for (int k : range(1, n)) {
    if (cross(vp[0], vp[k]) <= 0) {
      prev = k - 1;
      j = k;
      break;
    }
  }
  // cout <<"        INIT" << j << endl;
  ret = prev;

  if (j == n) {
    // it should be already corner of convex hull
    return 0;
  }

  for (int i : range(1, n)) {
    prev--;
    for (; ; j = (j + 1) % n, prev++) {
      if (j == i) return 0;
      if (cross(vp[i], vp[j]) <= 0) {
        break;
      }
    }
    //cout<<       "          PREV"<<prev<<" "<<i<<" "<<j<<"   "<<n<<endl;
    ret = min(ret, prev);
  }

  return ret;
}

void solve() {
  cout << endl; // !!!

  int N; cin >> N;
  vector<IP> vp(N);
  for (int i : range(N)) vp[i] = getp();

  for (int i : range(N)) {
    vector<IP> vp2;
    for (int j : range(N)) if (j != i) {
      IP q = vp[j] - vp[i];
      vp2.push_back(q);
    }

    sort(vp2.begin(), vp2.end());
    auto unip = unique(vp2.begin(), vp2.end());
    vp2.erase(unip, vp2.end());

    // cout << i << ": ";
    cout << solve2(vp2) << endl;
  }
}
