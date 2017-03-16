#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void checkMin(T &a, T b) { if(b<a) a=b; }
template<typename T> inline void checkMax(T &a, T b) { if(a<b) a=b; }
#define X first
#define Y second
#define MP make_pair
#define PB push_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for (int i=0;i<int(n);++i)
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;

int n;

void work() {
  cin >> n;
  vector<string> sv, sv2;
  vector<VI> iv(n);
  REP (i, n) {
    string s;
    cin >> s;
    sv.PB(s);
    for (int j = 0; j < SZ(s); ) {
      int k;
      for (k = 0; j + k < SZ(s) && s[j] == s[j + k]; ++k);
      iv[i].PB(k);
      j += k;
    }
    s.resize(unique(ALL(s)) - s.begin());
    sv2.PB(s);
  }

  REP (i, SZ(sv2) - 1) {
    if (sv2[i] != sv2[i + 1]) {
      printf("Fegla Won\n");
      return;
    }
  }

  int ans = 0;
  REP (i, SZ(iv[0])) {
    int t = ~0U >> 2;
    for (int k = 1; k <= 100; ++k) {
      int o = 0;
      REP (j, n) {
        o += abs(iv[j][i] - k);
      }
      checkMin(t, o);
    }
    ans += t;
  }
  printf("%d\n", ans);
}

int main() {
  int n_case;
  cin >> n_case;
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: ", index);
    work();
  }
  return 0;
}
