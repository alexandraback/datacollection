#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
int vals[5][5];
int cnt[20];
int main()
{
    freopen("D:/out.txt","w",stdout);
    freopen("D:/tp.txt","r",stdin);
    int tc;
    scanf("%d",&tc);
    for (int caseid=1; caseid<=tc; caseid++)
    {
        int x;
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&x);
        for (int i=1; i<=4; i++)
            for (int j=1; j<=4; j++)
                scanf("%d",&vals[i][j]);
        for (int i=1; i<=4; i++)
            cnt[vals[x][i]]++;

        scanf("%d",&x);
        for (int i=1; i<=4; i++)
            for (int j=1; j<=4; j++)
                scanf("%d",&vals[i][j]);
        for (int i=1; i<=4; i++)
            cnt[vals[x][i]]++;
        int csol,cval;
        csol=0;
        for (int i=1; i<=16; i++)
            if (cnt[i]==2)
            {
                csol++;
                cval=i;
            }
        printf("Case #%d: ",caseid);
        if (csol==1)
            printf("%d\n",cval);
        if (csol==0)
            printf("Volunteer cheated!\n");
        if (csol>1)
            printf("Bad magician!\n");
    }
}
