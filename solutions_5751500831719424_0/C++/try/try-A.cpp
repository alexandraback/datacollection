#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#define MAXN 100
#define MAXL 100
using namespace std;

pair<char,int> p[MAXN+1][MAXL+1];
char s[MAXL+1];
int q[MAXN+1];
int n;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int c,t,i,j,k,l,flg,sum,df1,df2,tot;
    scanf("%d",&t);
    for(c=0;c<t;c++)
    {
        memset(q,0,sizeof(q));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",s);
            l=strlen(s);
            for(j=0;j<=l;j=k)
            {
                for(k=j;k<=l;k++)
                {
                    if(s[j]!=s[k])
                    {
                        p[i][q[i]++]=make_pair(s[j],k-j);
                        break;
                    }
                }
            }
        }
        flg=1;
        for(i=1;(i<n)&&(flg==1);i++)
        {
            if(q[i]!=q[i-1])
            {
                flg=0;
            }
            for(j=0;(j<q[i])&&(flg==1);j++)
            {
                if(p[i][j].first!=p[i-1][j].first)
                {
                    flg=0;
                }
            }
        }
        printf("Case #%d: ",c+1);
        if(flg==0)
        {
            printf("Fegla Won\n");
            continue;
        }
        tot=0;
        for(j=0;j<q[0];j++)
        {
            sum=0;
            for(i=0;i<n;i++)
            {
                sum=sum+p[i][j].second;
            }
            sum=sum/n;
            df1=0;
            for(i=0;i<n;i++)
            {
                df1=df1+labs(p[i][j].second-sum);
            }
            sum++;
            df2=0;
            for(i=0;i<n;i++)
            {
                df2=df2+labs(p[i][j].second-sum);
            }
            tot=tot+min(df1,df2);
        }
        printf("%d\n",tot);
    }
    return 0;
}
