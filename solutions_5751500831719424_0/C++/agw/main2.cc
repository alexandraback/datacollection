#include <algorithm>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>


#define INF 1000000000
#define MOD 1000000007
#define ALL(x) std::begin(x), std::end(x)


std::string shortest(const std::string& s)
{
  std::string t;

  for (int i = 0, size = s.size(); i < size; i ++)
    if (i == 0) {
      t += s[i];
    }
    else if (s[i - 1] != s[i]){
      t += s[i];
    }

  return t;
}

bool early_test(const std::vector<std::string>& a)
{
  for (int i = 1, size = a.size(); i < size; i ++)
    if (a[i] != a[0])
      return false;

  return true;
}

int remove(std::string& s)
{
  int i = s.find_first_not_of(s.front());

  if (i == -1) {
    i = s.size();

    s.clear();

    return i;
  }
  else {
    s.erase(std::begin(s), std::begin(s) + i);

    return i;
  }
}

int smallest_alternation(const std::vector<int>& a)
{
  int cm = INF;

  for (int i = 0; i < 111; i ++) {
    int c = 0;

    for (const auto& j : a)
      c += std::abs(i - j);

    cm = std::min(c, cm);
  }
  
  return cm;
}


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T, N;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::cin >> N;

    std::vector<std::string> a(N), b(N);

    for (int i = 0; i < N; i ++)
      std::cin >> a[i];

    std::transform(ALL(a), std::begin(b), shortest);

    if (early_test(b)) {
      int s = 0;

      for (const auto& j : b[0]) {
        std::vector<int> c(N);

        for (int k = 0; k < N; k ++)
          c[k] = remove(a[k]);

        s += smallest_alternation(c);
      }

      std::cout << "Case #" << t << ": " << s << std::endl;
    }
    else {
      std::cout << "Case #" << t << ": Fegla Won" << std::endl;
    }
  }

  return 0;
}
