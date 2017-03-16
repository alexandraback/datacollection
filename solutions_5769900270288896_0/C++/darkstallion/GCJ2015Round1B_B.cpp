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
#define MOD 1000000007
using namespace std;

bool mat[20][20];

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    int r,c,n;
    scanf("%d%d%d",&r,&c,&n);
    int ans = 1000000;
    FORN(j,(1 << (r*c)))
    {
      int count = 0;
      FORN(k,r*c)
        if (j & (1 << k))
          count++;
      if (count == n)
      {
        RES(mat,false);
        FORN(k,r*c)
          if (j & (1 << k))
            mat[k/c][k%c] = true;
        int tot = 0;
        FORN(k,r)
          FORN(l,c)
            if ((k == r-1) && (l == c-1))
              continue;
            else if (k == r-1)
            {
              if (mat[k][l] && mat[k][l+1])
                tot++;
            }
            else if (l == c-1)
            {
              if (mat[k][l] && mat[k+1][l])
                tot++;
            }
            else
            {
              if (mat[k][l] && mat[k+1][l])
                tot++;
              if (mat[k][l] && mat[k][l+1])
                tot++;
            }
        ans = min(ans,tot);
      }
    }
    printf("Case #%d: %d\n",i+1,ans);
  }
}