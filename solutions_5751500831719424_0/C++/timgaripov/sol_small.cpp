#include <cstdio>
#include <cassert>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


const int maxn = 200;
const int maxl = 200;
char s[maxn][maxl];

vector<pair<char, int> > v[maxn];

void split(char *s, vector<pair<char, int> > &v) {
  char p = s[0]; //s not empty
  assert(strlen(s) > 0); 
  v.clear();
  int i = 0;
  int cnt = 1;
  do {
    i++;
    while (s[i] && s[i] == p) {
       i++;
       cnt++;
    }
    v.push_back(make_pair(p, cnt));   
    cnt = 1;
    p = s[i];
  } while (s[i]);  
}

int n;

int main() {
  
  int tests;
  assert(scanf("%d", &tests) == 1);
  for (int test = 0; test < tests; test++) {
    printf("Case #%d: ", test + 1);
    assert(scanf("%d", &n) == 1);
    for (int i = 0; i < n; i++) {
      assert(scanf(" %s", s[i]) == 1);
      split(s[i], v[i]);
    }
    bool ok = true;
    int ans = 0;    
    for (int i = 1; i < n; i++) {
      if (v[i].size() != v[0].size()) {
        ok = false;
      }  
    }
    vector<int> w;
    for (int j = 0; j < int(v[0].size()); j++) {    
      w.clear();
      w.push_back(v[0][j].second);
      for (int i = 1; i < n; i++) {
        if (v[i][j].first != v[0][j].first)
          ok = false;
        else
          w.push_back(v[i][j].second);
      }
      if (ok) {
        sort(w.begin(), w.end());
        int m = int(w.size()) / 2;
        for (int i = 0; i < n; i++)
          ans += abs(w[i] - w[m]);
      }
    }
    if (!ok) {
      printf("Fegla Won\n");      
    }
    else
      printf("%d\n", ans);
  }
  
  return 0;
}