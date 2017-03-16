#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int casT;
    scanf("%d",&casT);
    for(int cas=1;cas<=casT;cas++)
    {
        int cnt[20];
        memset(cnt,0,sizeof(cnt));
        int row,x;
        for(int ii=0;ii<2;ii++)
        {
            scanf("%d",&row);
            for(int i=1;i<=4;i++)
            {
                for(int j=0;j<4;j++)
                {
                    scanf("%d",&x);
                    if(row==i) cnt[x]++;
                }
            }
        }
        int ans=-1,num=0;
        for(int i=1;i<=16;i++)
        {
            if(cnt[i]==2)
            {
                num++;ans=i;
            }
        }

        if(num==0) printf("Case #%d: Volunteer cheated!\n",cas);
        else if(num==1) printf("Case #%d: %d\n",cas,ans);
        else printf("Case #%d: Bad magician!\n",cas);

    }

    return 0;
}
