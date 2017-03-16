#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<bitset>
#include<map>
#define test(t) while(t--)
#define cin(n) scanf("%d",&n)
#define cinl(n) scanf("%lld",&n)

#define cout(n) printf("%d\n",n)
#define rep(i,a,n) for(i=a;i<=n;i++)
#define vi vector<int>
#define vii vector< vector<int> >
#define vpii vector< pair<int,int> >
#define mii map<int,int>
#define eps 1e-12
#define pb push_back
#define mp make_pair
#define imax (int) 1000000007
#define ill long long
#define gc getchar_unlocked
#include<stack>
using namespace std;

int main()
{
    int m,n,t,i,j,k,l;
    cin>>t;
    int ct=1;
    while(t--)
    {
        cin>>n;
        string s[n+9];

        for(i=0;i<n;i++)
        cin>>s[i];
        vector<pair<int,int> >v[n+9];

        for(i=0;i<n;i++)
        {
            int count=0;
            int prev=-1;
            for(j=0;j<=s[i].length();j++)
            {
                if(j==s[i].length())
                  {
                  v[i].pb(mp(prev,count));
break;}
                int nn=s[i][j]-'a';
                if(!j)
                {
                    count++;
                    prev=nn;
                    continue;
                }
                if(nn!=prev)
                {
                   v[i].pb(mp(prev,count));
                    count=1;
                    prev=nn;
                }
                else
                    count++;
            }
        }
        vector<int>v1[v[0].size()+9];


        int fg=1;
        for(i=1;i<n;i++)
        {
                if(v[i].size()!=v[0].size())
                {
                    fg=0;
                    break;
                }
            for(j=0;j<v[i].size();j++)
            {
                if(v[i][j].first!=v[0][j].first)
                    fg=0;
            }
        }
     
        if(!fg)
        {
            cout<<"Case #"<<ct++<<": "<<"Fegla Won\n";
            continue;
        }

        for(i=0;i<n;i++)
        {
            for(j=0;j<v[0].size();j++)
            {
                v1[j].pb(v[i][j].second);
            }
        }
        int ans=0;
        //cout<<v[0].size()<<" ";
        for(i=0;i<v[0].size();i++)
        {
            sort(v1[i].begin(),v1[i].end());
            int med=v1[i][n/2];
            for(j=0;j<n;j++)
            {
                ans+=abs(med-v1[i][j]);
            }
        }
        cout<<"Case #"<<ct++<<": "<<ans<<"\n";




    }
    return 0;
}
