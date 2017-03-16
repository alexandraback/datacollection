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
#define mod 1000000007
#define inf 10000000
#include <cstdio>
#include <algorithm>

using namespace std;

ill powe(int aa,int b)
{
    ill ans=1;
    ill a=aa*1LL;
    while(b)
    {
        if(b&1)
            ans=(ans*1LL*a)%mod;
        a=(a*1LL*a)%mod;
        b=b/2;
    }
    return ans;
}
ill modinv(int a)
{
    return powe(a,mod-2);
}
#define eps 1e-12
#define gc getchar_unlocked


int gcd(int i,int j)
{
    if(j==0)
        return i;

    return gcd(j,i%j);
}
/*
#define MAX 100000001
int a[100000009]={0};
vector<int>v;
int sieve()
{
    int i,p,n;

    for(i=2;i<=MAX;i+=2)
        a[i]=2;
    for(i=3;i<=MAX;i+=3)
    {
       if(a[i]==0)
        a[i]=3;
       }
    for(i=5;i*i<=MAX;)
    {
        if(a[i]==0)
        {
            //v.pb(i);
            a[i]=i;
        }
        for(p=i*i;p<=MAX;p+=2*i)
        {
            if(a[p]==0)
            a[p]=i;
        }
        if(i%6==1)
            i+=4;
        else
            i+=2;
    }

    for(i=10000;i<=MAX;i++)
    {
       if(a[i]==0)
       {
           a[i]=i;
       }
    }
    return 0;
}
*/
/*
int m,n;
vector<int>v,vv;

int ctr,dp[108][3];

int rec(int pos,int gg,int fg)
{
    if(dp[pos][gg][fg]!=-1)
        return dp[pos][gg][fg];

    int ret=0;

    if(pos==v.size())
    {
        return 1;
    }

    if(!fg)
    {
        if(gg)
        {
            if(!v[pos]&&!vv[pos])
                ret=3*rec(pos+1,1,0);
            else if(!v[pos]&&vv[pos])
                ret=3*rec(pos+1,1,1);
            else if(v[pos]&&!vv[pos])
                ret=3*rec(pos+1,1,0);
            else
            {
                ret=3*rec(pos+1,1,1);
                ret+=rec(pos+1,1,0);
            }
        }
        else
        {
            if(!v[pos]&&!vv[pos])
                ret=rec(pos+1,0,0);
            else if(!v[pos]&&vv[pos])
                ret=rec(pos+1,0,1);
            else if(v[pos]&&!vv[pos])
            {
                ret=2*rec(pos+1,,0);
                ret+=rec(pos+1,,0);
            }
            else
            {
                ret=3*rec(pos+1,1);
                ret+=rec(pos+1,0);
            }
        }
        return dp[pos][fg]=ret;
    }
    if(v[pos])
    {
        ret=3*rec(pos+1,1);
        ret=rec(pos+1,1);
    }
    else
    {
        ret=
    }
    return dp[pos][fg]=ret;
}
*/

int main()
{
    int m,n,t,i,j,k,l;

    int ct=1;
    freopen("a.in","r",stdin);
    freopen("b.out","w",stdout);
cin(t);
    while(t--)
    {
        cin(n);
        string s[n+9];

        for(i=0;i<n;i++)
        cin>>s[i];
        vector<pair<int,int> >v[n+9];
cout<<"Case #"<<ct++<<": ";
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
        //cout<<v[0].size();
        if(!fg)
        {
            cout<<"Fegla Won\n";
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
        cout<<ans<<"\n";




    }
    return 0;
}
