//darkstallion's template

#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI acos(-1)
#define eps 1e-9
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    int n;
    scanf("%d",&n);
    int arr[n], ans1 = 0, maks = 0;
    FORN(j,n)
    {
      scanf("%d",&arr[j]);
      if (j > 0)
        if (arr[j] < arr[j-1])
        {
          ans1 += arr[j-1]-arr[j];
          maks = max(maks,arr[j-1]-arr[j]);
        }
    }
    int ans2 = 0;
    FORN(j,n-1)
      ans2 += min(arr[j],maks);
    printf("Case #%d: %d %d\n",i+1,ans1,ans2);
  }
}