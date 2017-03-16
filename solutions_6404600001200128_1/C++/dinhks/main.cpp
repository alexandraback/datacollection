#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
int a[200000];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,i,j,tt;
    cin>>t;
    for(tt=1;tt<=t;++tt)
    {
        cin>>n;
        for(j=0;j<n;++j)
            cin>>a[j];
        long long result1=0,result2=0;
        int ma=0;
        for(i=1;i<n;++i)
            if(a[i]<a[i-1])
            {
                result1+=-a[i]+a[i-1];
                if(a[i-1]-a[i]>ma)
                    ma=a[i-1]-a[i];
            }
        //cout<<ma<<endl;
        for(i=0;i<n-1;++i)
        {
            if(a[i]>=ma)
                result2+=ma;
            else
            {
                    result2+=a[i];
            }
        }

        cout<<"Case #"<<tt<<": "<<result1<<" "<<result2<<endl;
    }
    return 0;
}
