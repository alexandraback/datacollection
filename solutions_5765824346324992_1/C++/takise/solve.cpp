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

int B, N;
ll m[1000];

int main(void) {
  int TestCase, TC = 0;
  cin >> TestCase;
  while(TestCase != TC) {
    cout << "Case #" << ++TC << ": ";
    cin >> B >> N;
    REP(i, B) cin >> m[i];
    REP(i, B) {
      ll lb= -1, ub = 1000000000;
      while(ub - lb > 1) {
	ll mid = (lb + ub) / 2;
	ll cnt = 0;
	REP(j, B) {
	  if (i == j) continue;
	  cnt += (m[i] * mid - 1) / m[j] + 1;
	  if ((m[i] * mid) % m[j] == 0 && j < i) cnt++;
	}
	if (cnt + mid >= N - 1) ub = mid;
	else lb = mid;
      }
      int cnt = ub + 1;
      REP(j, B) {
	if (i == j) continue;
	cnt += (m[i] * ub - 1) / m[j] + 1;
	if ((m[i] * ub) % m[j] == 0 && j < i) cnt++;
      }
      if (cnt == N) cout << i + 1 << endl;
    }
  }
  return 0;
}
