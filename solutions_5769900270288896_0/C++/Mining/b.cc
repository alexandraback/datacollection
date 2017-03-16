#include <iostream>
#include <vector>
#include <climits>
#include <map>
#include <string>

int evaluate(const std::vector< std::vector<bool> > &v, int x, int y)
{
  int c = 0;
  // vertical walls
  for (int i = 0; i < x; i++) {
    for (int j = 1; j < y; j++) {
      if (v[i][j] && v[i][j-1]) {
        c++;
      }
    }
  }
  // horizontal walls
  for (int i = 1; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (v[i][j] && v[i-1][j]) {
        c++;
      }
    }
  }
  return c;
}

int es(std::map<std::string, int> &m, std::vector< std::vector<bool> > &v, int n, int x, int y)
{
  if (n == 0) {
    return evaluate(v, x, y);
  }
  std::string s;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      s += v[i][j]?'Y':'N';
    }
  }
  if (m.count(s)) {
    return m[s];
  }
  int best = INT_MAX;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (!v[i][j]) {
        v[i][j] = true;
        int d = es(m, v, n-1, x, y);
        if (d < best) best = d;
        v[i][j] = false;
      }
    }
  }
  m[s] = best;
  return best;
}

int solve(int n, int x, int y)
{
  std::vector< std::vector<bool> > v(x, std::vector<bool>(y));
  std::map<std::string, int> m;
  return es(m, v, n, x, y);
}

int main()
{
  int c;
  std::cin >> c;
  for (int i = 1; i <= c; i++) {
    int n, x, y;
    std::cin >> x >> y >> n;
    std::cout << "Case #" << i << ": " << solve(n,x,y) << std::endl;
  }
  return 0;
}
