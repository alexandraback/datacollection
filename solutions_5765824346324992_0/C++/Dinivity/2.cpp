#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
struct S
{
    long long id,num;
}s[1007],s1[1007];
long long gcd(long long a,long long b)
{
    return b?gcd(b,a%b):a;
}
long long lcm(long long a,long long b)
{
    return a/gcd(a,b)*b;
}
long long cmp(S a,S b)
{
    if(a.num==b.num)return a.id<b.id;
    return a.num<b.num;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long t,cas=1;
    scanf("%lld",&t);
    while(t--)
    {
        long long b,n,l=1,sum=0;
        scanf("%lld%lld",&b,&n);
        for(long long i=0;i<b;i++)
            scanf("%lld",&s[i].num),s[i].id=i,l=lcm(l,s[i].num),s1[i]=s[i];
        for(long long i=0;i<b;i++)
            sum+=l/s[i].num;
        printf("Case #%lld: ",cas++);
        if(n<=b){printf("%lld\n",n);continue;}
        n-=b;
        long long mod=n%sum;
        if(!mod)
        {
            sort(s1,s1+b,cmp);
            printf("%lld\n",s1[b-1].id+1);
        }
        else
        {
                long long flag=0;
                for(long long time=1;time<=l;time++)
                {
                    for(long long i=0;i<b;i++)
                    {
                        if(time%s[i].num==0)mod--;
                         if(mod==0)
                         {
                             printf("%lld\n",s[i].id+1);
                             flag=1;
                             break;
                         }
                    }
                    if(flag)break;
                }
        }
    }
    return 0;
}
