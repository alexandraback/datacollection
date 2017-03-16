#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())
typedef long long LL;

int cs;
int a[105][105][2];
char s[105][105];
int na[105];
void solve() {
  int n;
  scanf("%d", &n);
  for(int i=0;i<n;i++) scanf("%s", s[i]);
  int bad = 0;
  for(int i=0;i<n;i++) {
    na[i] = 0;
    for(int j=0;s[i][j];j++) {
      if(!j || s[i][j]!=s[i][j-1]) {
        a[i][++na[i]][0] = (int)s[i][j];
        a[i][na[i]][1] = 1;
      } else
        a[i][na[i]][1]++;
    }
    if(na[i] != na[0]) bad = 1;
    for(int k=1;k<=na[i];k++) if(a[i][k][0] != a[0][k][0]) bad = 1;
  }
  
  printf("Case #%d: ", cs);
  if (bad) { puts("Fegla Won"); return ; }

  int ans=0;
  for(int i=1;i<=na[0];i++) {
    vector<int> x;
    for(int j=0;j<n;j++) x.push_back(a[j][i][1]);
    sort(x.begin(), x.end());
    int mid = x[SZ(x)/2];
    for(int j=0;j<n;j++) ans += abs(x[j]-mid);
  }
  printf("%d\n", ans);
}

int main(void) {
  int T;
  scanf("%d", &T);
  for(cs=1;cs<=T;cs++) solve();
  return 0;
}
