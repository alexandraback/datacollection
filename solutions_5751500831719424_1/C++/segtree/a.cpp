#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int T,n,p[105],ans,l[105],a[105]; char s[105][105]; bool flag;
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T);
    for(int I=1;I<=T;++I)
    {
        scanf("%d",&n); memset(p,0,sizeof(p)); flag=1; ans=0;
        for(int i=0;i<n;++i) {scanf("%s",s[i]); l[i]=strlen(s[i]);}
        while(p[0]<l[0]&&flag)
        {
            char c=s[0][p[0]];
            for(int i=0;i<n;++i)
            {
                if(p[i]==l[i]) {flag=0; break;}
                int t=0;
                while(s[i][p[i]+t]==c) ++t;
                if(!t) {flag=0; break;}
                a[i]=t; p[i]+=t;
            }
            sort(a,a+n);
            for(int i=0;i<n;++i) ans+=abs(a[n/2]-a[i]);
        }
        for(int i=0;i<n;++i) if(p[i]!=l[i]) flag=0;
        printf("Case #%d: ",I);
        if(flag) printf("%d\n",ans);
        else printf("Fegla Won\n");
    }
}
