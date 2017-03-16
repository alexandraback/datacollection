#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int MaxN = 110;
const int inf = 1e9;

inline int myabs (int x) { return x < 0 ? -x : x; }

int N, p[MaxN];
string s[MaxN];
vector <int> v;

int calc (void) {
  int ret = inf;

  for (int i = 0; i < N; ++i) {
    int t = 0;
    for (int j = 0; j < N; ++j) 
      t += myabs(v[i] - v[j]);
    ret = min(ret, t);
  }

  return ret;
}

void solve (int c) {
  scanf("%d",&N);
  for (int i = 0; i < N; ++i)
    cin >> s[i];

  int res = 0;
  bool ok = true;

  memset(p, 0, sizeof(p));
  while (p[0] < s[0].size()) {
    char chr = s[0][p[0]];
    v.clear();
    
    for (int i = 0; i < N; ++i) {
      int tot = 0;
      while (p[i] < s[i].size() && s[i][p[i]] == chr) {
	++p[i];
	++tot;
      }
      if (tot == 0) 
	ok = false;	
      v.push_back(tot);
    }
    
    res += calc();
  }
  
  for (int i = 0; i < N; ++i)
    if (p[i] != s[i].size())
      ok = false;

  if (ok)
    printf("Case #%d: %d\n",c,res);
  else
    printf("Case #%d: Fegla won\n",c);
}

int main (void) {
  int t;
  scanf("%d",&t);
  for (int c = 1; c <= t; ++c)
    solve(c);
  return 0;
}
