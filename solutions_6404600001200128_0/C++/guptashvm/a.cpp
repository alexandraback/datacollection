#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n;
long long m[1005];
int main()
{
  cin >> t;
  for(int tcase = 1; tcase <= t; tcase++)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
    {
      cin >> m[i];
    }
    long long rate = 0;
    long long r1 = 0;
    for(int i = 1; i < n; i++)
    {
      if(m[i] < m[i-1])
      {
        r1 += m[i-1] - m[i];
        rate = max(rate, (m[i-1]-m[i]));
      }
    }
    long long r2 = 0;
    for(int i = 0; i < n-1; i++)
    {
      r2 += min((m[i]), rate);
    }
    cout << "Case #" << tcase << ": " << r1 << " " << r2 << endl;
  }
}
