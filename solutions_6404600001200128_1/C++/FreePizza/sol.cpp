#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("output.out","w",stdout);
    long int t,i,n,ans,j,m;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>n;
        long int a[n];
        ans=0;
        for(j=0;j<n;j++)
            cin>>a[j];
        for(j=1;j<n;j++)
            if(a[j]<a[j-1])
                ans+=-(a[j]-a[j-1]);
        cout<<"Case #"<<i<<": "<<ans<<" ";
        m=0;
        ans=0;
        for(j=1;j<n;j++)
            if(a[j]<a[j-1])
                m=max(m,a[j-1]-a[j]);
        for(j=0;j<n-1;j++)
            ans+=min(a[j],m);
        cout<<ans<<"\n";
    }
    return 0;
}
