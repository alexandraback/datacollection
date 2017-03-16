#include<bits\stdc++.h>

using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t,k,n,m[1000],i,j,x,y,z;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&m[i]);
        x=0;
        for(i=1;i<n;i++)
        {
            if(m[i]<m[i-1])
                x+=m[i-1]-m[i];
        }
        y=0;
        for(i=1;i<n;i++)
            y=max(y,m[i-1]-m[i]);
        z=0;
        for(i=0;i<n-1;i++)
            z+=min(y,m[i]);

        printf("Case #%d: %d %d\n",k,x,z);
    }
    return 0;
}
