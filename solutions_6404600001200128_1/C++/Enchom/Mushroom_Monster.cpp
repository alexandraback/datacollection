#include <iostream>
#include <stdio.h>
using namespace std;

int first_ans=0;
int second_ans=0;
int realsum;
int a[1011];
int n;

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large-output.txt","w",stdout);

    int t;
    int test;
    int i;
    int maxval;

    scanf("%d",&t);

    for (test=1;test<=t;test++)
    {
        scanf("%d",&n);

        first_ans=0;
        second_ans=0;
        for (i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);

            if (i!=1)
            {
                if (a[i]<a[i-1])
                {
                    first_ans+=a[i-1]-a[i];

                    if (a[i-1]-a[i]>second_ans)
                    second_ans=a[i-1]-a[i];
                }
            }
        }

        realsum=0;
        for (i=1;i<=n-1;i++)
        {
            realsum+=MIN(a[i],second_ans);
        }

        printf("Case #%d: %d %d\n",test,first_ans,realsum);
    }

    return 0;
}
