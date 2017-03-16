#include <bits/stdc++.h>
#define pb push_back
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define ALL(x) x.begin(), x.end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
const int INF = 1 << 29;

int m[1000];

int main(void) {
  int TestCase, TC = 0;
  cin >> TestCase;
  while(TestCase != TC) {
    cout << "Case #" << ++TC << ": ";
    int N; cin >> N;
    REP(i, N) cin >> m[i];
    int res = 0;
    REP(i, N - 1) if (m[i + 1] < m[i]) res += m[i] - m[i + 1];
    cout << res << " ";
    res = 0;
    int ma = 0;
    REP(i, N - 1) if (m[i + 1] < m[i]) ma = max(ma, m[i] - m[i + 1]);
    REP(i, N - 1) res += min(m[i], ma);
    cout << res << endl;
  }
  return 0;
}
