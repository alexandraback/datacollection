#include<iostream>
#include<cstdio>
long long int ar[1010];
long long int fn(long long int a,long long int b)
{
    long long int temp,temp1,temp2;
    temp1=a;
    temp2=b;
    while(b!=0)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return ((temp1/a)*temp2);
}
int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.txt","w",stdout);
    long long int lcm,c,n,b,time;
    int t,i,j,m,ca,flag,index;
    scanf("%d",&t);
    for(ca=1; ca<=t; ca++)
    {
        flag=0;
        lcm=1;
        scanf("%lld %lld",&b,&n);
        for(i=1; i<=b; i++)
        {
            scanf("%lld",&ar[i]);
            lcm=fn(lcm,ar[i]);
        }
        c=0;
        for(i=1; i<=b; i++)
        {
            c+=(lcm/ar[i]);
        }
        n=n%c;
        if(n==0)
            n=c;
        time=0;
        if(n<=b)
        {
            index=n;
        }
        else
        {
            c=b+1;
            time=1;
            while(1)
            {
                for(j=1; j<=b; j++)
                {
                    if(time%ar[j]==0)
                    {
                        if(c==n)
                        {
                            flag=1;
                            index=j;
                            break;
                        }
                        c++;
                    }
                }
                time++;
                if(flag)
                    break;
            }
        }
        printf("Case #%d: %d\n",ca,index);
    }
    return 0;
}
