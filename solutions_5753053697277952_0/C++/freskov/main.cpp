#include <bits/stdc++.h>

using namespace std;

#define _ << " " <<
#define trace(a) #a << "=" << a
typedef long long ll;
typedef long double ld;

const int N = 33;
int n;
int p[N];

void solve() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> p[i];

  priority_queue<pair<int,int>> q;
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    q.push({p[i], i});
    sum += p[i];
  }

  if (sum & 1)
  {
    pair<int,int> x = q.top();
    q.pop();
    --x.first;
    sum -= 1;
    cout << (char)('A' + x.second) << " ";
    q.push(x);
  }

  while (sum > 0)
  {
    pair<int,int> x = q.top();
    q.pop();
    pair<int,int> y = q.top();
    q.pop();

    --x.first; --y.first;
    sum -= 2;
    cout << (char)('A' + x.second) << (char)('A' + y.second) << " ";
    q.push(x); q.push(y);
  }
  cout << endl;
}

int main() {
  int tcs; cin >> tcs;
  for (int tc = 1; tc <= tcs; ++tc)
  {
    cout << "Case #" << tc << ": ";
    solve();
  }
  return 0;
}

