#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
using namespace std;
int a[2000];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int T,n;
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        int y=0,z=0,v=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<a[i-1])
                y+=a[i-1]-a[i];
            v=min(a[i]-a[i-1],v);
        }
        v=abs(v);
        for(int i=0;i<n-1;i++)
        {
            z+=min(v,a[i]);
        }
        printf("Case #%d: %d %d\n",t,y,z);
    }
    return 0;
}
