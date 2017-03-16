#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <list>
#include <string>
#include <utility>
#include <vector>

using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using ll = long long;

#define rep(i, n) for (int i = 0; i < n; i++)
#define repa(i, s, e) for (int i = s; i <= e; i++)
#define repd(i, s, e) for (int i = s; i >= e; i--)

int gcd(int m, int n)
{
  if ((0 == m) || (0 == n))
    return 0;

  while (m != n)
  {
    if (m > n)
      m = m - n;
    else
      n = n - m;
  }
  return m;
}

int lcm(int m, int n)
{
  if ((0 == m) || (0 == n))
    return 0;

  return ((m / gcd(m, n)) * n);
}

ll solve(vi& barbar, const ll& N)
{
  auto minimal = 1;
  for (auto v : barbar)
  {
    minimal = lcm(minimal, v);
  }

  auto round = 0;
  for (auto v : barbar)
  {
    round += (minimal / v);
  }

  auto line = N % round;

  vi counter;
  for (int i = 0; i < barbar.size(); i++)
  {
    counter.emplace_back(0);
  }

  if (line == 0)
  {
    line = round;
  }

  // std::cout << std::endl;
  // std::cout << "round: " << round << std::endl;
  // std::cout << "line: " << line << std::endl;

  auto answer = 1;

  auto count = 0;
  long time = 0;

  while (count != line)
  {

    bool f = false;
    for (int j = 0; j < counter.size(); j++)
    {
      if (counter[j] == 0)
      {
        counter[j] += barbar[j];
        answer = j + 1;

        count++;

        f = true;
        break;
      }
    }

    if (!f)
    {
      // delete
      for (int j = 0; j < counter.size(); j++)
      {
        if (counter[j] != 0)
        {
          counter[j] -= 1;
        }
      }
    }

    time++;
  }

  return answer;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;

  for (int i = 0; i < T; i++)
  {
    int B;
    ll N;

    cin >> B >> N;

    vi barbar;
    for (int j = 0; j < B; j++)
    {
      int b;
      cin >> b;

      barbar.emplace_back(b);
    }

    cout << "Case #" << (i + 1) << ": " << solve(barbar, N) << endl;
  }
}
