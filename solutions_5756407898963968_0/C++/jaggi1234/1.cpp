#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define iter(container,it) typeof(container.begin()) it
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(NULL)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h>
#endif
#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define iter(container,it) typeof(container.begin()) it
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(NULL)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h>
#endif
int main()
{
    int t,temp,i,j,tc=1,r;
    fastin;
    cin>>t;
    while(t--)
    {
        cin>>r;
        set<int> s;
        for(i=1; i<=4; i++)
        {
            for(j=1; j<=4; j++)
            {
                cin>>temp;
                if(i==r)
                {
                    s.insert(temp);
                }
            }
        }
        cin>>r;
        int count=0,ans=0;
        for(i=1; i<=4; i++)
        {
            for(j=1; j<=4; j++)
            {
                cin>>temp;
                if(i==r&&s.find(temp)!=s.end())
                {
                    count++;
                    ans=temp;
                }
            }
        }
        cout<<"Case #"<<tc++<<": ";
        if(count==0)
        {
            cout<<"Volunteer cheated!\n";
        }
        else if(count==1)
        {
            cout<<ans<<"\n";
        }
        else
        {
            cout<<"Bad magician!\n";
        }
    }
}
