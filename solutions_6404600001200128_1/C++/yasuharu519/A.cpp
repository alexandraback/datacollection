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

#define rep(i,n) for(int i=0; i<n; i++) 
#define repa(i,s,e) for(int i=s; i<=e; i++)
#define repd(i,s,e) for(int i=s; i>=e; i--)

long solution1(const vector<int>& m)
{
  long res = 0;
  long before = m.front();

  for (int i = 1; i < m.size(); i++)
  {
    auto v = m[i];
    if (before > v)
    {
      res += (before - v);
    }

    before = v;
  }

  return res;
}

long solution2(const vector<int>& m)
{
  auto max = std::max(m.begin(), m.end());
  auto min = std::min(m.begin(), m.end());

  long rate = 0;
  for (int i = 1; i < m.size(); i++)
  {
    auto before = m[i -1];
    auto current = m[i];
    auto diff = before - current;

    if (diff > rate)
    {
      rate = diff;
    }
  }

  auto last = m.back();
  long sum = 0;

  for (int i = 0; i < m.size() - 1; i++)
  {
    long v = m[i];
    sum += std::min(v, rate);
  }

  return sum;
}

void solve(int i, const vector<int>& m)
{
  cout << "Case #" << (i+1) << ": " << solution1(m) << " " << solution2(m) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int T;
  cin >> T;
  
  for(int i = 0; i < T; i++)
  {
    int N;
    cin >> N;

    std::vector<int> m;
    for(int j = 0; j < N; j++)
    {
      int mj;
      cin >> mj;
      m.emplace_back(mj);
    }

    solve(i, m);
  }
}
