//created by shikhar vishnoi

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <queue>
#include <string>
#include <string.h>
#include <math.h>
#define ll long long
#define pb push_back
#define iosync ios_base::sync_with_stdio(false);cin.tie(0);
const ll mod=1000000007;
const double pi=3.14159265358979323846;
using namespace std;

int main ()
{
    
    // freopen("input.txt", "r", stdin); 
    // freopen("output.txt", "w", stdout);
    iosync
    ll t;
    cin>>t;
    for (int T = 1; T <= t; ++T)
    {
        ll n,s;
        vector< pair <ll,ll> > p;
        cin>>n;
        for (int i = 0; i < n; ++i)
        {
            cin>>s;
            p.push_back(make_pair(s,i));
        }
        cout<<"Case #"<<T<<": ";
        sort(p.begin(),p.end());
        while(p[n-1].first>p[n-2].first)
        {
            cout<<char('A'+p[n-1].second)<<" ";
            p[n-1].first--;
        }
        for (int i = 0; i < n-2; ++i)
        {
            while(p[i].first)
            {
                cout<<char('A'+p[i].second)<<" ";
                p[i].first--;
            }
        }
        while(p[n-1].first)
        {
            cout<<char('A'+p[n-1].second)<<char('A'+p[n-2].second)<<" ";
            p[n-1].first--;
        }
        cout<<endl;
    }
    return 0;
}