#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<climits>
using namespace std;
#define FOR(i,n) for(i=0;i<n;i++)
#define sint(i) scanf("%d",&i)
#define ss(s) scanf("%s",s)
#define pii pair<int,int>
#define ll long long
#define MAX 1000000000
#define MOD 1000000007
int main()
{
     freopen("test.in", "r", stdin);
freopen("file.out", "w", stdout);
    int test;
    sint(test);
    int n,i;
    for(int t=1;t<=test;t++)
    {
        cout<<"Case #"<<t<<": ";
        sint(n);
        int a[n];
        FOR(i,n)
        {
            sint(a[i]);
        }
        int ans=0;
        int maxi=0;
        for(i=0;i<(n-1);i++)
        {
            if(a[i]>a[i+1])
            {
                ans=ans+a[i]-a[i+1];
                maxi=max(maxi,a[i]-a[i+1]);
            }
        }
        cout<<ans<<" ";
        ans=0;
        for(i=0;i<(n-1);i++)
        {
            if(a[i]>maxi)
            {
                ans=ans+maxi;
            }
            else
            ans=ans+a[i];
        }
        cout<<ans<<"\n";

    }
    return 0;
}
