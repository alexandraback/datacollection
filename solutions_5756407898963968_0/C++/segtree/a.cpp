#include <cstdio>
#include <cstring>
int T,g[4][4],s[16];
int main()
{
    freopen("i.txt","r",stdin);
    freopen("o.txt","w",stdout);
    scanf("%d",&T); int x;
    for(int I=1;I<=T;++I)
    {
        memset(s,0,sizeof(s));
        scanf("%d",&x); --x;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) scanf("%d",&g[i][j]);
        for(int i=0;i<4;++i) ++s[g[x][i]-1];
        scanf("%d",&x); --x;
        for(int i=0;i<4;++i)
            for(int j=0;j<4;++j) scanf("%d",&g[i][j]);
        for(int i=0;i<4;++i) ++s[g[x][i]-1];
        x=0;
        for(int i=0;i<16;++i) if(s[i]>1) ++x;
        printf("Case #%d: ",I);
        if(x>1) printf("Bad magician!\n");
        else if(x<1) printf("Volunteer cheated!\n");
        else
        {
            for(int i=0;i<16;++i) if(s[i]==2) x=i+1;
            printf("%d\n",x);
        }
    }
    return 0;
}
