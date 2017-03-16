#include <iostream>
#include <vector>
#include <queue>
using namespace std;

using Party = pair<int, char>;

void solve()
{
  int n, total = 0;
  cin >> n;
  priority_queue<Party> Q;
  for (int i = 0; i < n; ++i)
  {
    Party x;
    cin >> x.first;
    x.second = 'A' + i;
    total += x.first;
    Q.push(x);
  }

  while (total > 0)
  {
    Party x = Q.top();
    Q.pop();
    --x.first;
    --total;
    cout << " " << x.second;
    if (x.first > 0)
      Q.push(x);
    if (2 * Q.top().first > total)
    {
      x = Q.top();
      Q.pop();
      --x.first;
      --total;
      cout << x.second;
      if (x.first > 0)
        Q.push(x);
    }
  }
  cout << endl;
}

int main()
{
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas)
  {
    cout << "Case #" << cas << ":";
    solve();
  }
}
