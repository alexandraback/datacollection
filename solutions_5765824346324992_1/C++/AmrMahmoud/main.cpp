#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <limits>
#include <utility>
#include <iomanip>
#include <set>
#include <numeric>
#include <cassert>

#define INF_MAX 2147483647
#define INF_MIN -2147483647
#define INF_LL 9223372036854775807LL
#define INF 1000000000
#define PI acos(-1.0)
#define EPS 1e-8
#define LL long long
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define setzero(a) memset(a,0,sizeof(a))
#define setdp(a) memset(a,-1,sizeof(a))

using namespace std;

LL arr[1005];

int main()
{
  ios_base::sync_with_stdio(0);
  freopen("B-large.in", "r", stdin);
  freopen("out.out", "w", stdout);
  int t, tt = 1;
  cin >> t;
  while(t--)
  {
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
      cin >> arr[i];
    LL L = 0, R = 1e16;
    while(R > L)
    {
      LL mid = L + (R - L) / 2;
      LL cnt = 0;
      for(int i=0;i<n;i++)
        cnt+=mid / arr[i] + 1;
      if(cnt >= k) R = mid;
      else L = mid + 1;
    }
    L--;
    for(int i=0;i<n;i++)
      k-=L / arr[i] + 1;
    L++;
    int res = -1;
    for(int i=0;i<n && res == -1;i++)
    {
      if(L % arr[i] == 0)
        k--;
      if(k == 0) res = i + 1;
    }
    cout << "Case #" << tt++ << ": " << res << "\n";
  }
  return 0;
}
