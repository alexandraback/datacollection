#include<cstdio>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int a[50];
int main()
{
    freopen("1lar.in","r",stdin);
    freopen("1lar.out","w",stdout);
    int T,cas=0;scanf("%d",&T);
    while(T--)
    {
        int n;scanf("%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        scanf("%d",&a[i]),sum+=a[i];
        printf("Case #%d:",++cas);
        while(1)
        {
            int ma=0,dd=-1;
            for(int i=0;i<n;i++)
            {
                if(a[i]>ma)
                {
                    ma=a[i];dd=i;
                }
            }
            if(ma==0)
            {
                puts("");
                break;
            }
            a[dd]--;
            ma=0;
            for(int i=0;i<n;i++)
            ma=max(ma,a[i]);
            sum--;
            if(sum-ma<ma)
            {
                int m2=0,d2=-1;
                for(int i=0;i<n;i++)
                {
                    if(a[i]>m2)
                    {
                        m2=a[i];d2=i;
                    }
                }
                printf(" %c%c",dd+'A',d2+'A');
                a[d2]--;
                sum--;
            }
            else
            {
                printf(" %c",dd+'A');
            }



        }

    }
    return 0;
}
