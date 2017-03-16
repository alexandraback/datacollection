#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<string>
#include<iostream>
#include <utility>
#define PI 3.14159265359
#define e 2.718281828
using namespace std;
typedef long long LL;
int num[110][110],nu[110][110],len[110];
char s[110][110],s1[110][110];
int Abs(int x)
{
    return x<0?-x:x;
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int t,ca=1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,n;
        scanf("%d",&n);
        for(i=0;i<n;i++)scanf("%s",s[i]);
        for(i=0;i<n;i++)
        {
            int k=0;
            num[i][k]=1;s1[i][k]=s[i][0];
            for(j=1;s[i][j];j++)
            {
                if(s[i][j]==s[i][j-1])
                {
                    num[i][k]++;
                }
                else
                {
                    k++;
                    s1[i][k]=s[i][j];
                    num[i][k]=1;
                }
            }
            len[i]=k+1;
        }
        for(i=1;i<n;i++)if(len[i]!=len[i-1])break;
        if(i<n)printf("Case #%d: Fegla Won\n",ca++);
        else
        {
            int flag=0;
            for(i=1;i<n;i++)
            {
                for(j=0;j<len[i];j++)
                {
                    if(s1[i][j]!=s1[0][j]){flag=1;break;}
                }
                if(flag)break;
            }
            if(flag)printf("Case #%d: Fegla Won\n",ca++);
            else
            {
                memset(nu,0,sizeof(nu));
                for(i=0;i<n;i++)
                {
                    for(j=0;j<len[0];j++)
                    {
                        nu[j][i]=num[i][j];
                    }
                }
                for(i=0;i<len[0];i++)
                {
                    sort(nu[i],nu[i]+n);
                }
                int ans=0;
                for(i=0;i<len[0];i++)
                {
                    int x=nu[i][n/2];
                    for(j=0;j<n;j++)
                    {
                        ans+=Abs(x-nu[i][j]);
                    }
                }
                printf("Case #%d: %d\n",ca++,ans);
            }
        }
    }
}
