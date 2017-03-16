#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;
int mush[10000];
int main()
{
    int times;
    freopen("A-small.in","r",stdin);
    freopen("A-small.txt","w",stdout);
    scanf("%d\n",&times);
    for (int t = 1; t <= times; t++)
    {
        int n;

        scanf("%d",&n);
        int ans1 = 0;
        int ans2 = 0;
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&mush[i]);
            if (i > 0)
            {
                if (mush[i] - mush[i-1] < 0) ans1 += mush[i-1] - mush[i];
                if (mush[i-1] - mush[i] > max) max = mush[i-1] - mush[i];
            }
        }
        for (int i = 0; i < n-1; i++)
        {
            if (mush[i] > max) ans2+= max;
            else ans2 += mush[i];
        }-
        printf("Case #%d: %d %d\n",t,ans1,ans2);
    }
}
