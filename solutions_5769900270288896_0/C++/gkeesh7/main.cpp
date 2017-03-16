#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a)    for(int i = 0;i < a;i++)
#define REP(i,a,b)  for(int i = a;i < b;i++)
#define vi vector<int>

int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    int t;
    cin>>t;
    REP(a,1,t+1)
    {
        int n,r,c;
        cin>>r>>c>>n;
        int ans=INT_MAX;
        map<int,pair<int,int>>ma;
        int ctr=0;
        FOR(i,r)
        {
            FOR(j,c)
            {
                ma[ctr]={i,j};
                ctr++;
            }
        }
        vector<int>v;
        FOR(i,ctr)
        {
            v.push_back(i);
        }
        for(int i=0;i<(1<<(ctr));i++)
        {
            vector<pair<int,int> >vp1;
            for(int j=0;j<(ctr);j++)
            {
                if(i&(1<<j))
                {
                    vp1.push_back(ma[v[j]]);
                }
            }
            if(vp1.size()==n)
            {
                int ctr=0;
                FOR(k,n)
                {
                    REP(l,k+1,n)
                    {
                        if((abs(vp1[k].first-vp1[l].first))+(abs(vp1[k].second-vp1[l].second))==1)
                        {
                            ctr++;
                        }
                    }
                }
                ans=min(ctr,ans);
            }
        }
        cout<<"Case #"<<a<<": "<<ans<<endl;
    }
    return 0;
}
