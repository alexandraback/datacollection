#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char s[200],lib[200],te[200];
int cnt[200][200];
int sb[200];
void cal(int z,char s[],char t[])
{
    int k=1;t[0]=s[0];cnt[z][0]=1;
    for(int i=1;s[i];i++)
        if(t[k-1]==s[i])cnt[z][k-1]++;
        else t[k]=s[i],cnt[z][k++]=1;
    t[k]=0;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d%s",&n,s);
        memset(cnt,0,sizeof(cnt));
        cal(0,s,lib);
        bool f=1;
        for(int i=1;i<n;i++)
        {
            scanf("%s",s);
            cal(i,s,te);
            if(strcmp(lib,te)!=0)f=0;
        }
        printf("Case #%d: ",ti++);
        if(f)
        {
            int ans=0;
            for(int i=0;lib[i];i++)
            {
                for(int j=0;j<n;j++)
                    sb[j]=cnt[j][i];
                sort(sb,sb+n);
                int po=sb[n/2];
                for(int j=0;j<n;j++)
                    ans+=abs(po-sb[j]);
            }
            printf("%d\n",ans);
        }
        else puts("Fegla Won");
    }
    return 0;
}
