#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,m;
char ch[110][110];
char ya[110][110];
int num[110][110];
int len[110];
int main()
{
    freopen("A-small-attempt2.in","r",stdin);
    freopen("A-small-attempt2.out","w",stdout);
    int tit,tot;
    for(scanf("%d",&tot),tit=1;tit<=tot;tit++)
    {
        scanf("%d",&n);
        int maxlen=0;
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
            scanf("%s",ch[i]),len[i]=strlen(ch[i]);
        int pos[110]={};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<len[i];j++)
                if(j==0||ch[i][j]!=ch[i][j-1])
                    ya[i][pos[i]++]=ch[i][j];
                else num[i][pos[i]]++;
            ya[i][pos[i]]=0;
            /*for(int j=1;j<=pos[i];j++)
                cout<<num[i][j]<<' ';
            cout<<endl;*/
            maxlen=max(maxlen,pos[i]);
        }
        int noans=0,ans=0;
        for(int i=0;i<n-1;i++)
            if(strcmp(ya[i],ya[i+1])!=0)
                noans=1;
        if(noans==0)
        {
            for(int i=1;i<=maxlen;i++)
            {
                int minans=0x3f3f3f3f;
                for(int k=0;k<=100;k++)
                {
                    int sum=0;
                    for(int j=0;j<n;j++)
                        sum+=abs(num[j][i]-k);
                    minans=min(minans,sum);
                }
                ans+=minans;
            }
            printf("Case #%d: %d\n",tit,ans);
        }
        else 
            printf("Case #%d: Fegla Won\n",tit);
    }
	return 0;
}
