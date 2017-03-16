#include <bits/stdc++.h>

using namespace std;

const int N = 100;
pair <int, int> p[N];
int n;

bool isGood() {
  for(int i = 0; i < n; ++i) {
    if(p[i].first != 0) return false;
  }
  return true;
}

vector <string> solve() {
  vector <string> plan;
  
  while(!isGood()) {
    for(int i = 0; i < n; i += 2) {
      if(p[i].first == 0) {
        i--;
        continue;
      }
      string x = ""; x += (char)(p[i].second + 'A');
      p[i].first--;
      if(i + 1 < n && p[i + 1].first > 0) {
        x += (char)(p[i + 1].second + 'A');
        p[i + 1].first--;
      }
      plan.push_back(x);
    }
  }
  reverse(plan.begin(), plan.end());
  return plan;
}

int main()
{
  freopen("IN.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  
  int t;
  scanf("%d", &t);
  
  for(int tt = 1; tt <= t; ++tt) {
    scanf("%d", &n);
    
    for(int i = 0; i < n; ++i) {
      scanf("%d", &p[i].first);
      p[i].second = i;
    }
    sort(p, p + n);
    vector < string > ans = solve();
    printf("Case #%d:", tt);
    for(int i = 0; i < ans.size(); ++i) {
      printf(" %s", ans[i].c_str());
    }
    printf("\n");
  }
  return(0);
}
