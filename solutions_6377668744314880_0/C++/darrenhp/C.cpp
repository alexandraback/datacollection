//Clibrary:
#include<cassert>
#include<cctype>
#include<cerrno>
//#include<cfenv>
#include<cfloat>
//#include<cinttypes>
#include<ciso646>
#include<climits>
#include<clocale>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
//#include<cstdbool>
#include<cstddef>
//#include<cstdint>
#include<cstdio>
#include<cstdlib>
#include<cstring>
//#include<ctgmath>
#include<ctime>
//#include<cuchar>
#include<cwchar>
#include<cwctype>
//Containers:
//#include<array>
#include<bitset>
#include<deque>
//#include<forward_list>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
//#include<unordered_map>
//#include<unordered_set>
#include<vector>
//Input/Output:
#include<fstream>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
//Other:
#include<algorithm>
//#include<chrono>
//#include<codecvt>
#include<complex>
#include<exception>
#include<functional>
//#include<initializer_list>
#include<iterator>
#include<limits>
#include<locale>
#include<memory>
#include<new>
#include<numeric>
//#include<random>
//#include<ratio>
//#include<regex>
#include<stdexcept>
#include<string>
//#include<system_error>
//#include<tuple>
//#include<typeindex>
#include<typeinfo>
//#include<type_traits>
#include<utility>
#include<valarray>
using namespace std;

typedef long long i64;
typedef unsigned long long u64;

typedef long long               ll;
typedef vector<int>             vi;
typedef vector<vi>              vvi;
typedef pair<int, int>          pii;
typedef vector<pii>             vii; // vector of integer pairs
typedef set<int>                si;
typedef map<string, int>        msi;

const i64 PI = acos(-1);

/*
 * __builtin_ffs  __builtin_clz  __builtin_ctz __builtin_popcount  __builtin_parity
 * sizeof CLOCKS_PER_SEC
 * (1 << (31 - __builtin_clz(100) ) == 64;
 * decltype // deprecated
 */
const int MAX_N = 1024 * 3;
struct P{
  i64 x, y;
  P() {}
  P(i64 _x, i64 _y): x(_x), y(_y) {}
  P operator+(P p) { return P(x  + p.x, y  + p.y);}
  P operator-(P p) { return P(x -p.x, y -p.y);}
  P operator*(i64 d) { return P(x*d, y*d);}
  i64 dot(P p) { return x * p.x + y * p.y;}
  i64 det(P p) { return x * p.y -y * p.x;}
};

bool cmp_x(const P &p, const P& q){
  if (p.x != q.x) return p.x < q.x;
  return p.y < q.y;
}
vector<P> convex_hull(P* ps, int n) {
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);
  for (int i = 0; i < n; i++) {
    while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) <= 0) k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}
int N;
P ps[MAX_N];
bool on_seq(P p1, P p2, P q){
  return (p1 - q) .det(p2-q) == 0 && (p1 - q).dot(p2 - q) <= 0;
}
bool isValid(P p, vector<P> &ps1) {
  for (size_t i = 0; i < ps1.size(); i++) {
    int j = (i + 1) % ps1.size();
    if (p.x == ps1[i].x && p.y == ps1[i].y) return true;
    if (on_seq(ps1[i], ps1[j], p)) return true;
  }
  return false;
}
int main(){
  ios_base::sync_with_stdio(false); 
  int T; cin >> T;
  for (int Case = 1; Case <= T; Case++) {
    cout << "Case #" << Case << ":" << endl;
    cin >> N;
    for (int i = 0; i < N; i++) cin >> ps[i].x >> ps[i].y;

    vector<int> ans(N, N);
    for (int mask = 0; mask < (1 << N); mask++) {
      vector<P> ps1;
      int cut = 0;
      for (int i = 0; i < N; i++) {
        if ((1 << i) & mask) cut++;
        else ps1.push_back(ps[i]);
      }
      if (cut == N) continue;
      auto ch = convex_hull(ps1.data(), ps1.size());
      for (int i = 0; i < N; i++) if (isValid(ps[i], ch)) {
        ans[i] = min(ans[i], cut);
      }
    }
    for (auto i: ans) cout << i << endl;
  }
}

