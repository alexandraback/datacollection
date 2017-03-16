/*Author : Md. Al- Amin
           20th batch
           Dept. of CSE, SUST*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<map>
#include<set>
#include<queue>
#include<vector>
#define pi (2*acos(0))
#define SF scanf
#define SFd1(a) scanf("%d",&a)
#define SFd2(a,b) scanf("%d%d",&a,&b)
#define SFd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define PF printf
#define inf 99999999
#define eps 0.00000001
#define ll long long
#define ull long long unsigned
#define int_max 2147483647
#define int_min -2147483648
#define long_max 9223372036854775807
#define long_min -9223372036854775808
#define fr(i,n) for(i=0;i<n;i++)
#define ms(dp,a) memset(dp,a,sizeof(dp))
#define dist(x1,y1,x2,y2) sqrt( ((x2-x1)*(x2-x1)) + ((y2-y1)*(y2-y1)) )
#define PB push_back
#define mem(arr,val) memset(arr,val,sizeof(arr))

using namespace std;
//int rr[]={1,2,-1,-2,1,2,-1,-2};
//int cc[]={2,1,2,1,-2,-1,-2,-1};
//int rr[]={0,0,1,-1};
//int cc[]={-1,1,0,0};


ll res,arr[1010],b,n;

ll func(ll mx)
{
    ll ret=b;
    for(ll i=1LL;i<=b;i++)
    {
        ret+=(mx/arr[i]);
    }
    return ret;
}


int main()
{
    freopen("B-large0.in","r",stdin);
    freopen("HaircutOutput.txt","w",stdout);
    ll t,p,need,low,high,mid,i,j;

    scanf(" %lld",&t);

    for(p=1LL;p<=t;p++)
    {
        scanf(" %lld %lld",&b,&n);

        for(i=1;i<=b;i++)
        {
            scanf(" %lld",&arr[i]);
        }

        if(n<=b)
        {
            printf("Case #%lld: %lld\n",p,n);
            continue;
        }

        low=0LL;
        high=9999999999999999LL;
        need=9999999999LL;
        while(low<=high)
        {
            mid=(low+high)/2LL;

            if(func(mid)>=n)
            {
                res=mid;
                need=min(need,func(mid)-n);
                high=mid-1LL;
            }
            else
                low=mid+1LL;
        }

        for(j=0LL,i=b;i>=1LL;i--)
        {
            if((res%arr[i])==0LL)
            {
                if(j==need)
                {
                    printf("Case #%lld: %lld\n",p,i);
                    break;
                }
                j++;
            }
        }
    }

    return 0;
}





