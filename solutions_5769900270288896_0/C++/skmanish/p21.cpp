#include<bits/stdc++.h>

#define s(a) scanf("%d",&a)
#define ss(a) scanf("%s",a)

#define MP           make_pair
#define PB           push_back
#define REP(i, n)    for(int i = 0; i < n; i++)
#define INC(i, a, b) for(int i = a; i <= b; i++)
#define DEC(i, a, b) for(int i = a; i >= b; i--)
#define CLEAR(a)     memset(a, 0, sizeof a)

using namespace std;

typedef long long          LL;
typedef unsigned long long ULL;
typedef vector<int>        VI;
typedef pair<int, int>     II;
typedef vector<II>         VII;

bool mat[17][17];
inline int fun(int r,int c)
{
      int ret = 0;
      REP(cc,c)
      REP(rr,r)
      {
            if(rr>=1)
                  if(mat[rr][cc]&mat[rr-1][cc])
                        ret++;
            if(cc>=1)
                  if(mat[rr][cc]&mat[rr][cc-1])
                        ret++;
      }
      return ret;
}
int main()
{
      int t;
      s(t);
      //while(t--)
      REP(tt,t)
      {
            int r,c,n;
            s(r);s(c);s(n);
            int tot = r*c;
            int ans = 1e9;
            REP(i,(1<<tot))
            {
                  if(__builtin_popcount(i)!=n)
                        continue;
                  REP(rr,r)
                  REP(cc,c)
                  {
                        if((1<<(rr*c+cc))&i)
                              mat[rr][cc] = true;
                        else mat[rr][cc] = false;
                  }
                  ans = min(ans,fun(r,c));
            }
            printf("Case #%d: %d\n",tt+1,ans);
      }
      return 0;
}
