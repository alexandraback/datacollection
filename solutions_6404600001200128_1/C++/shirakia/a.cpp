#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

#define dd(x)  cerr << #x << " = " << (x) << endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define SORT(c) sort((c).begin(),(c).end())
#define PB push_back

using namespace std;

int main() {
  int ans = 0;
  int problem_num;

  cin >> problem_num;

  FOR(pn,0,problem_num) {
    int n;
    cin >> n;

    VI m;
    FOR(i,0,n) {
      int a;
      cin >> a;
      m.PB(a);
    }

    int ans1 = 0;
    int ans2 = 0;

    FOR(i,0,n-1) {
      if (m[i]>m[i+1]) ans1 += m[i] - m[i+1];
    }

    int max_i=0;
    int max_v=0;
    FOR(i,0,n-1) {
      if (max_v < m[i]-m[i+1]) {
        max_v = m[i]-m[i+1];
        max_i = i;
      }
    }

    FOR(i,0,n-1) {
      int current = 0;
      if (m[i] <= max_v) current = m[i];
      else current = max(m[i]-m[i+1], max_v);
      ans2 += current;
    }

    printf("Case #%d: %d %d\n", pn+1, ans1, ans2);
  }

  return 0;
}
