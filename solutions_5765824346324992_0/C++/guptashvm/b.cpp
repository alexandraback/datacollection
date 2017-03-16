#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
int t;
ll n;
ll b;
ll m[1005];
ll gcd(ll a, ll b)
{
  if(b == 0)
    return a;
  return gcd(b, a%b);
}
int main()
{
  cin >> t;
  for(int tcase = 1; tcase <= t; tcase++)
  {
    vector<pair<ll, int> > v;
    cin >> b >> n;
    n--;
    for(int i = 0; i < b; i++)
      cin >> m[i];
    ll lcm = 1;
    ll times = 0;
    for(int i = 0; i < b; i++)
    {
      lcm = (m[i] * lcm) / gcd(lcm, m[i]);
    }
    for(int i = 0; i < b; i++)
    {
      times += lcm / m[i];
    }
    n %= times;
    for(int i = 0; i < b; i++)
    {
      ll cur = 0; 
      while(cur <= lcm)
      {
        v.push_back(make_pair(cur, i));
        cur += m[i];
      }
    }
    sort(v.begin(), v.end());
    cout << "Case #" << tcase << ": " << v[n].second+1 << endl;
  }
}
