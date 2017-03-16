#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdint>
#include <cstdio>
using namespace std;

int main() {
  int t; cin>>t;
  for (int cn=1;cn<=t;cn++){
    cout << "Case #" << cn << ": ";

    int n; cin>>n;
    vector<int> v(n);
    for (auto &i: v) cin>>i;

    int max_dec = 0;
    for (int i=0;i+1<n;i++){
      max_dec = max(max_dec, v[i] - v[i+1]);
    }

    int ans1=0, ans2=0;

    for (int i=0;i+1<n;i++){
      ans1 += max(0, v[i] - v[i+1]);
    }

    for (int i=0;i+1<n;i++){
      ans2 += min(v[i], max_dec);
    }

    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
