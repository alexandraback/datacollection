#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}
int LCM(int a,int b)
{
    return a*b/gcd(a,b);
}
int finddmin(int *time,int n)
{
    int minn=999999999;
    int minx=0;
    for(int i=1;i<=n;i++)
    {
        if(time[i]<minn)
        {
            minn=time[i];
            minx=i;
        }
    }
    return minx;
}
int main()
{
    int t,b,n,cases;
    int m[100];
    int time[100];
    while(scanf("%d",&t)!=EOF)
    {
        cases=1;
        while(t--)
        {
            scanf("%d%d",&b,&n);
            memset(time,0,sizeof(time));
            for(int i=1;i<=b;i++)
            {
                scanf("%d",&m[i]);
            }
            int lcm=1;
            for(int i=1;i<=b;i++)
            {
                lcm=LCM(lcm,m[i]);
            }
            //printf("%d\n",lcm);
            int num=0;
            for(int i=1;i<=b;i++)
            {
                num+=lcm/m[i];
            }
           // printf("%d\n",num);
            if(num<n)
            {
                n%=num;
            }
            if(n==0)
            {
                n+=num;
            }
            int now=1;
            while(now<n)
            {
                int temp=finddmin(time,b);
                time[temp]+=m[temp];
                now++;
            }
            printf("Case #%d: %d\n",cases,finddmin(time,b));
            cases++;
        }
    }
    return 0;
}
