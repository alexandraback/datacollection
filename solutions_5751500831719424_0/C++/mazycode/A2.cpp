#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
char s[100][101];
int len[100];
char pop[100][101];
struct node{
       int v;
       int data;
}num[101][101];
int abs(int a)
{
    if(a>0)return a;
    return -a;
}
bool cmp(node a,node b)
{
     return a.data<b.data;
}
bool cmp2(node a,node b)
{
     return a.v<b.v;
}
int n;
int op;
int aim[101];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int ca=1;ca<=t;ca++)
    {
     scanf("%d",&n);
     for(int i=0;i<n;i++)
     for(int j=0;j<101;j++)
     {
      num[j][i].data=0;
      num[j][i].v=i;
     }
     for(int i=0;i<n;i++)
     {
     scanf("%s",s[i]);
     len[i]=strlen(s[i]);
     pop[i][0]=s[i][0];
     num[0][i].data=1;
     int u=0;
     for(int j=1;j<len[i];j++)
      {
       if(pop[i][u]!=s[i][j])
       {
        u++;
        pop[i][u]=s[i][j];
       }
       num[u][i].data++;
      }
     u++;
     pop[i][u]=0;
     op=u;
     }
     bool f=false;
     for(int i=1;i<n;i++)
     if(strcmp(pop[i],pop[i-1])) {printf("Case #%d: Fegla Won\n",ca);f=true;break;}
     if(f)continue;
     for(int i=0;i<op;i++)
     {
      sort(num[i],num[i]+n,cmp);
      aim[i]=num[i][n/2].data;
      sort(num[i],num[i]+n,cmp2);
     }
     int ans=0;
     for(int i=0;i<n;i++)
     for(int j=0;j<op;j++)
      ans+=abs(num[j][i].data-aim[j]);
      printf("Case #%d: %d\n",ca,ans);
    }
} 
