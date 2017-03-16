#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < int(b); ++i)
#define trav(a, v) for(auto& a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define D(x) cerr << #x << " = " << x << endl

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(int tc) {
  printf("Case #%d: ", tc);
  int N;
  scanf("%d", &N);
  set<pair<int, int>, greater<pair<int, int>>> P;
  rep(i,0,N) {
    int a;
    scanf("%d", &a);
    P.emplace(a, i);
  }
  while (!P.empty()) {
    if (P.size() > 2) {
      auto mx = *P.begin();
      printf("%c ", mx.second + 'A');
      P.erase(P.begin());
      mx.first--;
      if (mx.first) {
        P.insert(mx);
      }
    } else {
      auto mx = *P.begin();
      P.erase(P.begin());
      auto mx2 = *P.begin();
      assert(mx.first == mx2.first);
      rep(i,0,mx.first) {
        printf("%c%c ", mx.second + 'A', mx2.second + 'A');
      }
      break;
    }
  }
  printf("\n");
}

int main() {
  int N;
  scanf("%d", &N);
  rep(i,1,N+1) solve(i);
}
