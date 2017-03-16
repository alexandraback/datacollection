#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> P;

int T, N, B;
int b[1000];
int main()
{
  cin >> T;
  for(int t = 0; t < T; t++)
  {
    cin >> B >> N;
    int x = 1;
    for(int i = 0; i < B; i++)
    {
      int a;
      cin >> a;
      b[i] = a;
      x = x * a / __gcd(x, a);
    }

    int m = 0;
    for(int i = 0; i < B; i++)
      m += x / b[i];

    N = N % m;
    if(!N)
      N = m;
    priority_queue<P, vector<P>, greater<P>> q;
    for(int i = 0; i < B; i++)
      q.push(make_pair(0, i));
    while(N > 1)
    {
      auto p = q.top(); q.pop();
      N--;
      int i = p.second;
      q.push(make_pair(p.first + b[i], i));
    }
    int ans = q.top().second;
    cout << "Case #" << t + 1 << ": " << ans + 1 << endl;
  }
}
