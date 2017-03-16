#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

inline int in(){int x;scanf("%d",&x);return x;}
inline ll lcm(ll x, ll y){return x/__gcd(x,y)*y;}

int M[1010];

int main()
{
  int T = in();
  for (int c = 0; c < T; c++){
    int B;
    ll N;
    B = in();
    N = in() - 1;
    for (int i = 0; i < B; i++) M[i] = in();
    ll l = 1;
    for (int i = 0; i < B; i++) l = lcm(l, M[i]);
    ll n = 0;
    for (int i = 0; i < B; i++) n += l / M[i];
    N %= n;
    priority_queue<P> pq;
    for (int i = 0; i < B; i++) pq.push(P(0ll, -i));
    for (ll i = 0; i < N; i++){
      P p = pq.top();
      pq.pop();
      p.first -= M[-p.second];
      pq.push(p);
    }
    printf("Case #%d: %d\n", c + 1, -pq.top().second + 1);
    cerr << "Case " << c + 1 << ": end\n";
    cerr << l << " " << n << " " << N << "\n";
  }
  return 0;
}
