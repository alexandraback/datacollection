#include<bits/stdc++.h>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FZ(n) memset((n),0,sizeof(n))
#define FMO(n) memset((n),-1,sizeof(n))
#define MC(n,m) memcpy((n),(m),sizeof(n))
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define FOR(x,y) for(__typeof(y.begin())x=y.begin();x!=y.end();x++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
// Let's Fight!

const int MAXN = 3030;
const int INF = 1010101010;
typedef long long ll;
typedef pair<ll, ll> pll;

pll operator+(pll a, pll b){return MP(a.F+b.F, a.S+b.S);}
pll operator-(pll a, pll b){return MP(a.F-b.F, a.S-b.S);}
ll dot(pll a, pll b){return a.F*b.F+a.S*b.S;}
ll cross(pll a, pll b){return a.F*b.S-a.S*b.F;}

int N;
pll pt[MAXN];

bool anglecmp(const pll &a, const pll &b)
{
  return cross(a, b) > 0;
}

int solve(int v)
{
  vector<pll> vec1, vec2;
  for(int i=0; i<N; i++)
  {
    if(i==v) continue;
    pll p = pt[i] - pt[v];
    if(p.F>0 || (p.F==0 && p.S>0))
      vec1.PB(p);
    else
      vec2.PB(p);
  }
  sort(vec1.begin(), vec1.end(), anglecmp);
  sort(vec2.begin(), vec2.end(), anglecmp);

  for(int j=0; j<(int)vec2.size(); j++)
    vec1.PB(vec2[j]);

  // for(auto j:vec1) cout<<j.F<<","<<j.S<<" "; cout<<endl;
  
  int ans = INF;
  int ptr = 0;
  int L = vec1.size();
  for(int i=0; i<L; i++)
  {
    if(ptr == i-1) ptr = i;
    int j = (i+1)%L;
    if(cross(vec1[i], vec1[j]) == 0 && dot(vec1[i], vec1[j]) > 0) continue;
    while(1)
    {
      int nptr = ptr+1;
      int z = nptr % L;
      ll crs = cross(vec1[i], vec1[z]);
      if(crs<=0) break;
      ptr = nptr;
    }
    // cout<<i<<" / "<<ptr-i<<" ("<<i<<"~"<<ptr<<")"<<endl;
    ans = min(ans, ptr - i);
  }
  if(ans == INF) ans = 0;

  return ans;
}

int main()
{
  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>N;
    for(int i=0; i<N; i++)
      cin>>pt[i].F>>pt[i].S;
    cout<<"Case #"<<t<<":"<<endl;
    for(int i=0; i<N; i++)
      cout<<solve(i)<<endl;
  }

  return 0;
}
