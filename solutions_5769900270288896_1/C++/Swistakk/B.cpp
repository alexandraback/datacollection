#include <bits/stdc++.h>
#define MP make_pair
#define PB push_back
#define int long long
#define st first
#define nd second
#define rd third
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define RE(i, n) FOR(i, 1, n)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#ifdef LOCAL
#define debug(x) {cerr <<#x<<" = " <<x<<"\n"; }
#define debug2(x, y) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debug4(x, y, z, t) {cerr <<#x<<" = " <<x<<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<", "<<#t <<" = " <<t<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debug4(x,y,z,t)
#define debugv(x)
#define cerr if(0)cout
#endif
#define make(type, x) type x; cin>>x;
#define make2(type, x, y) type x, y; cin>>x>>y;
#define make3(type, x, y, z) type x, y, z; cin>>x>>y>>z;
#define make4(type, x, y, z, t) type x, y, z, t; cin>>x>>y>>z>>t;
#define next ____next
#define prev ____prev
#define left ____left
#define hash ____hash
using namespace std;
typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;

template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
template<class T1, class T2>
ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { A first; B second; C third; };
template<class T> void ResizeVec(T&, vector<int>) {}
template<class T> void ResizeVec(vector<T>& vec, vector<int> sz) {
  vec.resize(sz[0]); sz.erase(sz.begin()); if (sz.empty()) { return; }
  for (T& v : vec) { ResizeVec(v, sz); }
}
struct Sol {
  void Test() {
    make3(int, r, c, n);
    if (r > c) {
      swap(r, c);
    }
    if (r == 1) {
      VI is(c + 5);
      VI ord;
      VI vis(c + 5);
      for (int i = 1; i <= c; i += 2) {
        ord.PB(i);
        vis[i] = 1;
      }
      FORD (i, c, 1) {
        if (!vis[i]) {
          ord.PB(i);
        }
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        is[ord[i]] = 1;
        res += is[ord[i] - 1] + is[ord[i] + 1];
      }
      cout<<res<<"\n";
    } else {
      int per = 2 * r + 2 * c - 4;
      int zero = r * c / 2 + ((r & c) & 1);
      n -= zero;
      int num2 = 2;
      if (r % 2 == 1 && c % 2 == 1) {
        num2 = 0;
      }
      if (n <= 0) {
        cout<<"0\n";
        return;
      }
      per /= 2;
      VI pen;
      for (int i = 0; i < per; i++) {
        if (i < num2) {
          pen.PB(2);
        } else {
          pen.PB(3);
        }
      }
      for (int i = 0; i < r * c - zero - per; i++) {
        pen.PB(4);
      }
      int res = 0;
      for (int i = 0; i < n; i++) {
        res += pen[i];
      }
      if (r * c % 2 == 1) {
        VI lol;
        for (int i = 0; i < (r - 2) * (c - 2) / 2 + 1; i++) {
          lol.PB(4);
        }
        for (int i = 0; i < per - 4; i++) {
          lol.PB(3);
        }
        for (int i = 0; i < 4; i++) {
          lol.PB(2);
        }
        int all = (r - 1) * c + (c - 1) * r;
        n += zero;
        int take = r * c - n;
        int acc = 0;
        for (int i = 0; i < take; i++) {
          acc += lol[i];
        }
        mini(res, all - acc);
      } 
      cout<<res<<endl;
    }
  }
};



#undef int
int main() {
#define int long long

  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  
  make(int, T);
  RE (tt, T) {
    cout<<"Case #"<<tt<<": ";
    Sol sol;
    sol.Test();
  }
  return 0;
}
