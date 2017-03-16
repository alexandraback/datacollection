#include <bits/stdc++.h>

using namespace std;

#ifdef ACMTUYO
struct RTC{~RTC(){cerr << "Time: " << clock() * 1.0 / CLOCKS_PER_SEC <<" seconds\n";}} runtimecount;
#define DBG(X) cerr << #X << " = " << X << '\n';
#else
struct RTC{};
#define DBG(X)
#endif

#define fast_io() ios_base::sync_with_stdio(false)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(c) (c).begin(),(c).end()
#define forn(i, n) for (int i = 0; i < (n); i++)
typedef long long int number;
const int maxn = 27;
int n;
int v[maxn];
int total;
vector<string> ans;
bool brute_force(int actual) {
  forn (i, n)
    if (2*v[i] > actual)
      return false;

  if (actual == 0)
    return true;
  //tomar uno solo
  forn (i, n)
    if (v[i] > 0) {
      v[i] -= 1;
      if (brute_force(actual - 1)) {
        ans.pb(string(1, 'A' + i));
        return true;
      }
      v[i] += 1;
    }
  //tomar dos
  forn (i, n) forn (j, n)
    if (v[i] > 0 && v[j] > 0) {
      v[i] -= 1;
      v[j] -= 1;
      if (brute_force(actual - 2)) {
        string tmp;
        tmp.pb('A' + i);
        tmp.pb('A' + j);
        ans.pb(tmp);
        return true;
      }
      v[i] += 1;
      v[j] += 1;
    }
  return false;
}
int main() {
  int casos;
  scanf("%d", &casos);
  for (int caso = 1; caso <= casos; caso++) {
    scanf("%d", &n);
    total = 0;
    forn (i, n) {
      scanf("%d", &v[i]);
      total += v[i];
    }
    ans.clear();
    brute_force(total);
    printf("Case #%d:", caso);
    for (int i = sz(ans) - 1; i >= 0; i--)
      printf(" %s", ans[i].c_str());
    printf("\n");
  }
  return 0;
}

