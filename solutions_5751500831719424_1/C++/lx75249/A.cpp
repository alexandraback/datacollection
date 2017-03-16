#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <set>
#include <new>
#define see(x) cerr<<#x<<" = " << (x) << endl
using namespace std;

char s[110][110];
struct
{
  char c; int rep;
}R[110][110];
int tot[110];
int tmp[110];

int main()
{
  freopen("A-large.in","r",stdin);
  freopen("A-large.out","w",stdout);
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int n;
    scanf("%d",&n);
    memset(tot,0,sizeof(tot));
    for(int i=1;i<=n;i++)
      scanf("%s", s[i]);
    for(int i=1;i<=n;i++)
    {
      int l=strlen(s[i]);
      tot[i]=1;
      R[i][1].c=s[i][0];
      R[i][1].rep=1;
      for(int j=1;j<l;j++)
      {
        if (s[i][j] == s[i][j-1])
          R[i][tot[i]].rep++;
        else
        {
          tot[i]++;
          R[i][tot[i]].rep=0;
          R[i][tot[i]].c=s[i][j];
        }
      }
    }
    int ans=0;
    bool ok=true;
    for(int i=2;i<=n;i++)
      if (tot[i]!=tot[i-1])
        ok=false;
    for(int i=1;i<=tot[1];i++)
    {
      for(int j=2;j<=n;j++)
        if (R[j][i].c != R[j-1][i].c)
          ok=false;
      for(int j=1;j<=n;j++)
        tmp[j] = R[j][i].rep;
      sort(tmp+1, tmp+1+n);
      int mid;
      if (n%2==0)
        mid = (tmp[n/2]+tmp[n/2+1])/2;
      else
        mid = tmp[(n+1)/2];
      for(int j=1;j<=n;j++)
        ans += abs(mid-tmp[j]);
    }
    printf("Case #%d: ",t);
    if (ok)
      printf("%d\n", ans);
    else
      printf("Fegla Won\n");
  }
  return 0;
}
