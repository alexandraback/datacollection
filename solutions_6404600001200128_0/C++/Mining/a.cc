#include <iostream>
#include <vector>
#include <algorithm>

void solve(int t, const std::vector<int> &v)
{
  int mfirst = 0, msecond = 0;
  int max_d = 0;
  for (int i = 1; i < v.size(); i++) {
    int d = v[i-1] - v[i];
    if (d > 0) {
      mfirst += d;
    }
    if (d > max_d) {
      max_d = d;
    }
  }
  for (int i = 0; i < v.size()-1; i++) {
    msecond += std::min(v[i], max_d);
  }
  std::cout << "Case #" << t << ": " << mfirst << " " << msecond << std::endl;
}

int main()
{
  int T;
  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
    }
    solve(t, v);
  }
}
