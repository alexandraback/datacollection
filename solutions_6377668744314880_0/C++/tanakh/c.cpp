#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdint>
#include <cstdio>
using namespace std;

typedef pair<int64_t,int64_t> pt;

int64_t area(const pt &a, const pt &b, const pt &c)
{
  pt x(b.first-a.first, b.second-a.second);
  pt y(c.first-a.first, c.second-a.second);

  return x.first*y.second-x.second*y.first;
}

void solve()
{
  int n;cin>>n;
  vector<pt> p(n);
  for (auto &i: p) cin>>i.first>>i.second;

  for (int i=0;i<n;i++){
    int ans = n+1;

    if (n <= 3) {
      ans = 0;
    }
    else {
      for (int j=0;j<n;j++){
        if (i==j) continue;

        int l = 0, r = 0;
        for (int k=0;k<n;k++){
          int64_t t = area(p[i], p[j], p[k]);
          if (t > 0) l++;
          else if (t < 0) r++;
        }

        ans = min(ans, min(l, r));
      }
    }
    cout << ans << endl;
  }
}

int main() {
  int t; cin>>t;
  for (int cn=1;cn<=t;cn++){
    cout << "Case #" << cn << ":" << endl;

    solve();
    cout << flush;
  }
  return 0;
}
