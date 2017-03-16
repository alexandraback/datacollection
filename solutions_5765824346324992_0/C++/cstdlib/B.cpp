#include <bits/stdc++.h>
#define rep(i, s, e) for(int i = s; i <= e; i++)
using namespace std;
typedef long long ll;
vector<int> M;
using namespace std;
ll gcd(ll a, ll b)
{
  if(a < b) gcd(b, a);
  if(b==0) return a;
  return gcd(b, a % b);
}
ll __lcm(ll a, ll b)
{
  ll u = gcd(a, b);
  return a / u * b / u * u;
}

int main()
{
  int T, B;
  long long N;
  int mk;

  cin>>T;
  rep(c, 1, T)
  {
    cin>>B>>N;
    M.clear();
    rep(i, 1, B) { cin >> mk; M.push_back(mk); }
    ll lcm = M[0];
    rep(i, 1, B - 1) { lcm = __lcm(lcm, M[i]); }
    long long t = 1, ans = 0;
    long long mod = 0;
    rep(i, 0, B - 1) { mod += lcm/M[i];}
    N -= M.size();
    if(N< 0) { ans = N + M.size(); }
    N %= mod;
    cerr<<mod<<endl;
    cerr<<N<<endl;
    if(N==0) ans = B;
    while(N > 0)
    {
      rep(j, 0, M.size() - 1)
      {
        if(t % M[j] == 0)
        {
          N -= 1;
          if(N==0) { ans = j + 1; break; } 
        }
      }
      t++;
    }
    printf("Case #%d: %lld\n", c, ans);
  }
  return 0;
}
