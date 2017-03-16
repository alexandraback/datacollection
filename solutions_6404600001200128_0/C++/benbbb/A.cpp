#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);

    int T,ca,N,i;
    int a[20000];
    cin>>T;
    for (ca=1;ca<=T;ca++)

        {
            cin>>N;
            for (i=1;i<=N;i++)
            cin>>a[i];
            int x,y,j,t;
            x=0;
            y=0;
            t=0;
            for (i=2;i<=N;i++)
            if (a[i]<a[i-1]) x+=a[i-1]-a[i];
            for (i=1;i<N;i++)
             for (j=i+1;j<=N;j++)
               {
                   if ((a[i]-a[j])/(j-i)>t) t=(a[i]-a[j])/(j-i);
               }
            for (i=2;i<=N;i++)
             if (a[i-1]>=t) y+=t;
             else y+=a[i-1];
         printf("Case #%d: %d %d\n",ca,x,y);

        }


    return 0;
}
