#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <numeric>

using namespace std;

void solve(vector<pair<char, int>> v)
{
  if (v.empty())
    return;

  sort(begin(v), end(v), [] (auto p1, auto p2) { return p1.second > p2.second; });
  auto sum = accumulate(begin(v), end(v), 0, [] (auto a, auto p2) { return a + p2.second; });
  if (v[0].second == 1 && sum == 2)
  {
    cout << " " << v[0].first << v[1].first;
    v[0].second--;
    v[1].second--;
  }
  else if (v[0].second == v[1].second && v[0].second != 1)
  {
    cout << " " << v[0].first << v[1].first;
    v[0].second--;
    v[1].second--;
  }
  else if (v[0].second > 2)
  {
    cout << " " << v[0].first << v[0].first;
    v[0].second--;
    v[0].second--;
  }
  else 
  {
    cout << " " << v[0].first;
    v[0].second--;
  }
  
  auto rp = std::remove_if(begin(v), end(v), [] (auto p) { return p.second == 0; });
  v.erase(rp, end(v));
  solve(v);
}

int main()
{
  int t = 0;
  cin >> t;

  for (int i = 1; i <= t; ++i)
  {
    int n = 0;
    cin >> n;
    std::vector<pair<char, int>> v;
    for (char c = 'A'; c < 'A' + n; ++c)
    {
      int p = 0;
      cin >> p;
      v.push_back({c, p});
    }

    cout << "Case #" << i << ":";
    solve(v);
    cout << "\n";
  }

  return 0;
}
