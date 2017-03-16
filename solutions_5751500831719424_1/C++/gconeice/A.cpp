#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>

using namespace std;

const int N=110;
int T;
int n;
char f[N][N];
int a[N][N];
string s[N];

int main()
{
  freopen("A.in","r",stdin);
  freopen("A.out","w",stdout);
  cin >>T;
  for (int ii=1;ii<=T;ii++)
    {
      cin >>n;
      for (int i=1;i<=n;i++) cin >>s[i];
      for (int i=1;i<=n;i++)
	{
	  a[i][0]=0;
	  int len=s[i].length();
	  for (int j=0;j<len;j++)
	    {
	      int r=j;
	      while (r+1<len&&s[i][r+1]==s[i][j]) r++;
	      a[i][0]++;
	      a[i][a[i][0]]=r-j+1;
	      f[i][a[i][0]]=s[i][j];
	      j=r;
	    }
	}
      int num=a[1][0];
      bool check=0;
      for (int i=2;i<=n;i++)
	{
	  if (num!=a[i][0])
	    {
	      check=1;
	      break;
	    }
	  for (int j=1;j<=num;j++)
	    if (f[1][j]!=f[i][j])
	      {
		check=1;
		break;
	      }
	  if (check) break;
	}
      if (check) {printf("Case #%d: Fegla Won\n",ii); continue;}
      int ans=0;
      int t[N];
      for (int i=1;i<=num;i++)
	{
	  for (int j=1;j<=n;j++) t[j]=a[j][i];
	  sort(t+1,t+n+1);
	  int mid=t[n/2+1];
	  for (int j=1;j<=n;j++) ans+=abs(mid-t[j]);
	}
      printf("Case #%d: %d\n",ii,ans);
    }
  return 0;
}
