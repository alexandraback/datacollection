//darkstallion's template

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
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
    vector<pair<char,int> > data[n];
    string st[n];
    FORN(j,n)
    {
      string s;
      cin >> s;
      char tmp = s[0];
      int z = 1;
      FOR(k,1,s.sz())
        if (tmp != s[k])
        {
          data[j].pb(mp(tmp,z));
          st[j] += tmp;
          tmp = s[k];
          z = 1;
        }
        else
          z++;
      data[j].pb(mp(tmp,z));
      st[j] += tmp;
    }
    printf("Case #%d: ",i+1);
    bool ktmu = false;
    string tmp = st[0];
    FOR(j,1,n)
      if (st[j] != tmp)
      {
        ktmu = true;
        break;
      }
    if (ktmu)
    {
      printf("Fegla Won\n");
      continue;
    }
    int ans = 0;
    FORN(j,data[0].sz())
    {
      int mini = 1000;
      FORN(k,n)
      {
        int z = 0;
        FORN(l,n)
          z += abs(data[k][j].se-data[l][j].se);
        mini = min(mini,z);
      }
      ans += mini;
    }
    printf("%d\n",ans);
  }
}