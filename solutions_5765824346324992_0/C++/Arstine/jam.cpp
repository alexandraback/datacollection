#include<bits\stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else return gcd(b,a%b);
}

int main()
{
    freopen("B.in","r",stdin);
    freopen("out.txt","w",stdout);

    int t,k;
    int n,b,m[5];
    int free[5];
    int i,j,ans;
    int tm,c;
    int x,y,z;
    bool none;
    scanf("%d",&t);
    for(k=1;k<=t;k++)
    {
        scanf("%d %d",&b,&n);
        for(i=0;i<b;i++)
        {
            scanf("%d",&m[i]);
            free[i]=0;
        }
        tm=c=0;

        x=m[0];
        for(i=1;i<b;i++)
        {
            y=gcd(x,m[i]);
            z=x*m[i]/y;
            x=z;
        }
        x=0;
        for(i=0;i<b;i++)
        {
            x+=z/m[i];
        }
        if(n%x==0)
            n=x;
        else
            n=n%x;
        tm=c=0;

        while(c!=n)
        {
            none = true;
            for(i=0;i<b;i++)
                if(tm>=free[i])
                {
                    none = false;
                    free[i]=tm+m[i];
                    c++;
                    if(c==n)
                    {
                        ans=i;
                        break;
                    }
                }
            if(none)
            {
                tm=free[0];
                for(j=0;j<b;j++)
                {
                    tm=min(tm,free[j]);
                }
            }
            else
                tm++;
        }
        printf("Case #%d: %d\n",k,ans+1);
    }
    return 0;
}
