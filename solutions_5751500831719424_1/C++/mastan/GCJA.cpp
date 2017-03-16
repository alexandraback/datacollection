#include <cstdio>
#include <algorithm>

using namespace std;

char base[105][105];
int ln[105];
int cur[105];
int len[105];

int main()
{
    freopen("D:/in.txt","r",stdin);
    freopen("D:/out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int itr=1; itr<=tc; itr++)
    {
        int n;
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%s",base[i]+1);
        for (int i=1; i<=n; i++)
        {
            ln[i]=0;
            while (base[i][ln[i]+1])
                ln[i]++;
        }
        for (int i=1; i<=n; i++)
            cur[i]=1;
        int ok=1;
        char now=base[1][1];
        int sol=0;
        while (ok==1 && now!=0)
        {
            now=base[1][cur[1]];
            for (int i=1; i<=n; i++)
                if (base[i][cur[i]]!=now)
                    ok=0;
            if (ok==0)
                continue;
            if (now==0)
                continue;
            for (int i=1; i<=n; i++)
            {
                len[i]=0;
                while (base[i][cur[i]]==now)
                {
                    len[i]++;
                    cur[i]++;
                }
            }
            sort(len+1,len+1+n);
            for (int i=1; i<=n; i++)
                sol+=abs(len[i]-len[n/2+1]);
        }
        printf("Case #%d: ",itr);
        if (ok)
            printf("%d\n",sol);
        else
            printf("Fegla Won\n");
    }
}
