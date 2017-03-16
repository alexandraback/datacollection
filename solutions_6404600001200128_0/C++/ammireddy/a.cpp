#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
/*	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);*/

    int t;
    cin >> t;
    for(int tt=0;tt<t;tt++)
    {
        cout << "Case #" << (tt+1) << ": ";
        ll n;
        cin>>n;
        ll a[n];
        for(ll i=1;i<=n;i++)    cin>>a[i];
        ll res1=0;
        for(ll i=1;i<n;i++)
        {
            if(a[i]>a[i+1])
            {
                res1+=(a[i]-a[i+1]);
            }
        }
        cout<<res1<<" ";
        ll res2=0,max=INT_MIN;
        for(ll i=1;i<n;i++)
        {
            if(a[i]-a[i+1]>max)
            {
                max=a[i]-a[i+1];
            }
        }
        for(ll i=1;i<n;i++)
        {
            if(a[i]<=max)
                res2+=a[i];
            else
                res2+=(max);
        }
        cout<<res2<<endl;
    }
    return 0;
}
