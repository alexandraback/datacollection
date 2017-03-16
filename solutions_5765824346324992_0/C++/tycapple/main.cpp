#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
int t,n,b;
int arr[1001];
int found(long long l,long long r)
{
    long long mid=(l+r)/2;
    int ans;
    int m=0;
    long long s=0;
    for(int i=1;i<=b;i++)
    {
        s+=(1+(mid-1)/arr[i]);
        if(mid%arr[i]==0)
        {
            m++;
        }
    }
    if(s<n&&s+m>=n)
        {
            for(int i=1;i<=b;i++)
            {
                if(mid%arr[i]==0)
                    s++;
                if(s==n)
                {
                    ans=i;
                    break;
                }
            }
            return ans;
        }
    if(s<n)
        return found(mid+1,r);
    else
        return found(l,mid-1);
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    int ans;
    for(int i=1;i<=t;i++)
    {
        cin>>b>>n;
        for(int j=1;j<=b;j++)
        {
            scanf("%d",&arr[j]);
        }
        if(n<=b)
            ans=n;
        else
            ans=found(0,1ll<<60);
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
