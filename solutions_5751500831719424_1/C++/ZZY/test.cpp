#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
#include<algorithm> 
#define MAXN 105
using namespace std;
int a[MAXN][MAXN];
char s[MAXN][MAXN],ss[MAXN];
int doit(int n)
{
       int i,j,x,len,k,sum,m,ans;
       memset(ss,0,sizeof(ss));
       ss[m=1]=s[1][0];
       for (i=1;i<=n;i++)
       {
              len=strlen(s[i]); 
              if (s[i][0]!=s[1][0]) return -1;
              a[i][k=1]=1;
              for (x=1;x<len;x++)
                if (s[i][x]==s[i][x-1]) a[i][k]++;
                  else 
                  {
                        k++;
                        if (i==1) ss[k]=s[i][x],m=k; 
                        if (s[i][x]!=ss[k]) return -1;
                        a[i][k]=1;      
                  }
              if (k!=m) return -1;
       }
       ans=0;
       for (i=1;i<=m;i++)
       { 
             k=1<<29;
             for (x=1;x<=100;x++)
             {
                    sum=0;
                    for (j=1;j<=n;j++) sum+=abs(a[j][i]-x);
                    k=min(k,sum);
             }
             ans+=k;
       }       
       return ans;
}
int main()
{
       int T,cases,i,n,ans;
       freopen("A-large.in","r",stdin);
       freopen("output.txt","w",stdout);
       scanf("%d",&T);
       for (cases=1;cases<=T;cases++)
       {
               scanf("%d",&n);
               for (i=1;i<=n;i++) scanf("%s",s[i]);
               ans=doit(n);
               printf("Case #%d: ",cases);
               if (ans<0) puts("Fegla Won");
                    else  printf("%d\n",ans);
       }
       return 0;
}
