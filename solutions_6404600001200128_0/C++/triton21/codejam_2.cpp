#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false) ;
    int t;
    cin>>t;
    for(int p=1; p<=t; p++)
    {
        int n;
        cin>>n;
        int data[10000] = {0} ;
        for(int i=0; i<n; i++)
        {
            cin>>data[i];
        }
        int ans1=0,ans=0, ha =0;

        for(int i=1; i<n; i++)
        {
            if(data[i]-data[i-1]<0)
            {
                ans1 = ans1 + (data[i-1]-data[i]);
            }
            ha =max(ha,data[i-1]-data[i]);
        }
        for(int i=0; i<n-1; i++)
        {
            if(data[i]>=ha)ans = ans + ha;
            else ans = ans  + data[i];
        }
        cout<<"Case #"<<p<<": "<<ans1<<" "<<ans<<"\n";
    }
    return 0;
}
