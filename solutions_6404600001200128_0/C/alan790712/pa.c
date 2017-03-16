#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int m[10000];
int n;

int main()
{
    int T, t;
    int x, y, z;
    int i;
    int max;
    scanf("%d ",&T);
    for(t=1;t<=T;++t)
    {
        scanf("%d", &n);
        for(i=0;i<n;++i)
        {
            scanf("%d",&m[i]);
        }
        for(i=1, y=0, max=0;i<n;++i)
        {
            x = (m[i]<m[i-1])*(m[i-1]-m[i]);
            y += x;
            if(max <x)max = x;
        }
        for(i=0, z=0;i+1<n;++i)
        {
            z += (max<m[i])?max:m[i];
        }
        printf("Case #%d: %d %d\n", t, y, z);
    }

    return 0;
}
