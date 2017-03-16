#include <iostream>
#include<cstdio>
#include<string>
#include<cstdlib>
using namespace std;



int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.in","w",stdout);
    int test,n,tt,i,j,c,cnt,ans,k,l;
    int occ[105][105];
    string s[105],str[105];
    scanf("%d",&test);
    for(tt=1;tt<=test;tt++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        cin>>s[i];
        ans=0;
         for(i=0;i<n;i++)
        {
            for(j=0;j<=100;j++)
            occ[i][j]=0;
        }
        l=0;
        for(i=0;i<n;i++)
        {
            str[i]="";
            str[i]+=s[i][0];
            k=0;
            occ[i][k]=1;
            for(j=1;j<s[i].size();j++)
            {
                if(s[i][j]==s[i][j-1])
                occ[i][k]++;
                else if(s[i][j]!=s[i][j-1])
                {
                    str[i]+=s[i][j];
                    k++;
                    occ[i][k]++;
                }
            }
            l=max(l,k);
        }


        for(i=1;i<n;i++)
        {
            if(str[i]!=str[i-1])
            {
                ans=-1;
                break;
            }
        }
        if(ans!=-1)
        {
            ans=0;
            for(j=0;j<=l;j++)
            {
                cnt=-1;
                for(i=0;i<n;i++)
                {
                    c=0;
                    for(k=0;k<n;k++)
                    {
                        if(i!=k)
                        {
                            c=c+abs(occ[i][j]-occ[k][j]);
                        }
                    }
                    if(cnt==-1)
                    cnt=c;
                    else
                    cnt=min(cnt,c);
                }
                ans=ans+cnt;
            }
        }
        printf("Case #%d: ",tt);
        if(ans==-1)
        printf("Fegla Won\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}
