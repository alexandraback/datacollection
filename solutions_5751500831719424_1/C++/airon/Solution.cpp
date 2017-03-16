#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <functional>

#define pb push_back
#define mk make_pair
#define sqr(N) ((N)*(N))
#define F first
#define S second
#define maxn 101010

using namespace std;                         

typedef long long ll;

set < string > m;
int i, j, n, k;
string s[1111];

int main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin >> t;
  for(int test = 1; test <= t; test++) {
    printf("Case #%d: ", test);
    cin >> n;
    for(i = 1; i <= n; i++) cin >> s[i];
    m.clear();
    for(i = 1; i <= n; i++) {
      string d = "";
      for(j = 0; j < s[i].size(); j++) 
        if(j + 1 == s[i].size() || s[i][j] != s[i][j + 1]) d += s[i][j];
      m.insert(d);
    }
    if(m.size() > 1) {
      puts("Fegla Won");
      continue;
    }
    vector < int > g[1111];
    for(i = 1; i <= n; i++) {
      int cnt1 = 0, cnt2 = 0;
      string r = s[i];
      r += " ";
      for(j = 0; j < r.size() - 1; j++) {
        if(r[j] == r[j + 1]) cnt1++;
        else {
          cnt2++;
          g[cnt2].pb(cnt1 + 1);
          cnt1 = 0;
        } 
      }
    }
    int ans = 0;
    for(i = 1; g[i].size() > 0; i++) {
      int mx = 0;
      for(j = 0; j < g[i].size(); j++) if(mx < g[i][j]) mx = g[i][j];
      int best = 123456, cur;
      for(j = 1; j <= mx; j++) {
        cur = 0;
        for(int k = 0; k < g[i].size(); k++) cur += abs(j - g[i][k]);
        best = min(best, cur);
      }
      ans += best;
    }
    printf("%d\n", ans);
  }
  return 0;
}         