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

typedef long long ll;
const int MAXB = 1010;

int B, N;
int arr[MAXB];
int ans;

bool solve(ll tm)
{
  ll lnum = 0;
  ll num = 0;
  for(int i=0; i<B; i++)
  {
    lnum += (tm-1) / arr[i] + 1;
    num += tm / arr[i] + 1;
  }
  if(tm == 0) lnum = 0;

  if(N > num) return false;
  if(N <= lnum) return true;
  int k = N - lnum;
  int cnt = 0;
  for(int i=0; i<B; i++)
  {
    if(tm % arr[i] == 0)
    {
      cnt++;
      if(cnt == k)
      {
        ans = i + 1;
      }
    }
  }
  return true;
}

int main()
{
  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>B>>N;
    for(int i=0; i<B; i++)
      cin>>arr[i];
    
    ll lb = 0, rb = 1E18;
    while(lb < rb)
    {
      ll mb = (lb + rb) / 2;
      if(solve(mb))
        rb = mb;
      else
        lb = mb + 1;
    }

    cout<<"Case #"<<t<<": "<<ans<<endl; 
  }
  return 0;
}
