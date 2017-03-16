#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;

typedef i64 int_t;

typedef pair<i64, i64> pi;

typedef vector<int_t> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(auto i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

void Solver::solve() {
  i64 N;
  cin >> N;
  set<pi> P;
  i64 i;
  REP(0, N, i) {
    pi p;
    cin >> p.first;
    p.second = i;
    P.insert(p);
  }

  vector<string> ans;
  while(!P.empty()) {
    if(P.size() == 1) {
      auto it = P.begin();
      i64 remain = it->first;
      while(remain > 0) {
	ans.pb(string(1, char('A' + it->second)));
	remain--;
	if(remain > 0) {
	  ans.back() += char('A' + it->second);
	  remain--;
	}
      }
      P.erase(it);
    }
    else {
      pi p1 = *P.begin(); P.erase(P.begin());
      pi p2 = *P.begin(); P.erase(P.begin());

      ans.pb(string(1, char('A' + p1.second))); p1.first--;
      ans.back() += char('A' + p2.second); p2.first--;

      if(p1.first > 0) {
	P.insert(p1);
      }
      if(p2.first > 0) {
	P.insert(p2);
      }
    }
  }

  reverse(all(ans));

  tr(ans, a) {
    cout << " " << *a;
  }
  cout << endl;
}

int main(int argc, char *argv[]){
  i64 T;
  cin >> T;
  getchar();
  i64 t;

  REP(0, T, t) {
    Solver s;
    cout << "Case #" << t + 1 << ":";
    s.solve();
  }

  return 0;
}

