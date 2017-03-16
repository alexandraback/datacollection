#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <cstdio>
using namespace std;
int arr[1001];
int main()
{
    int s1,s2,s,x,t,n;
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        memset(arr,0,sizeof(arr));
        s1=s2=s=0;
        x=0;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&arr[j]);
            s+=arr[j];
            if(j>1)
            {
                s1+=max(0,arr[j-1]-arr[j]);
                x=max(x,arr[j-1]-arr[j]);
            }
        }
        for(int j=1;j<n;j++)
        {
            s2+=min(x,arr[j]);
        }
        printf("Case #%d: %d %d\n",i,s1,s2);
    }
    return 0;
}
