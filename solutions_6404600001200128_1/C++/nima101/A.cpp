#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <fstream>
#include <string>

using namespace std;

int main() {
  int tc, n, extra, mx = 0;
  string s;
  cin >> tc;
  for (int t=1; t<=tc; t++) {
    cin >> n;
    vector<int> v;
    mx = 0;
    for (int i=0; i<n; i++) {
      int tmp;
      cin >> tmp;
      v.push_back(tmp);
      if (i>0 && v[i] < v[i-1])
        mx = max(mx, v[i-1] - v[i]);
    }
    int res1=0, res2=0;
    for (int i=1; i<n; i++) {
      res1 += max(0, v[i-1] - v[i]);
      res2 += min(mx, v[i-1]);
    }

    cout << "Case #"<<t<<": "<< res1 << " " << res2 << endl;
  }

  return 0;
}
