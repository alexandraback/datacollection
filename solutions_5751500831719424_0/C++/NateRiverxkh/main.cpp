#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define maxn 5010
#define maxe 500010
#define INF 1<<30
int n,m,len[maxn],id[maxn],nxt[maxn];
char s[110][110];
inline int ab(int a){ return a>0?a:-a; }
int main()
{
    int i,j,ncase,tt=0;
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%s",s[i]),len[i]=strlen(s[i]);
        memset(id,0,sizeof(id));
        int f=0,ans=0;
        while(1)
        {
            int tmp[110];char c=s[0][id[0]];
            for(i=0;i<n;i++)
            {
                if(s[i][id[i]]!=c)
                    f=1;
                for(j=id[i];j<len[i];j++)
                    if(s[i][j]!=s[i][id[i]])
                        break;
                nxt[i]=j;
                tmp[i]=j-id[i];
            }
            if(f)
                break;
            int ret=INF;
            for(i=0;i<n;i++)
            {
                int tt=0;
                for(j=0;j<n;j++)
                    tt+=ab(tmp[i]-tmp[j]);
                ret=min(tt,ret);
            }
            ans+=ret;
            for(i=0;i<n;i++){
                id[i]=nxt[i];
                if(nxt[i]==len[i])
                    f=1;
            }
            if(f)
                break;
        }
        printf("Case #%d: ",++tt);
        for(i=0;i<n;i++)if(id[i]!=len[i])
                break;
        if(i<n) puts("Fegla Won");
        else
            printf("%d\n",ans);

    }
}
