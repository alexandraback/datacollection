#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

int gcd(int a, int b)
{
  while (b != 0)
  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int lcm(int a, int b)
{
  int d = gcd(a, b);
  return a*(b/d);
}

int solve()
{
  int B, N;
  int M[1009];
  cin >> B >> N;
  int l = 1;
  int c = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  for (int i = 0; i < B; ++i) {
    cin >> M[i];
    int nl = lcm(l, M[i]);
    if (l != nl)
      c *= nl/l;
    l = nl;
    c += l/M[i];
    q.push(make_pair(0, i));
  }
  N -= 1;
  N %= c;
  for (int i = 0; i < N; ++i) {
    int t, b;
    std::tie(t, b) = q.top();
    q.pop();
    q.push(make_pair(t+M[b], b));
  }
  return q.top().second;
}

int main()
{
  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i)
    cout << "Case #" << i << ": " << solve()+1 << endl;
  return 0;
}
