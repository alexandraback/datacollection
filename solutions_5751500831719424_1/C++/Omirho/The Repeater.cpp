#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,n,0)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORR(i,a,b) for(int i=a;i>=0;i--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define inf mod

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("a.in","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);
    int t,n;
    cin>>t;
    REP(i,t)
    {
        cout<<"Case #"<<i+1<<": ";
        cin>>n;
        string s[n];
        vector<pair<char,int> > v[n];
        int a[n][26],c=0;
        memset(a,0,sizeof a);
        REP(j,n)
            cin>>s[j];
        REP(j,n)
        {
            char ls = s[j][0];
            int temp=0;
            REP(k,s[j].length())
            {
                if(s[j][k]==ls)
                {
                    temp++;
                    if(k==s[j].length()-1)
                        v[j].pb(mp(s[j][k],temp));
                    continue;
                }
                else
                {
                    v[j].pb(mp(s[j][k-1],temp));
                    if(k==s[j].length()-1)
                        v[j].pb(mp(s[j][k],1));
                    ls=s[j][k];
                    temp=1;
                }
            }
        }
//        cout<<endl;
//        REP(j,n)
//        {
//            REP(k,v[j].size())
//                cout<<v[j][k].first<<","<<v[j][k].second<<' ';
//            cout<<endl;
//        }
        REP(j,n-1)
        {
            if(v[j].size()!=v[j+1].size())
            {
                c=1;
                break;
            }
        }
        int ans=0;
        if(!c)
        {
            REP(ww,v[0].size())
            {
                int ansmin = inf;
                REP(j,n)
                {
                    int temp=0;
                    REP(k,n)
                    {
                        if(v[j][ww].first!=v[k][ww].first)
                        {
                            c=1;
                            break;
                        }
                        temp+=abs(v[j][ww].second-v[k][ww].second);
                    }
                    if(c)
                        break;
                    ansmin=min(ansmin,temp);
                }
                if(c)
                    break;
                ans+=ansmin;
            }
            if(c)
            {
                cout<<"Fegla Won"<<endl;
            }
            else
            {
                cout<<ans<<endl;
            }
        }
        else
            cout<<"Fegla Won"<<endl;
    }
    return 0;
}
