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

int gcd(const int _a, const int _b) {
  int a = max(_a, _b);
  int b = min(_a, _b);
  while (b) {
    int tmp = a % b;
    a = b; b = tmp;
  }
  return a;
}
int lcm(const int a, const int b) {
  return a*b/gcd(a,b);
}

int main() {
  int ans = 0;
  int problem_num;

  cin >> problem_num;

  FOR(pn,0,problem_num) {
    int b,n;
    cin >> b >> n;
    VI m;
    VI time;
    FOR(i,0,b) {
      int a;
      cin >> a;
      m.PB(a);
      time.PB(0);
    }

    int x = m[0];
    FOR(i,1,b) x = lcm(x, m[i]);

    int loop_num = 0;
    FOR(i,0,b) loop_num += x / m[i];

    n = (n - 1)%loop_num+1;

    int ans = 0;

    FOR(i,0,n-1) {
      int min_j = 0;
      int min_v = 1000000;
      FOR(j,0,b) {
        if (time[j] < min_v) {
          min_j = j;
          min_v = time[j];
        }
      }
      if (min_v > 0) {
        FOR(j,0,b) time[j] -= min_v;
      }

      FOR(j,0,b) {
        if (time[j] == 0) {
          time[j] = m[j];
          break;
        }
      }
      // printf("%d %d %d %d %d\n", time[0], time[1], time[2], time[3], time[4]);
    }

    int min_j = 0;
    int min_v = 1000000;
    FOR(j,0,b) {
      if (time[j] < min_v) {
        min_j = j;
        min_v = time[j];
      }
    }
    ans = min_j + 1;
    printf("Case #%d: %d\n", pn+1, ans);
  }

  return 0;
}
