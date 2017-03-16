/*
 *
 * Author : fcbruce <fcbruce8964@gmail.com>
 *
 * Time : Sat 18 Apr 2015 09:10:35 AM CST
 *
 */
#include <cstdio>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <set>
#define sqr(x) ((x)*(x))
#define LL long long
#define itn int
#define INF 0x3f3f3f3f
#define PI 3.1415926535897932384626
#define eps 1e-10

#ifdef _WIN32
  #define lld "%I64d"
#else
  #define lld "%lld"
#endif

#define maxm 
#define maxn 1007

using namespace std;

int a[maxn];

int main()
{
#ifdef FCBRUCE
  freopen("/home/fcbruce/code/t","r",stdin);
  freopen("A.out","w",stdout);
#endif // FCBRUCE

  int T_T,__=0;
  scanf("%d",&T_T);

  while (T_T--)
  {
    int n;
    scanf("%d",&n);

    for (int i=0;i<n;i++) scanf("%d",a+i);

    long long res1=0,res2=0;
    for (int i=1;i<n;i++)
    {
      if (a[i]<a[i-1]) res1+=a[i-1]-a[i];
    }

    long long rate=0;
    for (int i=1;i<n;i++)
    {
      rate=max(rate,(LL)a[i-1]-a[i]);
    }
    
    for (int i=0;i<n-1;i++)
    {
      res2+=min(rate,(LL)a[i]);
    }

    
    printf("Case #%d: %lld %lld\n",++__,res1,res2);
  }



  return 0;
}
