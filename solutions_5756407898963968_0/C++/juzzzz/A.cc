#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <bitset>
#include <iterator>
#include <valarray>
#include <complex>
#include <utility>
#include <string>
#include <sstream>
#include <tuple>
#include <initializer_list>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(),(c).end()
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef tuple<int, int> tii;
template<typename T> ostream &operator<<(ostream &os, set<T> const &s);template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp);template<typename T> ostream &operator<<(ostream &os, vector<T> const &v);template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v);template<typename T> ostream &operator<<(ostream &os, set<T> const &s);
template<typename T> ostream &operator<<(ostream &os, set<T> const &s) { if (s.size() == 0) return os << "{}"; os << "{"; decltype(s.begin()) iter; for (iter = s.begin(), ++iter; iter != s.end(); ++iter) { --iter; os << *iter << ", "; ++iter; } --iter; os << *iter << '}'; return os; }
template<typename T, typename U> ostream &operator<<(ostream &os, map<T, U> const &mp) { if (mp.size() == 0) return os << "{}"; os << "{" << endl; decltype(mp.begin()) iter; for (iter = mp.begin(), ++iter; iter != mp.end(); ++iter) { --iter; os << "  {" << iter->first << ", " << iter->second << "}," << endl; ++iter; } --iter; os << "  {" << iter->first << ", " << iter->second << "}" << endl << '}'; return os; }
template<typename T> ostream &operator<<(ostream &os, vector<T> const &v) { os << '['; rep(i, v.size()-1) os << v[i] << ", "; if (v.size() > 0) os << v[v.size()-1]; cerr << ']'; return os; }
template<typename T, unsigned N, unsigned Last> struct TuplePrinter { static void print(ostream &os, T const& v) { os << std::get<N>(v) << ", "; TuplePrinter<T, N + 1, Last>::print(os, v); } };
template<typename T, unsigned N> struct TuplePrinter<T, N, N> { static void print(ostream &os, T const &v) { os << std::get<N>(v); } };
template<typename... Types> ostream& operator<<(ostream &os, tuple<Types...> const &v) { os << "("; TuplePrinter<tuple<Types...>, 0, sizeof...(Types) - 1>::print(os, v); os << ")"; return os; }
template<typename T> void dbg(T const &t) { cerr << t << endl; }
template<typename T, typename... Args> void dbg(T const &t, Args... args) { cerr << t << " "; dbg(args...); }

const ll infty = 1223372036854775807;
const double eps = 1e-8;


const int N = 4;

void solve() {
  int n;
  cin >> n; --n;
  set<int> fst, snd;
  rep(i, N) {
    rep(j, N) {
      int tmp;
      cin >> tmp;
      if (i == n) fst.insert(tmp);
    }
  }
  cin >> n; --n;
  rep(i, N) {
    rep(j, N) {
      int tmp;
      cin >> tmp;
      if (i == n) snd.insert(tmp);
    }
  }
  set<int> res;
  set_intersection(all(fst), all(snd), inserter(res, res.end()));
  if (res.size() == 1) {
    cout << *res.begin();
  } else if (res.size() == 0) {
    cout << "Volunteer cheated!";
  } else {
    cout << "Bad magician!";
  }
}

int main(int argc, char *argv[]) {
  // cin.tie(0); cout.sync_with_stdio(false);
  int TT;
  cin >> TT;
  rep(I, TT) {
    cout << "Case #" << I+1 << ": "; solve(); cout << endl;
  }
  return 0;
}
