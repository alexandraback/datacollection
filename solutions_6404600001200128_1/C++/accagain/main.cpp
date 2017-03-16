#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

#define Maxn 1100

using namespace std;

int sa[Maxn];
int n,m;

int main()
{
    int T;
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    scanf("%d",&T);
    for(int ca = 1; ca<=T;ca++)
    {
        scanf("%d",&n);

        int ans1=0,ans2=0,Max=0;

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&sa[i]);
            if(i!=1)
            {
                if(sa[i]<sa[i-1])
                {
                    ans1+=sa[i-1]-sa[i];
                    Max = max(sa[i-1]-sa[i],Max);
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            if(sa[i]<Max)
                ans2+=sa[i];
            else
                ans2+=Max;
        }
        printf("Case #%d: %d %d\n",ca,ans1,ans2);

    }
    return 0;
}
