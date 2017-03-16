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

const int MAXN = 1010;

int N;
int arr[MAXN];

int solve1()
{
  int ans = 0;
  int now = 0;
  for(int i=0; i<N; i++)
  {
    ans += max(0, now-arr[i]);
    now = arr[i];
  }
  return ans;
}

int solve2()
{
  int rate = 0;
  for(int i=1; i<N; i++)
    rate = max(rate, arr[i-1]-arr[i]);
  int ans = 0;
  for(int i=0; i<N-1; i++)
  {
    ans += min(rate, arr[i]);
  }
  return ans;
}

int main()
{
  IOS;
  int T;
  cin>>T;
  for(int t=1; t<=T; t++)
  {
    cin>>N;
    for(int i=0; i<N; i++)
      cin>>arr[i];
    cout<<"Case #"<<t<<": "<<solve1()<<" "<<solve2()<<endl;
  }
  return 0;
}
