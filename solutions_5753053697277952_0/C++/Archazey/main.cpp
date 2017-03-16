#include<bits/stdc++.h>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
using namespace std;

const int NMAX=30;

int t,n,fr[NMAX];

int main()
{
    int i,k,sum,mx,cnt,nr;
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);
    cin.sync_with_stdio(false);
    cin>>t;
    for (k=1;k<=t;k++)
    {
        cin>>n;sum=0;
        for (i=1;i<=n;i++) cin>>fr[i],sum+=fr[i];
        cout<<"Case #"<<k<<": ";
        while (sum)
        {
            mx=0;
            for (i=1;i<=n;i++)
                mx=max(mx,fr[i]);
            cnt=0;
            for (i=1;i<=n;i++)
                if (fr[i]==mx)
                    cnt++;
            if (cnt&1) nr=1;
            else nr=2;
            sum-=nr;
            for (i=1;i<=n && nr;i++)
                if (fr[i]==mx)
                {
                    fr[i]--;
                    cout<<(char)(i+'A'-1);
                    nr--;
                }
            cout<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

