#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define MAXN 131

int t;
int n;
pair<int,char> str[MAXN][MAXN];
int sL[MAXN];
char inp[MAXN];
int arr[MAXN];
int aL;

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output_small.txt","w",stdout);

    int i,j;
    int test;
    int L;
    bool finish;
    int mid;
    int minans;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        memset(sL,0,sizeof(sL));

        for (i=1;i<=n;i++)
        {
            scanf("%s",inp+1);

            L=strlen(inp+1);

            sL[i]=1;
            str[i][1].first=1;
            str[i][1].second=inp[1];

            for (j=2;j<=L;j++)
            {
                if ( inp[j]==inp[j-1] )
                {
                    str[i][ sL[i] ].first++;
                }
                else
                {
                    sL[i]++;
                    str[i][ sL[i] ].first=1;
                    str[i][ sL[i] ].second=inp[j];
                }
            }
        }

        finish=false;

        for (i=2;i<=n;i++)
        {
            if (sL[i]!=sL[1])
            {
                finish=true;
                break;
            }
        }

        if (finish)
        {
            printf("Case #%d: Fegla Won\n",test);
            continue;
        }

        for (i=1;i<=sL[1];i++)
        {
            for (j=2;j<=n;j++)
            {
                if (str[j][i].second!=str[1][i].second)
                {
                    finish=true;
                    break;
                }
            }
            if (finish)
            break;
        }

        if (finish)
        {
            printf("Case #%d: Fegla Won\n",test);
            continue;
        }

        minans=0;

        aL=0;
        for (i=1;i<=sL[1];i++)
        {
            aL=0;

            for (j=1;j<=n;j++)
            {
                aL++;
                arr[aL]=str[j][i].first;
            }

            sort(arr+1,arr+1+aL);

            mid=arr[ (aL+1)/2 ];

            for (j=1;j<=(aL+1)/2;j++)
            {
                minans=minans+(mid-arr[j]);
            }

            for (j=(aL+1)/2+1;j<=aL;j++)
            {
                minans=minans+(arr[j]-mid);
            }
        }

        printf("Case #%d: %d\n",test,minans);
    }

    return 0;

}
/**
1
2
vdpjtitufsmyhdtsftpaagvyth
vdpjtitufsmyhdtsftpaagvyte
**/
