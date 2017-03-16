#include <cstdio>
#include <cstring>

int n;
char s[110][120];
int a[110];
int b[110];
int l[110];

inline int calc(int x)
{
  int i,t,ret;
  ret=0;
  for (i=1;i<=n;i++)
  {
    t=a[x]-a[i];
    if (t<0) t=-t;
    ret+=t;
  }
  return ret;
}

inline int work()
{
  int i,j,y;
  int ret,t,mi;
  char f[110];
  memset(b,0,sizeof(b));
  ret=0;
  while (1)
  {
    for (j=1;j<=n;j++)
    {
      if (b[j]>=l[j]) 
      {
	a[j]=-1;
	continue;
      }
      y=b[j];
      f[j]=s[j][b[j]];
      while (b[j]+1<l[j] && s[j][b[j]]==s[j][b[j]+1]) b[j]++;
      a[j]=b[j]-y+1;
      b[j]++;
    }
    if (a[1]!=-1)
    {
      for (j=2;j<=n;j++)
	if (a[j]==-1 || f[j]!=f[j-1]) return -1;
    }
    else
    {
      for (j=2;j<=n;j++)
	if (a[j]!=-1) return -1;
      break;
    }
    mi=-1;
    for (j=1;j<=n;j++)
    {
      t=calc(j);
      if (mi==-1 || t<mi) mi=t;
    }
    ret+=mi;
  }
  return ret;
}

int main()
{
  int T,o,i,ans;
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%s",s[i]);
      l[i]=strlen(s[i]);
    }
    printf("Case #%d: ",o);
    ans=work();
    if (ans==-1)
      puts("Fegla Won");
    else
      printf("%d\n",ans);
  }
  return 0;
}
