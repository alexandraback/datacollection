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

int p,n,i,t,arr[1010],res1,res2,mx,extra;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("MushroomMonsterOutput.txt","w",stdout);
    scanf(" %d",&t);

    for(p=1;p<=t;p++)
    {
        scanf(" %d",&n);
        for(i=1;i<=n;i++)
        {
            scanf(" %d",&arr[i]);
        }

        res1=res2=0;
        mx=0;
        for(i=2;i<=n;i++)
        {
            mx=max(mx,arr[i-1]-arr[i]);
            if(arr[i]<arr[i-1])
            {
                res1+=(arr[i-1]-arr[i]);
            }
        }
        extra=0;
        for(i=1;i<n;i++)
        {
            res2+=min(arr[i],mx);
        }
        printf("Case #%d: %d %d\n",p,res1,res2);
    }
    return 0;
}





