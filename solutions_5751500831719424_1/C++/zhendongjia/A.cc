#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define REP(i,n) for (int i=0; i<(n); ++i)
#define ALL(c) c.begin(), c.end()
typedef vector<int> VI;
typedef pair<int, int> PII;
#define CLR(c,n) memset(c,n,sizeof(c))
template <class T> void checkmin(T &a, T b) { if (b<a) a=b; }
template <class T> void checkmax(T &a, T b) { if (b>a) a=b; }
#define TR(it, container) for(typeof(container.begin()) it = container.begin();\
it != container.end(); it++)
#define CONTAIN(it, container) (container.find(it)!=container.end())

int n, m;
string s[128], t;
int cnt[128][128];

string convert(string s) {
  char last = s[0];
  string t = "";
  REP(i, SZ(s)) {
    if (s[i] != last) {
      t += last;
      last = s[i];
    }
  }
  t += last;
  return t;
}

void convert(int col, string s) {
  int start = 0;
  REP(i, m) {
    int end = start;
    while (end < SZ(s) && s[end] == t[i]) ++end;
    cnt[i][col] = end - start;
    start = end;
  }
}

int check() {
  t = convert(s[0]);
  REP(i, n) if (convert(s[i]) != t) return -1;
  m = SZ(t);
  REP(i, n) convert(i, s[i]);
  int ans = 0;
  REP(i, m) {
    sort(cnt[i], cnt[i] + n);
    int mid = cnt[i][n/2];
    REP(j, n) ans += abs(mid - cnt[i][j]);
  }
  return ans;
}

int main(int argc, char *argv[]) {
  int tc; cin >> tc;
  FOR(ic, 1, tc) {
    printf("Case #%d: ", ic);
    cin >> n;
    REP(i, n) cin >> s[i];
    int ans = check();
    if (ans < 0) printf("Fegla Won\n");
    else printf("%d\n", ans);
  }
}
