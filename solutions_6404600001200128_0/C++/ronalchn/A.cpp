#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int T;

  cin >> T;

  for (int t=1;t<=T;t++) {
    int n;
    cin >> n;

    int ans1 = 0, maxrate = 0, ans2 = 0;
    int prev = 0;
    vector<int> ms;
    for (int i=0;i<n;i++) {
      int m;
      cin >> m;

      ans1 += max(prev - m, 0);
      maxrate = max(maxrate, prev - m);
      ms.push_back(m);

      prev = m;
    }
    for (int i=0;i<n - 1;i++) {
      ans2 += min(ms[i], maxrate);
    }

    printf("Case #%d: %d %d\n",t,ans1, ans2);
  }

}
