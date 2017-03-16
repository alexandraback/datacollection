#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>
#define maxn 20

using namespace std;

int test,ttest,a[maxn][maxn],n,r,c,ans,res,cnt;

void init()
 {
     scanf("%d%d%d\n",&r,&c,&n);
 }

void work()
 {
    int i,j,s,t,tot;
    ans=-1;cnt=r*c;
    for (s=0;s<=((1<<cnt)-1);s++)
    {
        for (i=1;i<=r;i++)
            for (j=1;j<=c;j++)a[i][j]=0;
        i=1;j=1;
        t=s;tot=0;
        while (t)
        {
            if (t&1)
            {
                tot++;a[i][j]=1;
            }
            if (j==c){i++;j=1;}else j++;
            t>>=1;
        }
        if (tot!=n)continue;res=0;
        for (i=1;i<=r;i++)
            for (j=1;j<=c;j++)
        {
            if (i<r && a[i][j] && a[i+1][j])res++;
            if (j<c && a[i][j] && a[i][j+1])res++;
        }
        if (ans==-1 || res<ans)ans=res;
    }
        printf("Case #%d: %d\n",ttest,ans);
 }

int main()
 {
     freopen("B.in","r",stdin);
     freopen("B.out","w",stdout);
     scanf("%d\n",&test);
     for (ttest=1;ttest<=test;ttest++)
     {
      init();
      work();
     }
     return 0;
 }
