#include<bits/stdtr1c++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
ld cp(const pt &a, const pt &b) { return imag(conj(a)*b); }
inline bool cmp_lex_i(const pt &a, const pt &b)
{ return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }
pol chull(pol p) {
  sort(p.begin(), p.end(), cmp_lex_i); int top=0, bot=1; pol ch(2*p.size());
  for (int i=0, d=1; i < p.size() && i >= 0; i += d) {
    while (top > bot && cp(ch[top-1]-ch[top-2], p[i]-ch[top-2]) < 0) top--;
    ch[top++] = p[i]; if (i == p.size()-1) d = -1, bot = top;
  } ch.resize(max(1, top-1)); return ch; }

int T, N;

class compare { public:
    bool operator()(const pt a,const pt b) const {
      if (real(a) != real(b)) return real(a) < real(b);
      return imag(a) < imag(b);
    }
};

int main () {
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> N;
    pol tr; tr.reserve(N);
    map<pt, int, compare> m;
    for (int i = 0; i < N; ++i) { int a, b; cin >> a >> b; tr.push_back(pt(a, b)); m[tr[tr.size() - 1]] = i; }
    vector<int> res(N, -1);
    int visited = 0;
    map<int, int> v;
    for (int i = 0; i < N; ++i) visited += 1 << i;
    queue<pair<int, int> > q;
    q.push(make_pair(visited, 0));
    while (!q.empty()) {
      if (visited == 0) break;
      pair<int, int> top = q.front();
      q.pop();
      if (v[top.first]) continue;
      v[top.first] = true;
      pol p;
      for (int i = 0; i < N; ++i)
        if (top.first & 1 << i)
          p.push_back(tr[i]);
      p = chull(p);
      for (int i = 0; i < p.size(); ++i) {
        int at = m[p[i]];
        if (visited & 1 << at) {
          res[at] = top.second;
          visited -= 1 << at;
        }
      }
      for (int i = 0; i < N; ++i)
        if (top.first & 1 << i)
          q.push(make_pair(top.first - (1 << i), top.second + 1));
    }
    cout << "Case #" << t << ":" << endl;
    for (int i = 0; i < N; ++i)
      cout << res[i] << endl;
  }
  return 0;
}
