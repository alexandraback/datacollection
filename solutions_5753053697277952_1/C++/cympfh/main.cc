#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);++i)
#define loop for(;;)
#define trace(var) cerr<<">>> "<<#var<<" = "<<var<<endl;
#define sort_all(v) sort(begin(v), end(v))
#define inf (1e9)
#define eps (1e-9)
using Integer = long long;
using Real = long double;
const Real PI = acosl(-1);
using P = pair<int, int>;

template<class S, class T> inline
ostream& operator<<(ostream&os, pair<S,T> p) {
  return os << '(' << p.first << ", " << p.second << ')';
}

template<class T, class U> inline
ostream& operator<<(ostream&os, tuple<T,U> t) {
  return os << '(' << get<0>(t) << ", " << get<1>(t) << ')';
}

template<class S, class T, class U> inline
ostream& operator<<(ostream&os, tuple<S,T,U> t) {
  return os << '(' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << ')';
}

template<class T> inline
ostream& operator<<(ostream&os, set<T> v) {
  os << "(set"; for (T item: v) os << ' ' << item; os << ")"; return os;
}

template<class T> inline
ostream& operator<<(ostream&os, vector<T> v) {
  if (v.size() == 0) return os << "(empty)";
  os << v[0]; for (int i=1, len=v.size(); i<len; ++i) os << ' ' << v[i];
  return os;
}

template<class T> inline
istream& operator>>(istream&is, vector<T>&v) {
  rep (i, v.size()) is >> v[i]; return is;
}

//           ^   >  v   <
int dx[] = { -1, 0, 1,  0 };
int dy[] = {  0, 1, 0, -1 };

using vi = vector<int>;
using vvi = vector<vi>;
using vd = vector<double>;
using vvd = vector<vd>;
using vb = vector<bool>;
const string Takahashi = "Takahashi";
const string Aoki = "Aoki";

int main() {
  cin.tie(0);
  ios::sync_with_stdio(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  random_device dev;
  mt19937 rand(dev());

  int t; cin >> t;
  rep (_, t) {
    cout << "Case #" << (_+1) << ":";

    int n; cin >> n;
    int N=0;
    vector<pair<int,char>> xs;
    rep (i, n) {
      int x; cin >> x;
      N += x;
      xs.push_back(make_pair(
            -x,
            'A' + i
            ));
    }
    sort_all(xs);

    vector<string> ans;

    while (N > 0) {
      string a="";
      
      xs[0].first += 1;
      a += xs[0].second;
      --N;
      sort_all(xs);

      xs[0].first += 1;
      a += xs[0].second;
      --N;

      int mn = xs[0].first;
      rep (i, n) mn = min(xs[i].first, mn);

      if (-mn > N/2) {
        ++N;
        a = a.substr(0, 1);
        xs[0].first -= 1;
      }
      sort_all(xs);

      ans.push_back(a);
    }

    for (string&s: ans) cout << " " << s;
    cout << endl;

  }

  return 0;
}
